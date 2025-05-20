//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_ENTRY 50
#define NAME_LENGTH 50
#define PHONE_LENGTH 11

struct entry {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
};

int main() {
    struct entry phonebook[MAX_ENTRY];
    char choice;
    int num_entries = 0;

    do {
        printf("\n1. Add Entry\n2. Display Entries\n3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                if (num_entries < MAX_ENTRY) {
                    printf("Enter name: ");
                    scanf("%s", phonebook[num_entries].name);
                    printf("Enter phone number (no dashes): ");
                    scanf("%s", phonebook[num_entries].phone);
                    num_entries++;
                }
                else {
                    printf("Phone book is full!\n");
                }
                break;
            case '2':
                if (num_entries == 0) {
                    printf("Phone book is empty!\n");
                }
                else {
                    printf("%-20s %s\n", "Name", "Phone");
                    for (int i = 0; i < num_entries; i++) {
                        printf("%-20s %s\n", phonebook[i].name, phonebook[i].phone);
                    }
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != '3');

    return 0;
}