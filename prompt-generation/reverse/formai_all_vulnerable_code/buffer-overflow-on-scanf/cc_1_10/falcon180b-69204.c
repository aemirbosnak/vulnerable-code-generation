//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    strncpy(entries[num_entries].date, date, 20);
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_LENGTH);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Digital Diary 2100!\n");
    printf("Please enter your name:\n");
    char name[50];
    scanf("%s", name);

    printf("Hello, %s! What would you like to do?\n", name);
    printf("1. Add an entry\n");
    printf("2. View entries\n");
    printf("3. Exit\n");

    int choice;
    while (true) {
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the date (YYYY-MM-DD): ");
                char date[20];
                scanf("%s", date);
                printf("Enter your entry:\n");
                char entry[MAX_ENTRY_LENGTH];
                scanf("%[^\n]", entry);
                add_entry(date, entry);
                printf("Entry added!\n");
                break;
            case 2:
                print_entries();
                break;
            case 3:
                printf("Goodbye, %s!\n", name);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}