//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define EVENT_LOG_BUFFER_SIZE 1024
#define EVENT_LOG_DB_CONNECT_TIMEOUT 5000
#define EVENT_LOG_DB_WRITE_TIMEOUT 10000

struct event_log {
    char *buffer;
    size_t capacity;
    size_t size;
};

int main(int argc, char **argv) {
    struct event_log *log;
    int sock;
    struct sockaddr_in server_addr;
    socklen_t server_len = sizeof(server_addr);
    int ret;

    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    log = calloc(1, sizeof(struct event_log));
    if (!log) {
        perror("calloc");
        return 1;
    }

    log->buffer = calloc(1, EVENT_LOG_BUFFER_SIZE);
    if (!log->buffer) {
        perror("calloc");
        free(log);
        return 1;
    }

    log->capacity = EVENT_LOG_BUFFER_SIZE;
    log->size = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        free(log->buffer);
        free(log);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server_addr, server_len);
    if (ret < 0) {
        perror("connect");
        close(sock);
        free(log->buffer);
        free(log);
        return 1;
    }

    while (1) {
        char *message = NULL;
        size_t message_len = 0;

        // wait for a message to arrive
        ret = recv(sock, &message, 1, 0);
        if (ret <= 0) {
            if (ret < 0) {
                perror("recv");
            }
            break;
        }

        message_len = strlen(message);
        if (log->size + message_len >= log->capacity) {
            log->capacity *= 2;
            log->buffer = realloc(log->buffer, log->capacity);
            if (!log->buffer) {
                perror("realloc");
                break;
            }
        }

        // append the message to the log buffer
        strcat(log->buffer, message);
        log->size += message_len;

        // send the log buffer to the distributed database
        ret = send(sock, log->buffer, log->size, 0);
        if (ret < 0) {
            perror("send");
            break;
        }

        // sleep for a bit before sending the next message
        usleep(100000);
    }

    close(sock);
    free(log->buffer);
    free(log);

    return 0;
}