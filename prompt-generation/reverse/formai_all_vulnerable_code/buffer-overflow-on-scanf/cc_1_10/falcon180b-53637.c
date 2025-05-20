//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 20
#define MAX_PHONEBOOK_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} phonebook_entry_t;

int main() {
    phonebook_entry_t phonebook[MAX_PHONEBOOK_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("Enter 1 to add a contact, 2 to search for a contact, or 3 to exit:\n");
        int choice = 0;
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_entries >= MAX_PHONEBOOK_ENTRIES) {
                printf("Phonebook is full.\n");
            } else {
                printf("Enter name (up to %d characters):\n", MAX_NAME_LENGTH - 1);
                scanf("%s", phonebook[num_entries].name);

                printf("Enter phone number (up to %d characters):\n", MAX_NUMBER_LENGTH - 1);
                scanf("%s", phonebook[num_entries].number);

                num_entries++;
            }
        } else if (choice == 2) {
            printf("Enter name to search for:\n");
            char search_name[MAX_NAME_LENGTH];
            scanf("%s", search_name);

            int found = 0;
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(phonebook[i].name, search_name) == 0) {
                    printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
                    found = 1;
                }
            }

            if (!found) {
                printf("Contact not found.\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}