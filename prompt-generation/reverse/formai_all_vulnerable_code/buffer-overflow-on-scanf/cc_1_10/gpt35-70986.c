//FormAI DATASET v1.0 Category: System event logger ; Style: secure
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

// Define a struct to hold event logs
struct event_log {
    time_t timestamp;
    char message[1000];
} event_logs[1000];

// Initialize log count to 0
int log_count = 0;

// Function to add log to event_logs array
void add_log(char message[1000]) {
    // Get current timestamp
    time_t current_time;
    time(&current_time);

    // Add log to event_logs array
    event_logs[log_count].timestamp = current_time;
    strcpy(event_logs[log_count].message, message);

    // Increment log count
    log_count++;
}

// Function to save event_logs to file
void save_logs() {
    // Open file for writing
    FILE *file_ptr;
    file_ptr = fopen("event_logs.txt", "w");

    // Write logs to file
    for (int i = 0; i < log_count; i++) {
        fprintf(file_ptr, "%s - %s", asctime(localtime(&event_logs[i].timestamp)), event_logs[i].message);
    }

    // Close file
    fclose(file_ptr);
}

// Main function to execute program
int main() {
    printf("Welcome to the event logger program!\n");

    int choice;
    char message[1000];

    while (1) {
        printf("\n1. Add log\n2. View logs\n3. Save logs\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter message: ");
                scanf(" %[^\n]s", message);
                add_log(message);
                printf("Log added!\n");
                break;
            case 2:
                printf("\nLogs:\n");
                for (int i = 0; i < log_count; i++) {
                    printf("%s - %s", asctime(localtime(&event_logs[i].timestamp)), event_logs[i].message);
                }
                break;
            case 3:
                printf("\nSaving logs...\n");
                save_logs();
                printf("Logs saved to event_logs.txt!\n");
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}