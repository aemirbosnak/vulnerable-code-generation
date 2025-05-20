//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[20];

    strftime(date, 20, "%Y-%m-%d", t);

    diary = fopen("diary.txt", "r");

    if (diary == NULL) {
        printf("Diary file not found. Creating new diary file...\n");
        diary = fopen("diary.txt", "w");
    } else {
        printf("Diary file found.\n");
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("--------------------\n");
        printf("1. Write new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter your entry for %s:\n", date);
            scanf("%[^\n]", entries[num_entries].entry);
            strcpy(entries[num_entries].date, date);
            num_entries++;
            break;

        case '2':
            if (num_entries == 0) {
                printf("No previous entries found.\n");
            } else {
                printf("\nPrevious entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s - %s\n", entries[i].date, entries[i].entry);
                }
            }
            break;

        case '3':
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}