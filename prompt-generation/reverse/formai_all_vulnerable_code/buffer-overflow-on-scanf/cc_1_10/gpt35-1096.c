//FormAI DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRY_SIZE 256
#define MAX_ENTRIES 100

struct diary_entry {
    char date[11];
    char time[6];
    char entry[MAX_ENTRY_SIZE];
};

void print_entry(struct diary_entry entry);
void add_entry(struct diary_entry *entries, int *num_entries, char *date, char *time, char *new_entry);
void view_entries(struct diary_entry *entries, int num_entries);
void view_entries_by_date(struct diary_entry *entries, int num_entries, char *date);
void delete_entry_by_index(struct diary_entry *entries, int *num_entries, int index_to_delete);

int main() {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char choice = ' ';
    char date[11];
    char time[6];
    char new_entry[MAX_ENTRY_SIZE];

    time_t now;
    struct tm *tm_info;

    while (choice != 'q') {
        printf("Welcome to thy mighty digital diary!\n");
        printf("Choose an option from the following:\n");
        printf("a - add a new entry\n");
        printf("v - view all entries\n");
        printf("d - view entries for a specific date\n");
        printf("r - remove an entry by index\n");
        printf("q - quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter the date of thy entry in format MM/DD/YYYY: ");
                scanf(" %s", date);
                printf("Enter the time of thy entry in format HH:MM: ");
                scanf(" %s", time);
                printf("Enter thy entry: ");
                scanf(" %[^\n]s", new_entry);
                add_entry(entries, &num_entries, date, time, new_entry);
                break;
            case 'v':
                view_entries(entries, num_entries);
                break;
            case 'd':
                printf("Enter the date to view in format MM/DD/YYYY: ");
                scanf(" %s", date);
                view_entries_by_date(entries, num_entries, date);
                break;
            case 'r':
                printf("Enter the index of the entry to delete: ");
                int index_to_delete;
                scanf("%d", &index_to_delete);
                delete_entry_by_index(entries, &num_entries, index_to_delete);
                break;
            case 'q':
                printf("Farewell, friend!");
                break;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    }

    return 0;
}

void print_entry(struct diary_entry entry) {
    printf("%s %s - %s\n", entry.date, entry.time, entry.entry);
}

void add_entry(struct diary_entry *entries, int *num_entries, char *date, char *time, char *new_entry) {
    // make sure there is room in the array
    if (*num_entries >= MAX_ENTRIES) {
        printf("Maximum capacity reached for your digital diary! Remove some entries to add more.\n");
        return;
    }

    // create new entry
    struct diary_entry new;
    strcpy(new.date, date);
    strcpy(new.time, time);
    strcpy(new.entry, new_entry);

    // add new entry to diary array
    entries[*num_entries] = new;
    *num_entries += 1;

    printf("Entry added to thy digital diary!\n");
}

void view_entries(struct diary_entry *entries, int num_entries) {
    // make sure there are entries to view
    if (num_entries == 0) {
        printf("No entries to display in thy digital diary.\n");
        return;
    }

    printf("Listing all entries in thy digital diary:\n");
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
    }
}

void view_entries_by_date(struct diary_entry *entries, int num_entries, char *date) {
    // make sure there are entries to view
    if (num_entries == 0) {
        printf("No entries to display in thy digital diary.\n");
        return;
    }

    printf("Listing entries in thy digital diary for the date %s:\n", date);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            print_entry(entries[i]);
        }
    }
}

void delete_entry_by_index(struct diary_entry *entries, int *num_entries, int index_to_delete) {
    // make sure index is within range
    if (index_to_delete < 0 || index_to_delete >= *num_entries) {
        printf("Invalid index entered.\n");
        return;
    }

    // delete entry by shifting all entries after it over by one
    for (int i = index_to_delete; i < *num_entries - 1; i++) {
        entries[i] = entries[i+1];
    }

    *num_entries -= 1;
    printf("Entry at index %d has been removed from thy digital diary.\n", index_to_delete);
}