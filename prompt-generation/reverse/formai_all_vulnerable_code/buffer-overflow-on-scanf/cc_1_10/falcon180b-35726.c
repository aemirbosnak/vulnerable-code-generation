//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void print_entries() {
    printf("Digital Diary Entries:\n");
    printf("-----------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Digital Diary\n");
        printf("------------\n");
        printf("1. Add entry\n");
        printf("2. Print entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter your entry: ");
                scanf("%s", entry);

                add_entry(date, entry);
                break;

            case 2:
                print_entries();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}