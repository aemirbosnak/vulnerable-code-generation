//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    int numEntries = 0;
    DiaryEntry diary[MAX_ENTRIES];
    char title[MAX_ENTRY_LENGTH];
    char entry[MAX_ENTRY_LENGTH];
    char choice;
    time_t now;

    printf("Welcome to your digital diary!\n\n");
    printf("Please enter a title for your diary: ");
    scanf("%s", title);
    printf("\nTitle set to %s\n\n", title);

    while (1) {
        printf("Select an option:\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("\nWrite a new entry:\n");
            printf("Date (YYYY-MM-DD): ");
            scanf("%s", diary[numEntries].date);
            printf("Entry: ");
            scanf("%[^\n]", diary[numEntries].entry);
            numEntries++;
            break;

        case '2':
            printf("\nPrevious entries:\n");
            for (int i = 0; i < numEntries; i++) {
                printf("%s - %s\n", diary[i].date, diary[i].entry);
            }
            break;

        case '3':
            printf("\nExiting...\n");
            exit(0);

        default:
            printf("\nInvalid option. Try again.\n");
        }
    }

    return 0;
}