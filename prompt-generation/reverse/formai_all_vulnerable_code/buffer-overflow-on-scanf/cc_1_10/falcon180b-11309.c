//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries == MAX_ENTRIES) {
        printf("Sorry, you cannot add any more entries.\n");
        return;
    }

    char input[MAX_ENTRY_LENGTH];
    printf("Enter your entry:\n");
    fgets(input, MAX_ENTRY_LENGTH, stdin);
    strcat(input, "\n");

    time_t now = time(NULL);
    strftime(entries[numEntries].date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    strcpy(entries[numEntries].entry, input);
    numEntries++;

    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (numEntries == 0) {
        printf("You have no entries yet.\n");
        return;
    }

    printf("Your entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntry() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter a keyword to search for:\n");
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("%s - %s\n", entries[i].date, entries[i].entry);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found with that keyword.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add entry\n2. View entries\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}