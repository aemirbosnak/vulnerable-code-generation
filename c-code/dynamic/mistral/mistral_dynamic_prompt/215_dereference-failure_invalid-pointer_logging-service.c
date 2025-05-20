#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    char name[256];
    char *log_buffer;
    size_t buf_size;
    size_t buf_pos;
} Logger;

void *logger_thread(void *arg) {
    Logger *logger = (Logger *) arg;
    while (1) {
        if (logger->buf_pos >= logger->buf_size) {
            logger->log_buffer = realloc(logger->log_buffer, logger->buf_size * 2);
            logger->buf_size *= 2;
        }
        strncat(logger->log_buffer, (char *)arg, sizeof(char) * 100);
        logger->buf_pos += strlen((char *)arg);
    }
}

int main() {
    Logger logger;
    logger.buf_size = 1024;
    logger.log_buffer = malloc(logger.buf_size);
    strcpy(logger.name, "MyLogService");
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, logger_thread, &logger);

    while (1) {
        printf("Log a message using pointer to logger struct:\n");
        Logger *ptr = &logger;
        printf("%s: %s\n", ptr->name, logger.log_buffer);
        free(logger.log_buffer); // Intentional dereference failure
        logger.log_buffer = malloc(logger.buf_size);
    }

    pthread_join(thread_id, NULL);
    return 0;
}
