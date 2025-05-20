//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500
#define DATE_FORMAT "%Y-%m-%d"
#define TIME_FORMAT "%H:%M:%S"

typedef struct {
    char date[11];
    char time[9];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    char filename[20];
    int i, j, choice, num_entries;
    time_t now;
    struct tm *tm_now;
    Entry entries[MAX_ENTRIES];

    printf("Welcome to your digital diary!\n");
    printf("Please enter your name: ");
    scanf("%s", entries[0].entry);

    strcpy(entries[0].date, asctime(localtime(&now)));
    strcpy(entries[0].time, asctime(localtime(&now)));
    num_entries = 1;

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Sorry, you can only have %d entries.\n", MAX_ENTRIES);
                break;
            }

            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", entries[num_entries].date);

            printf("Enter the time (HH:MM:SS): ");
            scanf("%s", entries[num_entries].time);

            printf("Enter your entry: ");
            scanf("%[^\n]", entries[num_entries].entry);
            entries[num_entries].entry[strcspn(entries[num_entries].entry, "\n")] = '\0';
            num_entries++;
            break;

        case 2:
            printf("\nPrevious entries:\n");
            for (i = 0; i < num_entries; i++) {
                printf("%s - %s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
            }
            break;

        case 3:
            printf("Goodbye, %s!\n", entries[0].entry);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}