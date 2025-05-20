//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;
char *username = NULL;

void init() {
    printf("Welcome to Digital Diary!\n");
    printf("Please enter your name: ");
    scanf("%s", username);
    printf("Hello, %s!\n", username);
}

void add_entry() {
    printf("Enter your entry:\n");
    char entry[MAX_ENTRY_LENGTH];
    fgets(entry, MAX_ENTRY_LENGTH, stdin);
    entry[strcspn(entry, "\n")] = '\0'; // remove newline character
    strcpy(entries[num_entries].entry, entry);
    time_t now = time(NULL);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    num_entries++;
}

void view_entries() {
    printf("Your entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter a keyword to search: ");
    scanf("%s", keyword);
    bool found = false;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
            found = true;
        }
    }
    if (!found) {
        printf("No entries found.\n");
    }
}

int main() {
    init();
    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                printf("Goodbye, %s!\n", username);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}