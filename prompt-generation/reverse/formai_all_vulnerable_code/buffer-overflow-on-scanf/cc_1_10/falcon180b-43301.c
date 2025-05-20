//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* date, char* entry) {
    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].entry, entry);
    numEntries++;
}

void displayEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[1000];
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to Ada Lovelace's Digital Diary!\n\n");

    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        fgets(input, sizeof(input), stdin);
        strcpy(date, input);

        printf("Enter your entry: ");
        fgets(input, sizeof(input), stdin);
        strcpy(entry, input);

        addEntry(date, entry);
        printf("\nEntry added!\n");

        printf("Press 'd' to display entries or any other key to continue: ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'd' || choice == 'D') {
            displayEntries();
        }
    }

    return 0;
}