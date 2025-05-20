//FormAI DATASET v1.0 Category: Phone Book ; Style: real-life
// C Phone Book Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

int num_contacts = 0;
Contact contacts[MAX_CONTACTS];

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Sorry, the phone book is full.\n");
        return;
    }
    Contact new_contact;
    printf("Enter the contact name: ");
    fgets(new_contact.name, sizeof(new_contact.name), stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0;
    printf("Enter the contact phone number: ");
    fgets(new_contact.phone, sizeof(new_contact.phone), stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0;
    contacts[num_contacts++] = new_contact;
    printf("Contact added!\n");
}

void display_contacts() {
    if (num_contacts == 0) {
        printf("The phone book is empty.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    printf("Welcome to the Phone Book!\n");
    while (1) {
        printf("Menu: 1) Add Contact 2) Display Contacts 3) Quit\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // consume newline character after scanf
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}