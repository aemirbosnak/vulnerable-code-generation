//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_SIZE 256

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

pthread_mutex_t log_mutex;

void initialize_logging() {
    pthread_mutex_init(&log_mutex, NULL);
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void log_event(LogLevel level, const char *message) {
    pthread_mutex_lock(&log_mutex);

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file for writing");
        pthread_mutex_unlock(&log_mutex);
        return;
    }

    char *level_str;
    switch (level) {
        case INFO: level_str = "INFO"; break;
        case WARNING: level_str = "WARNING"; break;
        case ERROR: level_str = "ERROR"; break;
    }

    fprintf(file, "[%02d-%02d-%04d %02d:%02d:%02d] [%s] %s\n",
            local->tm_mday, local->tm_mon + 1, local->tm_year + 1900,
            local->tm_hour, local->tm_min, local->tm_sec, level_str, message);

    fclose(file);
    pthread_mutex_unlock(&log_mutex);
}

void *event_generator(void *arg) {
    char *messages[] = {
        "System initialized",
        "User logged in",
        "File opened for reading",
        "Data processed successfully",
        "Disk space running low",
        "Network connection lost",
        "Critical error: unable to save file"
    };

    for (int i = 0; i < 10; i++) {
        int event_index = rand() % 7;
        LogLevel level;
        if (event_index < 3) {
            level = INFO;
        } else if (event_index < 6) {
            level = WARNING;
        } else {
            level = ERROR;
        }

        log_event(level, messages[event_index]);
        sleep(1); // Simulate time between events
    }

    return NULL;
}

int main(void) {
    srand(time(NULL));
    initialize_logging();

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, event_generator, NULL);
    pthread_create(&thread2, NULL, event_generator, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&log_mutex);
    
    printf("Event logging finished. Check %s for logs.\n", LOG_FILE);
    return 0;
}