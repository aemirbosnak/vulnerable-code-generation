//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 32
#define MAX_NUMBER_LENGTH 16
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

entry phonebook[MAX_ENTRIES];

int main() {
    int num_entries = 0;

    while (1) {
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_entries == MAX_ENTRIES) {
                    printf("Phonebook is full");
                } else {
                    printf("Enter name: ");
                    scanf("%s", phonebook[num_entries].name);
                    printf("Enter number: ");
                    scanf("%s", phonebook[num_entries].number);
                    num_entries++;
                }
                break;
            case 2:
                printf("Enter name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);

                int found = 0;
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(phonebook[i].name, name) == 0) {
                        printf("Number: %s\n", phonebook[i].number);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Name not found in phonebook\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}