//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

void add_entry(diary_entry* entries, int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries(diary_entry* entries, int num_entries) {
    printf("Date\tEntry\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char input[100];
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to your Digital Diary!\n");
    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        scanf("%s", date);
        printf("Enter your entry:\n");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
        strcpy(entry, input);
        add_entry(entries, num_entries, date, entry);
        num_entries++;
        printf("\nEntry added successfully!\n");
    }

    return 0;
}