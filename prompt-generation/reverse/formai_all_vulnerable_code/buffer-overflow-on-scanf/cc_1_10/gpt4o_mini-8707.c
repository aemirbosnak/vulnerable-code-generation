//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LOG_SIZE 1024
#define LOG_FILE "event_log.txt"

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

const char *logLevelStr[] = {
    "INFO",
    "WARNING",
    "ERROR"
};

void writeLog(LogLevel level, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", tm_now);

    fprintf(file, "[%s] [%s] %s\n", timeString, logLevelStr[level], message);
    fclose(file);
}

void simulateEvent(int eventType) {
    switch (eventType) {
        case 1:
            writeLog(INFO, "Simulation started successfully.");
            break;
        case 2:
            writeLog(WARNING, "Warning: Simulation approaching memory limit.");
            break;
        case 3:
            writeLog(ERROR, "Error: Simulation encountered an unrecoverable error.");
            break;
        default:
            writeLog(WARNING, "Unknown event type received.");
            break;
    }
}

void displayMenu() {
    printf("=== Event Logger Menu ===\n");
    printf("1. Start Simulation\n");
    printf("2. Memory Warning\n");
    printf("3. Error Occurred\n");
    printf("4. Exit\n");
    printf("=========================\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                simulateEvent(1);
                break;
            case 2:
                simulateEvent(2);
                break;
            case 3:
                simulateEvent(3);
                break;
            case 4:
                writeLog(INFO, "Exiting the event logger.");
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please select a valid option.\n");
                break;
        }

        // Induce a small delay to mimic processing time
        for (int i = 0; i < 5; i++) {
            printf(".");
            fflush(stdout);
            usleep(500000);  // 0.5 seconds delay
        }
        printf("\n");
    }
    
    return 0;
}