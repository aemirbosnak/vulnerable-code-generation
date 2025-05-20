//FormAI DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>

int main() {
    printf("Welcome to the tavern! Let's have a look at the logs for the past week.\n");
    printf("--------------------------------------------------------\n");

    int totalEntries = 0;
    int successfulEntries = 0;
    int failedEntries = 0;
    int criticalEntries = 0;
    float successRate;
    char date[20];
    char message[100];

    while(1) {
        printf("Enter the date of the entry (dd/mm/yyyy), or \"exit\" to quit: ");
        scanf("%s", date);

        if(strcmp(date, "exit") == 0) {
            break;
        }

        printf("Enter the message of the entry: ");
        scanf("%s", message);

        totalEntries++;

        if(strstr(message, "arrived at the castle") != NULL) {
            successfulEntries++;
        } else if(strstr(message, "stopped by the goblins") != NULL) {
            failedEntries++;
        } else if(strstr(message, "dragon attack!") != NULL) {
            criticalEntries++;
        }

        printf("\n");
    }

    printf("--------------------------------------------------------\n");
    printf("Total entries: %d\n", totalEntries);
    printf("Successful entries: %d\n", successfulEntries);
    printf("Failed entries: %d\n", failedEntries);
    printf("Critical entries: %d\n", criticalEntries);

    if(totalEntries == 0) {
        successRate = 0;
    } else {
        successRate = (float)successfulEntries / (float)totalEntries * 100;
    }

    printf("Success rate: %.2f%%\n", successRate);

    return 0;
}