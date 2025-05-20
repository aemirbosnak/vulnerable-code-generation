//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* date, char* entry) {
    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].entry, entry);
    numEntries++;
}

void displayEntries() {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[100];
    char date[11];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("\nEnter a date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter your entry:\n");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
        strcpy(entry, input);

        addEntry(date, entry);
        printf("Entry added.\n");

        displayEntries();

        printf("\nDo you want to add another entry? (y/n): ");
        scanf("%s", input);
        if (strcmp(input, "n") == 0) {
            break;
        }
    }

    return 0;
}