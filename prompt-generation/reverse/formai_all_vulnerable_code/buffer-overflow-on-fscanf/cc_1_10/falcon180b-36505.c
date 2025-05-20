//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int main() {
    FILE *phonebook;
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;
    char choice;

    phonebook = fopen("phonebook.txt", "r");
    if (phonebook == NULL) {
        printf("Error: Could not open phonebook.txt\n");
        return 1;
    }

    while (fscanf(phonebook, "%s %s\n", entries[numEntries].name, entries[numEntries].number)!= EOF) {
        numEntries++;
    }

    fclose(phonebook);

    while (1) {
        printf("Phonebook:\n");
        for (int i = 0; i < numEntries; i++) {
            printf("%s: %s\n", entries[i].name, entries[i].number);
        }

        printf("Enter choice:\n");
        printf("A - Add entry\n");
        printf("S - Search for entry\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter name: ");
                scanf("%s", entries[numEntries].name);
                printf("Enter number: ");
                scanf("%s", entries[numEntries].number);
                numEntries++;
                break;
            case 'S':
                printf("Enter name to search for: ");
                scanf("%s", entries[numEntries].name);
                for (int i = 0; i < numEntries; i++) {
                    if (strcmp(entries[i].name, entries[numEntries].name) == 0) {
                        printf("%s: %s\n", entries[i].name, entries[i].number);
                    }
                }
                break;
            case 'Q':
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}