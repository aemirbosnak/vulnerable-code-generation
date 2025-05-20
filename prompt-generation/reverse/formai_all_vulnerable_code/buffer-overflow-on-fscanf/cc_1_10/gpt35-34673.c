//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000

struct LogInfo {
    char id[20];
    char time[20];
    char action[10];
    char result[20];
};

int checkSuspiciousActivity(struct LogInfo logs[], int numLogs) {
    int count = 0;

    for (int i = 0; i < numLogs; i++) {
        if (strcmp(logs[i].action, "login") == 0 && strcmp(logs[i].result, "failed") == 0) {
            count++;
            if (count >= 3) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    struct LogInfo logs[MAX_LOG_SIZE];
    int numLogs = 0;

    FILE *fp = fopen("log.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (numLogs < MAX_LOG_SIZE && fscanf(fp, "%s %s %s %s", logs[numLogs].id, logs[numLogs].time, logs[numLogs].action, logs[numLogs].result) == 4) {
        numLogs++;
    }

    fclose(fp);

    if (checkSuspiciousActivity(logs, numLogs)) {
        printf("Possible intrusion detected.\n");
    } else {
        printf("No suspicious activity detected.\n");
    }

    return 0;
}