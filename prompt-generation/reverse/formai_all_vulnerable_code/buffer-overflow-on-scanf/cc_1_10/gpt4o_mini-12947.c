//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "eventlog.txt"
#define BUFFER_SIZE 256

void log_event(const char *event_type, const char *event_detail) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    time_t now;
    time(&now);
    struct tm *tm_info = localtime(&now);
    char time_buffer[30];
    
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    
    fprintf(log_file, "[%s] %s: %s\n", time_buffer, event_type, event_detail);
    fclose(log_file);
}

void print_menu() {
    printf("\nEvent Logger Menu:\n");
    printf("1. Log Info Event\n");
    printf("2. Log Warning Event\n");
    printf("3. Log Error Event\n");
    printf("4. Show Log Entries\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void show_logs() {
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    char buffer[BUFFER_SIZE];
    printf("\nLog Entries:\n");
    while (fgets(buffer, BUFFER_SIZE, log_file)) {
        printf("%s", buffer);
    }
    fclose(log_file);
}

int main() {
    int choice;
    char detail[BUFFER_SIZE];

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter info event detail: ");
                fgets(detail, BUFFER_SIZE, stdin);
                detail[strcspn(detail, "\n")] = 0; // Remove newline character
                log_event("INFO", detail);
                break;
            case 2:
                printf("Enter warning event detail: ");
                fgets(detail, BUFFER_SIZE, stdin);
                detail[strcspn(detail, "\n")] = 0; // Remove newline character
                log_event("WARNING", detail);
                break;
            case 3:
                printf("Enter error event detail: ");
                fgets(detail, BUFFER_SIZE, stdin);
                detail[strcspn(detail, "\n")] = 0; // Remove newline character
                log_event("ERROR", detail);
                break;
            case 4:
                show_logs();
                break;
            case 5:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}