//FormAI DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Log {
    char date[20];
    char time[20];
    char ipAddress[20];
    char request[200];
    int responseCode;
    int responseTime;
};

int main() {
    char fileName[50];
    printf("Enter the name of the log file: ");
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Failed to open file %s. Please check if the file exists.", fileName);
        return -1;
    }

    struct Log logs[100];
    int numLogs = 0;

    char line[300];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *tok = strtok(line, " ");
        int i = 0;
        while (tok != NULL) {
            if (i == 3) {
                strcpy(logs[numLogs].date, tok);
            }
            else if (i == 4) {
                strcpy(logs[numLogs].time, tok);
            }
            else if (i == 6) {
                strcpy(logs[numLogs].ipAddress, tok);
            }
            else if (i == 7) {
                strcat(logs[numLogs].request, tok);
                strcat(logs[numLogs].request, " ");
            }
            else if (i == 8) {
                strcat(logs[numLogs].request, tok);
            }
            else if (i == 10) {
                logs[numLogs].responseCode = atoi(tok);
            }
            else if (i == 11) {
                logs[numLogs].responseTime = atoi(tok);
            }

            tok = strtok(NULL, " ");
            i++;
        }

        numLogs++;
    }

    fclose(fp);

    printf("Log file analysis complete. Found %d logs.\n\n", numLogs);

    printf("Top 5 most common IP addresses:\n");
    char uniqueAddresses[100][20] = {""};
    int addressCounts[100] = {0};
    int numUniqueAddresses = 0;

    for (int i = 0; i < numLogs; i++) {
        char *address = logs[i].ipAddress;
        int found = 0;
        for (int j = 0; j < numUniqueAddresses; j++) {
            if (strcmp(address, uniqueAddresses[j]) == 0) {
                found = 1;
                addressCounts[j]++;
                break;
            }
        }

        if (!found) {
            strcpy(uniqueAddresses[numUniqueAddresses], address);
            addressCounts[numUniqueAddresses] = 1;
            numUniqueAddresses++;
        }
    }

    for (int i = 0; i < 5; i++) {
        int maxCount = 0;
        int maxIndex = 0;
        for (int j = 0; j < numUniqueAddresses; j++) {
            if (addressCounts[j] > maxCount) {
                maxCount = addressCounts[j];
                maxIndex = j;
            }
        }

        printf("%s - %d times\n", uniqueAddresses[maxIndex], addressCounts[maxIndex]);
        addressCounts[maxIndex] = 0;
    }

    printf("\nRequests by response code:\n");
    int responseCodeCounts[6] = {0};

    for (int i = 0; i < numLogs; i++) {
        int code = logs[i].responseCode / 100;
        responseCodeCounts[code]++;
    }

    for (int i = 1; i < 6; i++) {
        printf("%dxx - %d requests\n", i, responseCodeCounts[i]);
    }

    return 0;
}