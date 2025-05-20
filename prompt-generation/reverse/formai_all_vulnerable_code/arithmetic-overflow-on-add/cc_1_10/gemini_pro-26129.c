//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LOG_SIZE (1024 * 1024)
#define MAX_LOG_ENTRIES 100

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL
} log_level_t;

typedef struct {
    log_level_t level;
    time_t timestamp;
    char *message;
} log_entry_t;

typedef struct {
    int fd;
    size_t size;
    log_entry_t *entries;
} log_t;

log_t *log_open(const char *path) {
    log_t *log = malloc(sizeof(log_t));
    if (log == NULL) {
        return NULL;
    }

    log->fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (log->fd == -1) {
        free(log);
        return NULL;
    }

    log->size = 0;
    log->entries = NULL;

    return log;
}

void log_close(log_t *log) {
    if (log == NULL) {
        return;
    }

    if (log->entries != NULL) {
        free(log->entries);
    }

    close(log->fd);
    free(log);
}

int log_write(log_t *log, log_level_t level, const char *format, ...) {
    if (log == NULL) {
        return -1;
    }

    if (log->size >= MAX_LOG_ENTRIES) {
        return -1;
    }

    va_list args;
    va_start(args, format);
    size_t message_size = vsnprintf(NULL, 0, format, args) + 1;
    va_end(args);

    char *message = malloc(message_size);
    if (message == NULL) {
        return -1;
    }

    va_start(args, format);
    vsnprintf(message, message_size, format, args);
    va_end(args);

    log_entry_t *entry = &log->entries[log->size++];
    entry->level = level;
    entry->timestamp = time(NULL);
    entry->message = message;

    return 0;
}

int log_flush(log_t *log) {
    if (log == NULL) {
        return -1;
    }

    for (size_t i = 0; i < log->size; i++) {
        log_entry_t *entry = &log->entries[i];
        char timestamp[32];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&entry->timestamp));

        char level[8];
        switch (entry->level) {
            case LOG_LEVEL_DEBUG:
                strcpy(level, "DEBUG");
                break;
            case LOG_LEVEL_INFO:
                strcpy(level, "INFO");
                break;
            case LOG_LEVEL_WARNING:
                strcpy(level, "WARNING");
                break;
            case LOG_LEVEL_ERROR:
                strcpy(level, "ERROR");
                break;
            case LOG_LEVEL_FATAL:
                strcpy(level, "FATAL");
                break;
        }

        char message[MAX_LOG_SIZE];
        snprintf(message, sizeof(message), "%s %s %s\n", level, timestamp, entry->message);

        if (write(log->fd, message, strlen(message)) == -1) {
            return -1;
        }

        free(entry->message);
    }

    log->size = 0;

    return 0;
}

int main(int argc, char **argv) {
    log_t *log = log_open("log.txt");
    if (log == NULL) {
        perror("log_open");
        return EXIT_FAILURE;
    }

    log_write(log, LOG_LEVEL_INFO, "Program started");
    log_write(log, LOG_LEVEL_DEBUG, "Variable value: %d", 42);
    log_write(log, LOG_LEVEL_WARNING, "Potential problem detected");
    log_write(log, LOG_LEVEL_ERROR, "Error occurred");
    log_write(log, LOG_LEVEL_FATAL, "Fatal error");

    log_flush(log);

    log_close(log);

    return EXIT_SUCCESS;
}