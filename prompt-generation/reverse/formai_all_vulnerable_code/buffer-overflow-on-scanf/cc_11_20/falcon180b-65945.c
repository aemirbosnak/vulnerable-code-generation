//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1024

typedef struct {
    char date[10];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[20];
    char choice;
    time_t current_time;

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter a filename for your diary (without extension): ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    diary = fopen(filename, "a");

    if (diary == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (1) {
        printf("\n");
        printf("1. Write a new entry\n");
        printf("2. Read entries\n");
        printf("3. Search for an entry\n");
        printf("4. Save and exit\n");
        printf("5. Exit without saving\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            if (num_entries >= MAX_ENTRIES) {
                printf("Error: maximum number of entries reached.\n");
                break;
            }
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", entries[num_entries].date);
            printf("Enter your entry:\n");
            fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
            num_entries++;
            break;

        case '2':
            printf("\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s - %s\n", entries[i].date, entries[i].entry);
            }
            break;

        case '3':
            printf("\n");
            printf("Enter keyword to search: ");
            char keyword[MAX_ENTRY_LENGTH];
            fgets(keyword, MAX_ENTRY_LENGTH, stdin);
            for (int i = 0; i < num_entries; i++) {
                if (strstr(entries[i].entry, keyword)!= NULL) {
                    printf("%s - %s\n", entries[i].date, entries[i].entry);
                }
            }
            break;

        case '4':
            fclose(diary);
            printf("Your diary has been saved.\n");
            exit(0);

        case '5':
            printf("Your diary has not been saved.\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}