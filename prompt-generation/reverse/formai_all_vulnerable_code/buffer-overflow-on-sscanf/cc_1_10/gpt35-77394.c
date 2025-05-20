//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define TIME_DIFFERENCE 5 //change this to set the time difference threshold

typedef struct {
    char ip_address[16];
    char timestamp[20];
} Log;

void readLog(Log logs[], int* num_logs) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    file = fopen("logs.txt", "r");
    if (file == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, file)) != -1) {
        sscanf(line, "%s %s", logs[i].ip_address, logs[i].timestamp);
        i++;
    }
    *num_logs = i;

    fclose(file);
    if (line)
        free(line);
}

int checkLogs(Log logs[], int num_logs, char* ip_address) {
    int count = 0;
    int last_index = 0;
    for(int i=0; i<num_logs; i++) {
        if(strcmp(logs[i].ip_address, ip_address) == 0) {
            if(count == 0) {
                last_index = i;
            } else if(i - last_index < TIME_DIFFERENCE) {
                return 1;
            }
            count++;
        }
    }
    return 0;
}

int main() {
    Log logs[MAX_LENGTH];
    int num_logs = 0;
    readLog(logs, &num_logs);

    char ip_address[16];
    printf("Enter IP address: ");
    scanf("%s", ip_address);

    int found = checkLogs(logs, num_logs, ip_address);
    if(found) {
        printf("Intrusion detected!\n");
    } else {
        printf("No intrusion detected.\n");
    }

    return 0;
}