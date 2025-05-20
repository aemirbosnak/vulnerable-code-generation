//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char *date;
    char *title;
    char *entry;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *title, char *entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    entries[num_entries].date = strdup(date);
    entries[num_entries].title = strdup(title);
    entries[num_entries].entry = strdup(entry);

    num_entries++;
}

void print_entry(int index) {
    printf("%s - %s\n%s\n", entries[index].date, entries[index].title, entries[index].entry);
}

void print_entries() {
    printf("Digital Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        print_entry(i);
    }
}

int main() {
    srand(time(NULL));
    char date[20];
    char title[100];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter title: ");
        scanf("%s", title);

        printf("Enter your entry:\n");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        entry[strcspn(entry, "\n")] = '\0';

        add_entry(date, title, entry);

        printf("Entry added successfully.\n");

        char choice;
        printf("Do you want to add another entry? (y/n): ");
        scanf(" %c", &choice);

        if (tolower(choice) == 'n') {
            break;
        }
    }

    printf("Your entries:\n");
    print_entries();

    return 0;
}