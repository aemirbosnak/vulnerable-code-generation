//FormAI DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* message) {
    time_t raw_time;
    struct tm* time_info;
    char time_string[80];

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(time_string, 80, "%Y-%m-%d %H:%M:%S", time_info);

    printf("%s: %s\n", time_string, message);
}

int main() {
    int input;

    printf("Welcome to the futuristic System Event Logger.\n");

    do {
        printf("\nWhat event would you like to log?\n");
        printf("1. Login attempt\n");
        printf("2. File deletion\n");
        printf("3. System shutdown\n");
        printf("4. Exit program\n");

        scanf("%d", &input);

        switch (input) {
            case 1:
                log_event("Login failed: Invalid username");
                break;
            case 2:
                log_event("File deleted: Confidential documents");
                break;
            case 3:
                log_event("System shutdown initiated");
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (input != 4);

    return 0;
}