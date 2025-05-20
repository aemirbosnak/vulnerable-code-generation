//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void add_entry(char *date, char *entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    printf("Digital Diary\n\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

void search_entry(char *keyword) {
    int found = 0;
    char search_date[20];
    strcpy(search_date, entries[0].date);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].entry, keyword) == 0) {
            found = 1;
            printf("%s\n%s\n", entries[i].date, entries[i].entry);
        }
    }
    if (!found) {
        printf("No entries found.\n");
    }
}

void delete_entry(char *date) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(Entry) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
}

int main() {
    char choice;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("\nDigital Diary\n");
        printf("A - Add entry\n");
        printf("S - Search entry\n");
        printf("D - Delete entry\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter your entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0';
                add_entry(date, entry);
                break;
            case 'S':
                printf("Enter keyword to search: ");
                scanf("%s", entry);
                search_entry(entry);
                break;
            case 'D':
                printf("Enter date of entry to delete: ");
                scanf("%s", date);
                delete_entry(date);
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}