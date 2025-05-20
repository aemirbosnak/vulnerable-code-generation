//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

int main() {
    FILE* file;
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open phonebook file.\n");
        return 1;
    }

    // Read in entries from file
    while (fscanf(file, "%s %s\n", entries[numEntries].name, entries[numEntries].number) == 2) {
        numEntries++;
        if (numEntries == MAX_ENTRIES) {
            printf("Error: Phonebook is full.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // User input
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];

    printf("Enter name to search for: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Name not found.\n");
    }

    return 0;
}