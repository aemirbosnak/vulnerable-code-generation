//FormAI DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// structure to hold contact information
typedef struct {
    char name[MAX];
    char phone[MAX];
    char email[MAX];
} Contact;

// global array to store contacts
Contact phonebook[MAX];

// function prototypes
void print_menu();
void add_contact();
void view_contacts();
void search_contacts();

int main() {
    int choice;

    do {
        // print menu and request user choice
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;

            case 2:
                view_contacts();
                break;

            case 3:
                search_contacts();
                break;

            case 4:
                // exit the program
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}

void print_menu() {
    printf("\n\n");
    printf("***************************\n");
    printf("*        PHONEBOOK        *\n");
    printf("***************************\n\n");
    printf("1. Add contact\n");
    printf("2. View contacts\n");
    printf("3. Search contacts\n");
    printf("4. Exit\n");
}

void add_contact() {
    int i;
    char name[MAX], phone[MAX], email[MAX];

    // request contact information from user
    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    printf("Enter email: ");
    scanf("%s", email);

    // check if contact already exists
    for (i = 0; i < MAX; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Contact already exists!\n");
            return;
        }
    }

    // add contact to phonebook
    for (i = 0; i < MAX; i++) {
        if (strlen(phonebook[i].name) == 0) {
            strcpy(phonebook[i].name, name);
            strcpy(phonebook[i].phone, phone);
            strcpy(phonebook[i].email, email);
            printf("Contact added successfully!\n");
            return;
        }
    }

    // phonebook is full
    printf("Phonebook is full!\n");

}

void view_contacts() {
    int i;

    // check if phonebook is empty
    for (i = 0; i < MAX; i++) {
        if (strlen(phonebook[i].name) != 0)
            break;
    }

    if (i == MAX) {
        printf("Phonebook is empty!\n");
        return;
    }

    // print all contacts in phonebook
    printf("Name\t\tPhone\t\tEmail\n");
    printf("-------------------------------------------\n");
    for (i = 0; i < MAX; i++) {
        if (strlen(phonebook[i].name) != 0)
            printf("%-15s%-15s%-15s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
    }
}

void search_contacts() {
    char search_name[MAX];
    int i, found = 0;

    // request name to search for from user
    printf("Enter name to search for: ");
    scanf("%s", search_name);

    // search for contact in phonebook
    for (i = 0; i < MAX; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name\t\tPhone\t\tEmail\n");
            printf("-------------------------------------------\n");
            printf("%-15s%-15s%-15s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Contact not found!\n");
}