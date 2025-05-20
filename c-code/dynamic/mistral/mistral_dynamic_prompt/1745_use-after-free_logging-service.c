#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LOG_SIZE 1024
#define LOG_FILE "log.txt"

typedef struct Logger {
    FILE *file;
    char buffer[MAX_LOG_SIZE];
} Logger;

void init_logger(Logger *logger) {
    logger->file = fopen(LOG_FILE, "a");
    if (!logger->file) {
        perror("Error opening log file");
        exit(1);
    }
}

void log(Logger *logger, const char *message) {
    strcpy(logger->buffer, message);
    fprintf(logger->file, "%s\n", logger->buffer);
    memset(logger->buffer, 0, MAX_LOG_SIZE);
}

void destroy_logger(Logger *logger) {
    fclose(logger->file);
    free(logger);
}

int main() {
    Logger *logger = malloc(sizeof(Logger));
    init_logger(logger);

    char *dynamic_log_buffer = malloc(MAX_LOG_SIZE);
    for (int i = 0; i < 10; ++i) {
        snprintf(dynamic_log_buffer, MAX_LOG_SIZE, "Log message %d\n", i);
        log(logger, dynamic_log_buffer);
    }

    // Use dynamic_log_buffer after freeing the memory associated with it.

    destroy_logger(logger);
    free(dynamic_log_buffer);

    return 0;
}
