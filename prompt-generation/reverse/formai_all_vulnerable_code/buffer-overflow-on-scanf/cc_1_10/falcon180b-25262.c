//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary full!\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void view_entries(void) {
    int i;

    printf("Viewing diary entries...\n");

    for (i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

void delete_entry(char* date) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            strcpy(entries[i].date, "");
            strcpy(entries[i].entry, "");

            num_entries--;

            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    char choice;

    do {
        printf("Digital Diary\n");
        printf("A - Add entry\n");
        printf("V - View entries\n");
        printf("D - Delete entry\n");
        printf("Q - Quit\n");
        printf("> ");

        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter date (YYYY-MM-DD): ");
                scanf(" %s", entries[num_entries].date);

                printf("Enter entry: ");
                scanf(" %[^\n]", entries[num_entries].entry);

                add_entry(entries[num_entries].date, entries[num_entries].entry);
                break;

            case 'V':
                view_entries();
                break;

            case 'D':
                printf("Enter date of entry to delete (YYYY-MM-DD): ");
                scanf(" %s", entries[num_entries].date);

                delete_entry(entries[num_entries].date);
                break;

            case 'Q':
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 'Q');

    return 0;
}