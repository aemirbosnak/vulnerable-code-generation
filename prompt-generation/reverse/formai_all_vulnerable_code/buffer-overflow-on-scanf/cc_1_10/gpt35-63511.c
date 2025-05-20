//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000

/* Structure to store log information */
typedef struct log {
    char type[10];
    char message[100];
} Log;

/* Array to store logs */
Log logs[MAX_LOG_SIZE];

/* Function to check for suspicious patterns */
int checkPattern(char *str) {
    char pattern1[] = "password";
    char pattern2[] = "admin";
    char pattern3[] = "root";

    if (strstr(str, pattern1) != NULL || strstr(str, pattern2) != NULL || strstr(str, pattern3) != NULL)
        return 1;

    return 0;
}

/* Function to log messages */
void logMessage(char *type, char *message) {
    int i;

    for (i = 0; i < MAX_LOG_SIZE; i++) {
        if (strlen(logs[i].message) == 0) {
            strcpy(logs[i].type, type);
            strcpy(logs[i].message, message);
            return;
        }
    }
}

/* Function to print logs */
void printLogs() {
    int i;

    for (i = 0; i < MAX_LOG_SIZE; i++) {
        if (strlen(logs[i].message) != 0) {
            printf("[%s] %s\n", logs[i].type, logs[i].message);
        }
    }
}

/* Main function */
int main() {
    char input[100];
    int successCount = 0;
    int failedCount = 0;

    printf("Welcome to the Intrusion Detection System. Type 'exit' to quit.\n");

    /* Loop until 'exit' is entered */
    while (1) {
        printf("> ");
        scanf("%s", input);

        /* Check for suspicious patterns in input */
        if (checkPattern(input)) {
            logMessage("Alert", input);
            printf("Suspicious pattern detected!\n");
            failedCount++;
        } else {
            printf("Command executed successfully.\n");
            successCount++;
        }

        /* Check if 'exit' is entered */
        if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    printf("Number of successful commands: %d\n", successCount);
    printf("Number of failed commands: %d\n", failedCount);
    printf("Log Messages:\n");
    printLogs();

    return 0;
}