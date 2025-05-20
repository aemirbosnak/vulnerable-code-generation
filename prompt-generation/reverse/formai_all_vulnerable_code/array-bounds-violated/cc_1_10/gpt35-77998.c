//FormAI DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone_number[20];
};

struct Contact phone_book[MAX_CONTACTS];

int num_contacts = 0;

void add_contact() {
    if (num_contacts == MAX_CONTACTS) {
        printf("Can't add another contact. Phone book is full!\n");
        return;
    }

    struct Contact new_contact;
    printf("Enter the name of the contact: ");
    fgets(new_contact.name, 50, stdin);
    new_contact.name[strlen(new_contact.name)-1] = '\0'; // Remove newline character

    printf("Enter the phone number of the contact: ");
    fgets(new_contact.phone_number, 20, stdin);
    new_contact.phone_number[strlen(new_contact.phone_number)-1] = '\0'; // Remove newline character

    phone_book[num_contacts] = new_contact;
    num_contacts++;
    printf("Contact added successfully!\n");
}

void search_contacts() {
    char search_name[50];
    printf("Enter the name of the contact to search: ");
    fgets(search_name, 50, stdin);
    search_name[strlen(search_name)-1] = '\0'; // Remove newline character

    int match_found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("%s's phone number: %s\n", phone_book[i].name, phone_book[i].phone_number);
            match_found = 1;
            break;
        }
    }
    if (!match_found) {
        printf("No matches found for %s\n", search_name);
    }
}

void show_contacts() {
    if (num_contacts == 0) {
        printf("No contacts to show!\n");
        return;
    }
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i+1, phone_book[i].name, phone_book[i].phone_number);
    }
}

int main() {
    printf("*** Retro Phone Book ***\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contacts\n");
        printf("3. Show All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        char choice_str[5];
        fgets(choice_str, 5, stdin);
        int choice = atoi(choice_str);

        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contacts();
                break;
            case 3:
                show_contacts();
                break;
            case 4:
                printf("Thanks for using Retro Phone Book!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}