//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 50
#define NAME_LENGTH 50
#define PHONE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(void);
void search_contact(void);
void display_contacts(void);
void print_menu(void);

int main() {
    char choice;
    do {
        print_menu();
        scanf("%c", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 'A':
                add_contact();
                break;
            case 'S':
                search_contact();
                break;
            case 'D':
                display_contacts();
                break;
            case 'Q':
                printf("Farewell, noble adventurer.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 'Q');

    return 0;
}

void add_contact() {
    if (num_contacts == MAX_CONTACTS) {
        printf("Your phone book is full.\n");
        return;
    }

    printf("Enter contact name: ");
    fgets(contacts[num_contacts].name, NAME_LENGTH, stdin);
    contacts[num_contacts].name[strcspn(contacts[num_contacts].name, "\n")] = '\0';

    printf("Enter contact phone number: ");
    fgets(contacts[num_contacts].phone, PHONE_LENGTH, stdin);
    contacts[num_contacts].phone[strcspn(contacts[num_contacts].phone, "\n")] = '\0';

    num_contacts++;

    printf("Contact added successfully.\n");
}

void search_contact() {
    char search_name[NAME_LENGTH];
    int i;

    printf("Enter contact name to search: ");
    fgets(search_name, NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void display_contacts() {
    int i;

    printf("\nContacts:\n");

    for (i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void print_menu() {
    printf("\n*******************************************************\n");
    printf("*          The Enchanted Phone Book of Yore          *\n");
    printf("*******************************************************\n");
    printf("* A)dd new contact                                   *\n");
    printf("* S)earch for contact                               *\n");
    printf("* D)isplay all contacts                             *\n");
    printf("* Q)uit the phone book                               *\n");
    printf("*******************************************************\n");
}