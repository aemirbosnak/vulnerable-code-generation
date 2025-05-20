//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    char search_date[20];
    int search_result;

    file = fopen("diary.txt", "r");

    if (file == NULL) {
        printf("Diary file not found. Creating a new one.\n");
        file = fopen("diary.txt", "w");
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", entries[num_entries].date);
            printf("Enter your entry:\n");
            fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
            num_entries++;
            break;

        case '2':
            printf("\nDate\tEntry\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s\t%s\n", entries[i].date, entries[i].entry);
            }
            break;

        case '3':
            printf("Enter the date to search (YYYY-MM-DD): ");
            scanf("%s", search_date);
            search_result = search_entry(entries, num_entries, search_date);

            if (search_result == -1) {
                printf("No entries found for the given date.\n");
            } else {
                printf("\nEntry for %s:\n%s\n", search_date, entries[search_result].entry);
            }
            break;

        case '4':
            fclose(file);
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

int search_entry(Entry entries[], int num_entries, char date[]) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            return i;
        }
    }

    return -1;
}