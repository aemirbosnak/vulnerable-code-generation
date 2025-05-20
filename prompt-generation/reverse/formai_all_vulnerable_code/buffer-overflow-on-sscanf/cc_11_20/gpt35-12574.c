//FormAI DATASET v1.0 Category: Log analysis ; Style: irregular
#include<stdio.h>

// Defining a structure to hold log information
struct Log {
    char timestamp[50];
    char origin[20];
    char severity[10];
    char message[200];
};

int main() {
    // Reading log file
    FILE *fptr;
    fptr = fopen("sample.log", "r");

    // Checking if log file exists or not
    if (fptr == NULL) {
        printf("Log file does not exists or unable to open\n");
        return 0;
    }

    // Reading logs line by line
    int count = 0;
    struct Log logs[100];
    char line[400];
    while (fgets(line, sizeof(line), fptr)) {
        // Parsing log line into different fields
        sscanf(line, "%[^,], %[^,], %[^,], %[^\n]", logs[count].timestamp, logs[count].origin, logs[count].severity, logs[count].message);
        count++;
    }

    // Closing log file
    fclose(fptr);

    // Displaying logs based on severity level
    printf("\n*****Displaying logs based on severity level*****\n");
    printf("\nSeverity Level: INFO\n");
    printf("\n%-25s%-15s%s\n", "Timestamp", "Origin", "Message");
    for (int i = 0; i < count; i++) {
        if (strcmp(logs[i].severity, "INFO") == 0) {
            printf("%-25s%-15s%s\n", logs[i].timestamp, logs[i].origin, logs[i].message);
        }
    }
    printf("\nSeverity Level: WARNING\n");
    printf("\n%-25s%-15s%s\n", "Timestamp", "Origin", "Message");
    for (int i = 0; i < count; i++) {
        if (strcmp(logs[i].severity, "WARNING") == 0) {
            printf("%-25s%-15s%s\n", logs[i].timestamp, logs[i].origin, logs[i].message);
        }
    }
    printf("\nSeverity Level: ERROR\n");
    printf("\n%-25s%-15s%s\n", "Timestamp", "Origin", "Message");
    for (int i = 0; i < count; i++) {
        if (strcmp(logs[i].severity, "ERROR") == 0) {
            printf("%-25s%-15s%s\n", logs[i].timestamp, logs[i].origin, logs[i].message);
        }
    }

    // Displaying logs from a specific origin
    printf("\n*****Displaying logs from a specific origin*****\n");
    char origin[20];
    printf("\nEnter origin name: ");
    scanf("%s", origin);
    printf("\n%-25s%-15s%-10s%s\n", "Timestamp", "Origin", "Severity", "Message");
    for (int i = 0; i < count; i++) {
        if (strcmp(logs[i].origin, origin) == 0) {
            printf("%-25s%-15s%-10s%s\n", logs[i].timestamp, logs[i].origin, logs[i].severity, logs[i].message);
        }
    }

    return 0;
}