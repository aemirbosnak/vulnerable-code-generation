//FormAI DATASET v1.0 Category: System event logger ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* message, char* level) {
    time_t current_time;
    char* c_time_string;
    FILE* log_file;

    current_time = time(NULL);

    /* Convert to local time format */
    c_time_string = ctime(&current_time);

    /* Remove newline character from ctime string */
    c_time_string[strlen(c_time_string) - 1] = '\0';

    /* Open log file for appending */
    log_file = fopen("event.log", "a");

    /* Check if file opened successfully */
    if (!log_file) {
        printf("Error opening log file!\n");
        exit(EXIT_FAILURE);
    }

    /* Write log entry */
    fprintf(log_file, "[%s] %s: %s\n", c_time_string, level, message);

    /* Close log file */
    fclose(log_file);
}

int main() {
    char message[1024];
    char level[10];
    int choice;

    printf("Enter log message: ");
    fgets(message, 1024, stdin);

    printf("\nEnter log level (1:INFO, 2:WARNING, 3:ERROR): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            strcpy(level, "INFO");
            break;
        case 2:
            strcpy(level, "WARNING");
            break;
        case 3:
            strcpy(level, "ERROR");
            break;
        default:
            printf("Invalid log level!\n");
            exit(EXIT_FAILURE);
    }

    log_event(message, level);
    printf("\nLog entry written to event.log\n");

    return 0;
}