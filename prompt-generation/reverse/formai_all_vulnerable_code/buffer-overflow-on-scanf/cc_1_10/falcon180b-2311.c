//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64
#define MAX_PHONE_NUM_LEN 20
#define MAX_NUM_OF_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char phone_number[MAX_PHONE_NUM_LEN];
} Contact;

int num_of_entries = 0;

void add_contact(Contact *contact_list, char *name, char *phone_number) {
    if (num_of_entries >= MAX_NUM_OF_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strcpy(contact_list[num_of_entries].name, name);
    strcpy(contact_list[num_of_entries].phone_number, phone_number);

    num_of_entries++;
}

void search_contact(Contact *contact_list, char *name) {
    int i;

    for (i = 0; i < num_of_entries; i++) {
        if (strcmp(contact_list[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", contact_list[i].name, contact_list[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    Contact contact_list[MAX_NUM_OF_ENTRIES];
    int choice;

    printf("Welcome to the Phone Book program!\n\n");

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", contact_list[num_of_entries-1].name);
            printf("Enter phone number: ");
            scanf("%s", contact_list[num_of_entries-1].phone_number);
            break;

        case 2:
            printf("Enter name to search: ");
            char search_name[MAX_NAME_LEN];
            scanf("%s", search_name);

            search_contact(contact_list, search_name);
            break;

        case 3:
            printf("Exiting the program...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}