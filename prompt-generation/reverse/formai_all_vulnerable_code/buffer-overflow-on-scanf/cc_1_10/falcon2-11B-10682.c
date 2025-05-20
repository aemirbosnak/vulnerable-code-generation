//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_MESSAGES 10
#define MAX_WORDS 50

typedef struct {
    char* message;
    int sender;
    int receiver;
    int length;
} Message;

typedef struct {
    pthread_t thread;
    int id;
    Message message;
} Thread;

void* thread_function(void* arg) {
    Thread* thread = (Thread*) arg;
    Message* message = &thread->message;

    if (message->sender == thread->id) {
        printf("%d: %s\n", message->sender, message->message);
        free(message->message);
        free(message);
    } else {
        printf("%d: %s\n", message->receiver, message->message);
        free(message->message);
        free(message);
    }

    return NULL;
}

void send_message(char* message, int sender, int receiver) {
    Message* new_message = (Message*) malloc(sizeof(Message));
    new_message->message = strdup(message);
    new_message->sender = sender;
    new_message->receiver = receiver;
    new_message->length = strlen(message);

    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, (void*) new_message);
    pthread_join(thread, NULL);

    free(new_message);
}

int main() {
    int threads[MAX_THREADS];
    int num_threads = 0;

    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    printf("Welcome to the Space Adventure!\n");
    printf("Enter the number of threads you want to use: ");
    int num_threads_input = scanf("%d", &num_threads);

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*) &(Thread){.id = i});
    }

    int num_messages = 0;
    char message[MAX_WORDS];

    while (1) {
        printf("Enter your message (or 'exit' to quit): ");
        scanf("%s", message);

        if (strcmp(message, "exit") == 0) {
            break;
        }

        pthread_mutex_lock(&mutex);

        for (int i = 0; i < num_threads; i++) {
            Thread* thread = &threads[i];
            Message* message = &thread->message;

            if (message->sender == thread->id && message->receiver == i) {
                send_message(message->message, thread->id, i);
                break;
            }
        }

        pthread_mutex_unlock(&mutex);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}