//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define NAME_SIZE 50

typedef struct {
    char name[NAME_SIZE];
    char phone[15];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void print_menu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Reflect\n");
    printf("5. Quit\n");
}

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter contact name: ");
    fgets(contacts[num_contacts].name, NAME_SIZE, stdin);
    contacts[num_contacts].name[strlen(contacts[num_contacts].name) - 1] = '\0'; // remove newline character

    printf("Enter contact phone number: ");
    fgets(contacts[num_contacts].phone, 15, stdin);
    contacts[num_contacts].phone[strlen(contacts[num_contacts].phone) - 1] = '\0'; // remove newline character

    num_contacts++;
    printf("Contact added successfully.\n");
}

int search_contact(char name[]) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void delete_contact(int index) {
    if (index < 0 || index >= num_contacts) {
        printf("Invalid contact index.\n");
        return;
    }

    memmove(&contacts[index], &contacts[index + 1], sizeof(Contact) * (num_contacts - index - 1));
    num_contacts--;
    printf("Contact deleted successfully.\n");
}

void reflect() {
    printf("\nReflection Mode:\n");
    printf("You have added %d contacts in this phone book.\n", num_contacts);
    printf("Let's see the names of your contacts:\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s\n", i + 1, contacts[i].name);
    }
}

int main() {
    int choice;
    char name[NAME_SIZE];
    int index;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                printf("Enter contact name: ");
                fgets(name, NAME_SIZE, stdin);
                name[strlen(name) - 1] = '\0'; // remove newline character
                index = search_contact(name);

                if (index != -1) {
                    printf("Contact found: %s - %s\n", contacts[index].name, contacts[index].phone);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 3:
                printf("Enter contact index to delete: ");
                scanf("%d", &index);
                delete_contact(index - 1);
                break;
            case 4:
                reflect();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}