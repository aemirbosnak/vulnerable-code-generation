//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
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
    char choice;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    diary = fopen("diary.txt", "a");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("Welcome to your digital diary!\n");
        printf("Please choose an option:\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter the date (YYYY-MM-DD): ");
            scanf(" %s", date);

            printf("Enter your entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);

            strcat(entry, "\n");
            strcat(entry, date);
            strcat(entry, "\n");

            fprintf(diary, "%s", entry);
            printf("Entry saved.\n");
            break;

        case '2':
            rewind(diary);

            while (fgets(entry, MAX_ENTRY_LENGTH, diary)!= NULL) {
                printf("%s", entry);
            }

            break;

        case '3':
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    fclose(diary);
    return 0;
}