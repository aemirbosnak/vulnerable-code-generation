//FormAI DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 30
#define MAX_PHONE_LEN 12

struct contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
};

struct phonebook {
    struct contact contacts[MAX_CONTACTS];
    int num_contacts;
};

void print_menu() {
    printf("1. Add contact\n");
    printf("2. Delete contact\n");
    printf("3. Display all contacts\n");
    printf("4. Search contacts\n");
    printf("5. Exit\n");
}

int get_option() {
    int option;
    printf("Enter your choice: ");
    scanf("%d", &option);
    return option;
}

void add_contact(struct phonebook *pb) {
    if (pb->num_contacts == MAX_CONTACTS) {
        printf("Phonebook is full. Cannot add contact.\n");
        return;
    }

    struct contact c;
    printf("Enter name: ");
    scanf("%s", c.name);
    printf("Enter phone number: ");
    scanf("%s", c.phone);

    pb->contacts[pb->num_contacts] = c;
    pb->num_contacts++;

    printf("Contact added.\n");
}

void delete_contact(struct phonebook *pb) {
    char name[MAX_NAME_LEN];
    printf("Enter name to delete: ");
    scanf("%s", name);

    int i, found = 0;
    for (i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        pb->num_contacts--;
        for (; i < pb->num_contacts; i++) {
            pb->contacts[i] = pb->contacts[i+1];
        }
        printf("Contact deleted.\n");
    } else {
        printf("Contact not found.\n");
    }
}

void display_contacts(struct phonebook *pb) {
    int i;
    for (i = 0; i < pb->num_contacts; i++) {
        printf("%s: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void search_contacts(struct phonebook *pb) {
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);

    int i, found = 0;
    for (i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            found = 1;
            printf("%s: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    struct phonebook pb = {0};

    while (1) {
        print_menu();
        int option = get_option();

        switch (option) {
            case 1:
                add_contact(&pb);
                break;
            case 2:
                delete_contact(&pb);
                break;
            case 3:
                display_contacts(&pb);
                break;
            case 4:
                search_contacts(&pb);
                break;
            case 5:
                printf("Exiting. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }

        // clear input buffer
        while (getchar() != '\n') {}
    }

    return 0;
}