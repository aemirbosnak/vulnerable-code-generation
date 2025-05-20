//FormAI DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct log_entry {
    char date[20];
    char time[20];
    char process[20];
    char message[256];
};

int main() {
    struct log_entry logs[1000];
    int num_entries = 0;
    char filename[50];
    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    char buffer[300];
    while (fgets(buffer, 300, fp)) {
        char *token = strtok(buffer, ",");
        strcpy(logs[num_entries].date, token);

        token = strtok(NULL, ",");
        strcpy(logs[num_entries].time, token);

        token = strtok(NULL, ",");
        strcpy(logs[num_entries].process, token);

        token = strtok(NULL, ",");
        strcpy(logs[num_entries].message, token);

        num_entries++;
    }

    fclose(fp);

    // Count the number of logs for each process
    int num_processes = 0;
    char processes[100][20];
    int counts[100] = {0};
    for (int i = 0; i < num_entries; i++) {
        int found = 0;
        for (int j = 0; j < num_processes; j++) {
            if (strcmp(logs[i].process, processes[j]) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(processes[num_processes], logs[i].process);
            counts[num_processes] = 1;
            num_processes++;
        }
    }

    // Print the results
    printf("Process log analysis:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s: %d\n", processes[i], counts[i]);
    }

    return 0;
}