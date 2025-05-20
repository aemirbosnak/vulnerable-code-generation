//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

struct log_entry {
    char source_ip[16];
    char date_time[20];
    char action[5];
    char target_ip[16];
};

int main() {
    FILE *log_file = fopen("log_file.txt", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log_file.txt\n");
        exit(1);
    }

    char input[MAX_INPUT_SIZE];
    struct log_entry entry;
    int anomaly_count = 0;
    printf("**** Intrusion Detection System ****\n");
    printf("Checking log file...\n");

    while (fgets(input, MAX_INPUT_SIZE, log_file) != NULL) {
        sscanf(input, "%s %s %s %s", entry.source_ip, entry.date_time, entry.action, entry.target_ip);

        // Check action and target IP
        if ((strcmp(entry.action, "DENY") == 0 || strcmp(entry.action, "BLOCK") == 0) &&
            (strcmp(entry.target_ip, "192.168.1.1") == 0 || strcmp(entry.target_ip, "10.0.1.4") == 0)) {
            printf("Possible intrusion detected: %s %s %s %s\n", entry.source_ip, entry.date_time, entry.action, entry.target_ip);
            anomaly_count++;
        }
    }

    fclose(log_file);

    if (anomaly_count > 0) {
        printf("Warning: %d possible intrusions detected.\n", anomaly_count);
        printf("Do you want to take action? (y/n) ");
        char response;
        scanf("%c", &response);
        if (response == 'y' || response == 'Y') {
            // TODO: Implement action to block IPs
            printf("IPs blocked.\n");
        } else {
            printf("No action taken.\n");
        }
    } else {
        printf("No intrusions detected.\n");
    }

    return 0;
}