//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 25
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} Contact;

Contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts < MAX_CONTACTS) {
        Contact new_contact;
        printf("Enter name: ");
        fgets(new_contact.name, MAX_NAME_LENGTH, stdin);
        size_t name_length = strlen(new_contact.name);
        if (new_contact.name[name_length - 1] == '\n') {
            new_contact.name[name_length - 1] = '\0';
        }
        printf("Enter phone number: ");
        fgets(new_contact.phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);
        size_t phone_number_length = strlen(new_contact.phone_number);
        if (new_contact.phone_number[phone_number_length - 1] == '\n') {
            new_contact.phone_number[phone_number_length - 1] = '\0';
        }
        phone_book[num_contacts++] = new_contact;
        printf("Contact added successfully.\n");
    } else {
        printf("Error: phone book is full.\n");
    }
}

void list_contacts() {
    printf("Name\t\tPhone Number\n");
    printf("============================================\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t\t%s\n", phone_book[i].name, phone_book[i].phone_number);
    }
    printf("============================================\n");
}

void search_contacts() {
    char search_term[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    fgets(search_term, MAX_NAME_LENGTH, stdin);
    size_t search_term_length = strlen(search_term);
    if (search_term[search_term_length - 1] == '\n') {
        search_term[search_term_length - 1] = '\0';
    }
    int found_match = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_term) == 0) {
            printf("%s\t\t%s\n", phone_book[i].name, phone_book[i].phone_number);
            found_match = 1;
        }
    }
    if (!found_match) {
        printf("No matching contacts found.\n");
    }
}

int main() {
    char choice;
    do {
        printf("Select an option:\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Search contacts\n");
        printf("4. Quit\n");
        printf("Choice: ");
        scanf(" %c", &choice);
        getchar(); // clear out the newline character
        switch (choice) {
            case '1':
                add_contact();
                break;
            case '2':
                list_contacts();
                break;
            case '3':
                search_contacts();
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != '4');
    return 0;
}