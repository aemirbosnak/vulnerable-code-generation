//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* date;
    char* event;
    char* emotion;
} Entry;

int main() {
    Entry curEntry;
    int numEntries = 0;
    char option = '0';
    char* tempStr;

    printf("Welcome to your digital diary!\n\n");

    while (option != '3') {
        printf("What would you like to do?\n");
        printf("1. Create new entry\n");
        printf("2. View previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                printf("\nCreating new entry...\n");
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%ms", &tempStr);
                curEntry.date = malloc(strlen(tempStr) + 1);
                strcpy(curEntry.date, tempStr);
                free(tempStr);

                printf("Enter event: ");
                scanf("%ms", &tempStr);
                curEntry.event = malloc(strlen(tempStr) + 1);
                strcpy(curEntry.event, tempStr);
                free(tempStr);

                printf("Enter feeling: ");
                scanf("%ms", &tempStr);
                curEntry.emotion = malloc(strlen(tempStr) + 1);
                strcpy(curEntry.emotion, tempStr);
                free(tempStr);

                numEntries++;
                printf("\nEntry created!\n\n");
                break;

            case '2':
                if (numEntries == 0) {
                    printf("\nNo entries yet.\n\n");
                } else {
                    for (int i = 0; i < numEntries; i++) {
                        printf("\nEntry #%d:\n", i + 1);
                        printf("Date: %s\n", curEntry.date);
                        printf("Event: %s\n", curEntry.event);
                        printf("Feeling: %s\n\n", curEntry.emotion);
                    }
                }
                break;

            case '3':
                printf("\nExiting digital diary...\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}