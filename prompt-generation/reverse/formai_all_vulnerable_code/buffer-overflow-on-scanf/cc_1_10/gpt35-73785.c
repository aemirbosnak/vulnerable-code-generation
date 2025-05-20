//FormAI DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact(Contact *contacts, int *num_contacts);
void delete_contact(Contact *contacts, int *num_contacts);
void display_contacts(Contact *contacts, int num_contacts);
void modify_contact(Contact *contacts, int num_contacts);

int main(void) {
    Contact phone_book[50];
    int num_contacts = 0;
    int option;

    do {
        printf("Phone Book\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Display contacts\n");
        printf("4. Modify contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_contact(phone_book, &num_contacts);
                break;
            case 2:
                delete_contact(phone_book, &num_contacts);
                break;
            case 3:
                display_contacts(phone_book, num_contacts);
                break;
            case 4:
                modify_contact(phone_book, num_contacts);
                break;
            case 5:
                printf("Thank you for using Phone Book!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

void add_contact(Contact *contacts, int *num_contacts) {
    if (*num_contacts < 50) {
        printf("Enter name: ");
        scanf("%s", contacts[*num_contacts].name);
        printf("Enter phone number: ");
        scanf("%s", contacts[*num_contacts].phone);
        (*num_contacts)++;
    } else {
        printf("Phone book is full. Unable to add contact.\n");
    }
}

void delete_contact(Contact *contacts, int *num_contacts) {
    char name[MAX_NAME_LENGTH];
    int i, j;

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            for (j = i; j < *num_contacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j+1].name);
                strcpy(contacts[j].phone, contacts[j+1].phone);
            }
            (*num_contacts)--;
            return;
        }
    }

    printf("%s not found in phone book. Unable to delete contact.\n", name);
}

void display_contacts(Contact *contacts, int num_contacts) {
    int i;

    if (num_contacts == 0) {
        printf("Phone book is empty. No contacts to display.\n");
    } else {
        printf("Contacts:\n");
        for (i = 0; i < num_contacts; i++) {
            printf("%s: %s\n", contacts[i].name, contacts[i].phone);
        }
    }
}

void modify_contact(Contact *contacts, int num_contacts) {
    char name[MAX_NAME_LENGTH];
    int i;

    printf("Enter name of contact to modify: ");
    scanf("%s", name);

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone);
            printf("%s's phone number has been updated.\n", name);
            return;
        }
    }

    printf("%s not found in phone book. Unable to modify contact.\n", name);
}