//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void write_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Cannot add more than %d entries.\n", MAX_ENTRIES);
        exit(1);
    }

    strncpy(entries[num_entries].date, date, 20);
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_SIZE);

    num_entries++;
}

void read_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s:\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_SIZE];

    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter your entry:\n");
        fgets(entry, MAX_ENTRY_SIZE, stdin);
        entry[strcspn(entry, "\n")] = '\0';

        write_entry(date, entry);

        printf("Would you like to read your entries? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            read_entries();
        }
    }

    return 0;
}