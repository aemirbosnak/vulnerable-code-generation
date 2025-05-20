//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[20];
    char choice;
    int index;

    printf("Welcome to the Digital Diary!\n\n");
    printf("Please enter a filename for your diary (without extension): ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    diary = fopen(filename, "a");

    if (diary == NULL) {
        printf("Error opening file. Exiting program.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("\nWrite an Entry:\n");
            printf("Date (YYYY-MM-DD): ");
            scanf("%s", entries[num_entries].date);
            printf("Entry:\n");
            fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
            num_entries++;
            break;

        case '2':
            printf("\nRead Entries:\n");
            for (index = 0; index < num_entries; index++) {
                printf("%s - %s\n", entries[index].date, entries[index].entry);
            }
            break;

        case '3':
            printf("\nSearch Entries:\n");
            printf("Keyword: ");
            scanf("%s", entries[num_entries].entry);
            num_entries++;
            break;

        case '4':
            printf("\nExiting program...\n");
            fclose(diary);
            exit(0);

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}