//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define EVENT_MAX_LEN 1024
#define EVENT_BUFFER_SIZE 1024
#define EVENT_QUEUE_SIZE 1024

typedef struct {
    char *event;
    int len;
} event_t;

typedef struct {
    pthread_mutex_t lock;
    event_t events[EVENT_QUEUE_SIZE];
    int head;
    int tail;
} event_queue_t;

void *log_worker(void *arg) {
    event_queue_t *queue = arg;

    while (1) {
        pthread_mutex_lock(&queue->lock);
        while (queue->head == queue->tail) {
            pthread_mutex_unlock(&queue->lock);
            usleep(100000); // wait for 1 second
        }

        event_t *event = &queue->events[queue->tail];
        queue->tail++;

        // log the event
        syslog(LOG_NOTICE, "%s", event->event);

        pthread_mutex_unlock(&queue->lock);
    }

    return NULL;
}

int main() {
    event_queue_t queue;

    pthread_mutex_init(&queue.lock, NULL);

    // create a listener socket
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };
    bind(listener, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(listener, 5);

    // create log worker threads
    for (int i = 0; i < 5; i++) {
        pthread_t thread;
        log_worker((void *)&queue);
    }

    // loop until exit
    while (1) {
        // wait for a connection
        socklen_t client_len = sizeof(struct sockaddr_in);
        int client = accept(listener, (struct sockaddr *)&server_addr, &client_len);

        // read the event from the client
        char buffer[EVENT_MAX_LEN];
        read(client, buffer, EVENT_MAX_LEN);

        // add the event to the queue
        pthread_mutex_lock(&queue.lock);
        queue.events[queue.head] = (event_t) {
            .event = buffer,
            .len = strlen(buffer)
        };
        queue.head++;
        pthread_mutex_unlock(&queue.lock);

        // log the event
        syslog(LOG_NOTICE, "%s", buffer);
    }

    return 0;
}