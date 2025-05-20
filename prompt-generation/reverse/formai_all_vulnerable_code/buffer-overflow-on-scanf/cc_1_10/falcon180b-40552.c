//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[100];
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n2. View entries\n3. Exit\n");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", date);

            printf("Enter your entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            entry[strcspn(entry, "\n")] = '\0';

            add_entry(date, entry);
            printf("Entry added successfully!\n");
        } else if (strcmp(input, "2") == 0) {
            print_entries();
        } else if (strcmp(input, "3") == 0) {
            printf("Goodbye!");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}