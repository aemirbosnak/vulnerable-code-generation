//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 5000
#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void add_entry(Entry entries[], int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void print_entries(Entry entries[], int num_entries) {
    printf("Entries:\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];

    char username[50];
    printf("Enter your name: ");
    scanf("%s", username);

    printf("Welcome to your digital diary, %s!\n", username);

    while (1) {
        char choice;
        printf("What would you like to do? (a)dd an entry, (r)ead entries, or (q)uit? ");
        scanf("%c", &choice);

        if (choice == 'a' || choice == 'A') {
            char date[20];
            time_t now = time(NULL);
            strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));

            char entry[MAX_ENTRY_LENGTH];
            printf("Enter your entry for %s:\n", date);
            fgets(entry, MAX_ENTRY_LENGTH, stdin);

            entry[strcspn(entry, "\n")] = '\0';

            add_entry(entries, num_entries, date, entry);
            printf("Entry added successfully!\n");

            num_entries++;
        } else if (choice == 'r' || choice == 'R') {
            print_entries(entries, num_entries);
        } else if (choice == 'q' || choice == 'Q') {
            printf("Goodbye, %s!\n", username);
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}