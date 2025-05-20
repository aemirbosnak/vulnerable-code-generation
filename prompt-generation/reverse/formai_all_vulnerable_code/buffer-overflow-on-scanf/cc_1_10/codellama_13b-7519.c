//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: standalone
/*
 * Digital Diary Example Program
 *
 * This program is a simple digital diary that allows the user to input
 * text entries, which are stored in a file. The program also allows the
 * user to view, search, and delete entries.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 100

typedef struct {
    char date[11];
    char time[9];
    char text[MAX_LENGTH];
} Entry;

void add_entry(Entry *entries, int *num_entries);
void view_entry(Entry *entries, int num_entries);
void search_entry(Entry *entries, int num_entries);
void delete_entry(Entry *entries, int *num_entries);

int main(void) {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    // Main menu
    char choice;
    do {
        printf("Enter your choice:\n");
        printf("(A)dd an entry\n");
        printf("(V)iew an entry\n");
        printf("(S)earch for an entry\n");
        printf("(D)elete an entry\n");
        printf("(Q)uit\n");
        scanf(" %c", &choice);

        switch (choice) {
        case 'A':
        case 'a':
            add_entry(entries, &num_entries);
            break;
        case 'V':
        case 'v':
            view_entry(entries, num_entries);
            break;
        case 'S':
        case 's':
            search_entry(entries, num_entries);
            break;
        case 'D':
        case 'd':
            delete_entry(entries, &num_entries);
            break;
        case 'Q':
        case 'q':
            return 0;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}

void add_entry(Entry *entries, int *num_entries) {
    if (*num_entries == MAX_ENTRIES) {
        printf("Sorry, the diary is full.\n");
        return;
    }

    // Get the date and time
    char date[11], time[9];
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%10s", date);
    printf("Enter the time (HH:MM): ");
    scanf("%8s", time);

    // Get the text
    printf("Enter the text: ");
    fgets(entries[*num_entries].text, MAX_LENGTH, stdin);

    // Save the entry
    strcpy(entries[*num_entries].date, date);
    strcpy(entries[*num_entries].time, time);
    (*num_entries)++;

    printf("Entry added.\n");
}

void view_entry(Entry *entries, int num_entries) {
    if (num_entries == 0) {
        printf("The diary is empty.\n");
        return;
    }

    // Display the entries
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n", entries[i].date, entries[i].time);
        printf("%s\n\n", entries[i].text);
    }
}

void search_entry(Entry *entries, int num_entries) {
    if (num_entries == 0) {
        printf("The diary is empty.\n");
        return;
    }

    // Get the search criteria
    char search[MAX_LENGTH];
    printf("Enter the search text: ");
    fgets(search, MAX_LENGTH, stdin);

    // Search for the entry
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].text, search)) {
            printf("%s %s\n", entries[i].date, entries[i].time);
            printf("%s\n\n", entries[i].text);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(Entry *entries, int *num_entries) {
    if (*num_entries == 0) {
        printf("The diary is empty.\n");
        return;
    }

    // Get the entry to delete
    char date[11], time[9];
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%10s", date);
    printf("Enter the time (HH:MM): ");
    scanf("%8s", time);

    // Find the entry
    for (int i = 0; i < *num_entries; i++) {
        if (strcmp(entries[i].date, date) == 0 && strcmp(entries[i].time, time) == 0) {
            // Delete the entry
            for (int j = i; j < *num_entries - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*num_entries)--;
            return;
        }
    }

    printf("Entry not found.\n");
}