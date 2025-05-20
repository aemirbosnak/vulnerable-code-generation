//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#define LOG_FILE "intrusion_log.txt"
#define MAX_LOG_ENTRIES 100
#define THRESHOLD 5

typedef struct {
    char timestamp[20];
    char action[256];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;
pthread_mutex_t logMutex;

void writeLog(const char *action) {
    pthread_mutex_lock(&logMutex);
    if (logCount < MAX_LOG_ENTRIES) {
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);
        strftime(logEntries[logCount].timestamp, 20, "%Y-%m-%d %H:%M:%S", tm_info);
        strncpy(logEntries[logCount].action, action, 256);
        logCount++;
    } else {
        printf("Log entries exceeded max limit.\n");
    }
    pthread_mutex_unlock(&logMutex);
}

void saveLogToFile() {
    pthread_mutex_lock(&logMutex);
    FILE *file = fopen(LOG_FILE, "a");
    if (file) {
        for (int i = 0; i < logCount; i++) {
            fprintf(file, "[%s] %s\n", logEntries[i].timestamp, logEntries[i].action);
        }
        fclose(file);
        logCount = 0; // Clear log after saving
    } else {
        perror("Unable to open log file");
    }
    pthread_mutex_unlock(&logMutex);
}

void *logSaver(void *arg) {
    while (1) {
        sleep(10); // Save logs every 10 seconds
        saveLogToFile();
    }
    return NULL;
}

void simulateIntrusion(int attempts) {
    if (attempts > THRESHOLD) {
        writeLog("Intrusion detected! Multiple failed login attempts.");
        printf("Alert: Intrusion detected! Actions logged.\n");
    } else {
        writeLog("User login attempt successful.");
    }
}

void printLogs() {
    printf("Current Log Entries:\n");
    pthread_mutex_lock(&logMutex);
    for (int i = 0; i < logCount; i++) {
        printf("[%s] %s\n", logEntries[i].timestamp, logEntries[i].action);
    }
    pthread_mutex_unlock(&logMutex);
}

int main() {
    pthread_t logThread;
    pthread_mutex_init(&logMutex, NULL);
    pthread_create(&logThread, NULL, logSaver, NULL);

    int attempts;
    char choice;

    while (1) {
        printf("Enter number of failed login attempts (0 to exit): ");
        scanf("%d", &attempts);
        if (attempts == 0) {
            printf("Exiting the Intrusion Detection System.\n");
            break;
        }
        simulateIntrusion(attempts);
        printLogs();
    }

    // Ensure all logs are saved before exit
    saveLogToFile();
    pthread_mutex_destroy(&logMutex);
    pthread_cancel(logThread);
    return 0;
}