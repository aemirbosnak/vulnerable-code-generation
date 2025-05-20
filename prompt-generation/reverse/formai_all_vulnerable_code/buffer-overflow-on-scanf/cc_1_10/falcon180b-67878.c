//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[30];
    char phone[15];
} contact;

contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_contacts].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_contacts].phone);

    num_contacts++;
}

void display_all_contacts() {
    printf("\nPhonebook:\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i+1, phonebook[i].name, phonebook[i].phone);
    }
}

void search_contact() {
    char search_name[30];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    int found = 0;

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("\n%s - %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Phonebook!\n");

    while (1) {
        printf("\n1. Add contact\n2. Display all contacts\n3. Search contact\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_all_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}