//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
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
} entry_t;

void add_entry(entry_t *diary, int num_entries, char *date, char *entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full, cannot add new entry.\n");
        return;
    }

    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);

    num_entries++;
}

void view_entry(entry_t *diary, int num_entries, char *date) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("Entry for %s:\n%s\n", date, diary[i].entry);
            return;
        }
    }

    printf("No entry found for %s.\n", date);
}

void view_all_entries(entry_t *diary, int num_entries) {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("Entry for %s:\n%s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    entry_t diary[MAX_ENTRIES];
    int num_entries = 0;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    char choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n2. View entry\n3. View all entries\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter date (dd/mm/yyyy): ");
            scanf("%s", date);
            printf("Enter entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            entry[strcspn(entry, "\n")] = '\0';
            add_entry(diary, num_entries, date, entry);
            break;

        case '2':
            printf("Enter date to view entry: ");
            scanf("%s", date);
            view_entry(diary, num_entries, date);
            break;

        case '3':
            view_all_entries(diary, num_entries);
            break;

        case '4':
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}