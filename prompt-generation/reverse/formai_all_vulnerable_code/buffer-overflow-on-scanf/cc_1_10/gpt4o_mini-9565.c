//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_LOG_MESSAGE_LENGTH 256
#define MAX_LOG_ENTRIES 100

typedef struct {
    char message[MAX_LOG_MESSAGE_LENGTH];
    time_t timestamp;
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;
pthread_mutex_t logMutex;

void initializeLogger() {
    pthread_mutex_init(&logMutex, NULL);
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void logEvent(const char *eventMessage) {
    pthread_mutex_lock(&logMutex);
    if (logCount >= MAX_LOG_ENTRIES) {
        printf("Log limit reached. Please clear the log.\n");
    } else {
        time(&logEntries[logCount].timestamp);
        strncpy(logEntries[logCount].message, eventMessage, MAX_LOG_MESSAGE_LENGTH - 1);
        logEntries[logCount].message[MAX_LOG_MESSAGE_LENGTH - 1] = '\0';
        logCount++;
        
        FILE *file = fopen(LOG_FILE, "a");
        if (file != NULL) {
            fprintf(file, "%s: %s\n", ctime(&logEntries[logCount - 1].timestamp), logEntries[logCount - 1].message);
            fclose(file);
        }
    }
    pthread_mutex_unlock(&logMutex);
}

void clearLog() {
    pthread_mutex_lock(&logMutex);
    logCount = 0;
    FILE *file = fopen(LOG_FILE, "w");
    if (file != NULL) {
        fprintf(file, "Log cleared at %s\n", ctime(&(time_t){time(NULL)}));
        fclose(file);
    }
    pthread_mutex_unlock(&logMutex);
}

void displayLog() {
    pthread_mutex_lock(&logMutex);
    for (int i = 0; i < logCount; i++) {
        printf("%s: %s\n", ctime(&logEntries[i].timestamp), logEntries[i].message);
    }
    pthread_mutex_unlock(&logMutex);
}

void *simulateEventGeneration(void *arg) {
    for (int i = 0; i < 10; i++) {
        char eventMessage[MAX_LOG_MESSAGE_LENGTH];
        snprintf(eventMessage, MAX_LOG_MESSAGE_LENGTH, "Generated event %d", i + 1);
        logEvent(eventMessage);
        sleep(1);
    }
    return NULL;
}

int main() {
    initializeLogger();

    pthread_t eventThread;
    if (pthread_create(&eventThread, NULL, simulateEventGeneration, NULL) != 0) {
        perror("Failed to create event generation thread");
        return EXIT_FAILURE;
    }

    char command[10];
    while (1) {
        printf("Enter command (log/display/clear/exit): ");
        scanf("%s", command);
        if (strcmp(command, "log") == 0) {
            char msg[MAX_LOG_MESSAGE_LENGTH];
            printf("Enter message to log: ");
            getchar(); // to consume newline character
            fgets(msg, sizeof(msg), stdin);
            msg[strcspn(msg, "\n")] = 0; // remove newline character
            logEvent(msg);
        } else if (strcmp(command, "display") == 0) {
            displayLog();
        } else if (strcmp(command, "clear") == 0) {
            clearLog();
            printf("Log has been cleared.\n");
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }

    pthread_join(eventThread, NULL);
    pthread_mutex_destroy(&logMutex);
    return EXIT_SUCCESS;
}