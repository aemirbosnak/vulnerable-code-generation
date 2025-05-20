//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int main() {
    int numEntries = 0;
    FILE *phoneBook;
    Entry entries[MAX_ENTRIES];

    // Open the phone book file
    phoneBook = fopen("phonebook.txt", "r");
    if (phoneBook == NULL) {
        printf("Error: Could not open phone book file.\n");
        exit(1);
    }

    // Read in the entries from the file
    while (fscanf(phoneBook, "%s %s\n", entries[numEntries].name, entries[numEntries].number)!= EOF) {
        numEntries++;
    }

    // Sort the entries alphabetically by name
    for (int i = 0; i < numEntries - 1; i++) {
        for (int j = i + 1; j < numEntries; j++) {
            if (strcmp(entries[i].name, entries[j].name) > 0) {
                // Swap the entries
                char tempName[MAX_NAME_LENGTH];
                strcpy(tempName, entries[i].name);
                strcpy(entries[i].name, entries[j].name);
                strcpy(entries[j].name, tempName);

                char tempNumber[MAX_NUMBER_LENGTH];
                strcpy(tempNumber, entries[i].number);
                strcpy(entries[i].number, entries[j].number);
                strcpy(entries[j].number, tempNumber);
            }
        }
    }

    // Print the sorted entries to the console
    printf("Sorted Phone Book:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }

    // Close the phone book file
    fclose(phoneBook);

    return 0;
}