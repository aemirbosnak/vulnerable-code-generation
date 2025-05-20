//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define LOG_FILE "event_log.txt"
#define MAX_LOG_SIZE 1024
#define NUM_THREADS 2

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

typedef struct {
    LogLevel level;
    char message[MAX_LOG_SIZE];
} LogEvent;

pthread_mutex_t log_mutex;

void log_event(LogEvent event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open log file for writing\n");
        return;
    }
    pthread_mutex_lock(&log_mutex);

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_buffer[20];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", t);

    const char *level_strings[] = { "INFO", "WARNING", "ERROR" };
    fprintf(file, "[%s] [%s] %s\n", time_buffer, level_strings[event.level], event.message);

    pthread_mutex_unlock(&log_mutex);
    fclose(file);
}

void *event_generator(void *arg) {
    const char *messages[] = {
        "System boot successful",
        "User logged in",
        "File created: test.txt",
        "File deleted: old_report.pdf",
        "Connection established to database",
        "Error reading file: permissions denied",
        "Warning: Low disk space",
        "User logged out"
    };
    
    for (int i = 0; i < 10; i++) {
        LogEvent event;
        event.level = rand() % 3; // Randomly assign a log level
        strncpy(event.message, messages[rand() % (sizeof(messages) / sizeof(messages[0]))], MAX_LOG_SIZE);
        log_event(event);
        sleep(1); // Sleep for a second before generating the next event
    }
    return NULL;
}

void configure_logging_level() {
    int level;
    printf("Choose logging level: 0-INFO, 1-WARNING, 2-ERROR\n");
    scanf("%d", &level);

    if (level < 0 || level > 2) {
        fprintf(stderr, "Invalid logging level. Defaulting to INFO.\n");
        level = 0;
    }
    LogLevel log_level = (LogLevel)level;

    // Here you can implement conditional logging based on log_level
    // For now, we will just demo the setup.
    printf("Logging configured to level: %d\n", log_level);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&log_mutex, NULL);
    
    configure_logging_level();
    
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, event_generator, NULL);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&log_mutex);
    printf("Logging complete. Check %s for logged events.\n", LOG_FILE);
    return 0;
}