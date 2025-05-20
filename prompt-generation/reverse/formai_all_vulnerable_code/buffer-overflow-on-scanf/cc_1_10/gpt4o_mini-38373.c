//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_LINE_LENGTH 256

typedef enum {
    INFO,
    WARNING,
    ERROR,
    DEBUG
} LogLevel;

void log_event(LogLevel level, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    
    char time_buffer[26];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);

    char *level_strings[] = {
        "INFO",
        "WARNING",
        "ERROR",
        "DEBUG"
    };

    fprintf(file, "[%s] [%s]: %s\n", time_buffer, level_strings[level], message);
    fclose(file);
}

void simulate_event(LogLevel level, const char *event_description) {
    log_event(level, event_description);
    printf("%s event logged: %s\n", level == INFO ? "Info" : level == WARNING ? "Warning" : level == ERROR ? "Error" : "Debug", event_description);
}

void display_log() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Unable to open log file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("\nEvent Log:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    int choice;
    
    printf("=== System Event Logger ===\n");
    printf("1. Log Info Event\n");
    printf("2. Log Warning Event\n");
    printf("3. Log Error Event\n");
    printf("4. Log Debug Event\n");
    printf("5. Display Log\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nChoose an option: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter Info message: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
                simulate_event(INFO, buffer);
                break;
            case 2:
                printf("Enter Warning message: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
                simulate_event(WARNING, buffer);
                break;
            case 3:
                printf("Enter Error message: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
                simulate_event(ERROR, buffer);
                break;
            case 4:
                printf("Enter Debug message: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
                simulate_event(DEBUG, buffer);
                break;
            case 5:
                display_log();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}