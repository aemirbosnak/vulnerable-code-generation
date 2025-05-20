//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE "intrusion_log.txt"

typedef struct {
    char timestamp[20];
    char event[256];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

void log_event(const char *event) {
    if (logCount < MAX_LOG_ENTRIES) {
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);
        strftime(logEntries[logCount].timestamp, 20, "%Y-%m-%d %H:%M:%S", tm_info);
        strncpy(logEntries[logCount].event, event, 255);
        logEntries[logCount].event[255] = '\0'; // Ensure null termination
        logCount++;
    } else {
        printf("Log is full!\n");
    }
}

void save_log_to_file() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        perror("Unable to open log file");
        return;
    }
    for (int i = 0; i < logCount; i++) {
        fprintf(file, "[%s] %s\n", logEntries[i].timestamp, logEntries[i].event);
    }
    fclose(file);
}

void monitor_file(const char *filepath) {
    struct stat fileStat;
    time_t lastModTime = 0;

    while (1) {
        if (stat(filepath, &fileStat) == -1) {
            perror("Error getting file stats");
            break;
        }

        if (lastModTime != fileStat.st_mtime) {
            lastModTime = fileStat.st_mtime;
            char event[256];
            snprintf(event, sizeof(event), "File %s was modified.", filepath);
            log_event(event);
        }

        sleep(5); // Sleep for 5 seconds before checking again
    }
}

void display_logs() {
    printf("\n*** Intrusion Log ***\n");
    for (int i = 0; i < logCount; i++) {
        printf("[%s] %s\n", logEntries[i].timestamp, logEntries[i].event);
    }
}

int main() {
    printf("=== Artistic Intrusion Detection System ===\n");

    const char *watchedFile = "sensitive_file.txt";
    
    // Start monitoring the file in the background using fork
    if (fork() == 0) {
        monitor_file(watchedFile);
        exit(0);
    }

    char command[10];
    while (1) {
        printf("\nEnter 'show' to display logs, 'save' to save logs to file, or 'exit' to quit:\n");
        scanf("%s", command);

        if (strcmp(command, "show") == 0) {
            display_logs();
        } else if (strcmp(command, "save") == 0) {
            save_log_to_file();
            printf("Logs saved to %s\n", LOG_FILE);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Unknown command!\n");
        }
    }

    return 0;
}