//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 20

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void print_menu() {
    printf("\n--------------------\n");
    printf("| Phone Book Menu   |\n");
    printf("--------------------\n");
    printf("| 1. Add Contact   |\n");
    printf("| 2. Delete Contact|\n");
    printf("| 3. Search Contact|\n");
    printf("| 4. Display All  |\n");
    printf("| 5. Exit          |\n");
    printf("--------------------\n");
}

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone Book is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    while (getchar() != '\n') {}

    printf("Enter phone number: ");
    fgets(contacts[num_contacts].phone, PHONE_LENGTH, stdin);
    contacts[num_contacts].phone[strlen(contacts[num_contacts].phone) - 1] = '\0';

    num_contacts++;
    printf("Contact added successfully!\n");
}

void delete_contact() {
    int index;
    char search_name[NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", search_name);

    for (index = 0; index < num_contacts; index++) {
        if (strcmp(contacts[index].name, search_name) == 0) {
            memmove(&contacts[index], &contacts[index + 1], (num_contacts - index - 1) * sizeof(Contact));
            num_contacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

void search_contact() {
    int index;
    char search_name[NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (index = 0; index < num_contacts; index++) {
        if (strcmp(contacts[index].name, search_name) == 0) {
            printf("Name: %s\n", contacts[index].name);
            printf("Phone: %s\n", contacts[index].phone);
            return;
        }
    }

    printf("Contact not found!\n");
}

void display_all() {
    int index;

    printf("\nPhone Book:\n");
    for (index = 0; index < num_contacts; index++) {
        printf("%d. %s - %s\n", index + 1, contacts[index].name, contacts[index].phone);
    }
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                display_all();
                break;
            case 5:
                printf("Exiting Phone Book...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}