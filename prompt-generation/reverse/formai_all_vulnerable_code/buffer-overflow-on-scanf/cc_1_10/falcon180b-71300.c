//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    printf("Digital Diary Entries:\n");
    printf("======================\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    char date[20];

    printf("Welcome to the Digital Diary!\n");
    while (1) {
        printf("\nEnter a date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter your entry for this date:\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        add_entry(date, input);
        print_entries();
    }

    return 0;
}