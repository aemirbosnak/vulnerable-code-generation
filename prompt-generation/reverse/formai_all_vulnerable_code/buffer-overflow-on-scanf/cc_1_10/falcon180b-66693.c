//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[30];
    char phone[20];
} phonebook_entry;

phonebook_entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char name[30];
    char phone[20];

    printf("Enter contact name: ");
    scanf("%s", name);

    printf("Enter contact phone number: ");
    scanf("%s", phone);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);

    num_entries++;
}

void search_entry() {
    char search_name[30];

    printf("Enter contact name to search: ");
    scanf("%s", search_name);

    int found = 0;

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nPhonebook:\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_entry();
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}