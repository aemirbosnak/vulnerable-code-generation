//FormAI DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to store contact information
typedef struct {
    char name[30];
    char phone_number[15];
    char email[50];
} contact;

// Define function to add new contacts to the phone book
void add_contact(contact *phone_book[], int *num_contacts) {
    contact *new_contact = malloc(sizeof(contact));
    if (!new_contact) {
        printf("Error: unable to allocate memory.\n");
        return;
    }
    printf("Enter contact name: \n");
    fgets(new_contact->name, 30, stdin);
    printf("Enter phone number (format: xxx-xxx-xxxx): \n");
    fgets(new_contact->phone_number, 15, stdin);
    printf("Enter email address: \n");
    fgets(new_contact->email, 50, stdin);
    phone_book[*num_contacts] = new_contact;
    (*num_contacts)++;
    printf("Contact successfully added!\n");
}

// Define function to display all contacts in the phone book
void display_contacts(contact *phone_book[], int num_contacts) {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("Phone book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Contact #%d\nName: %sPhone: %sEmail: %s", i + 1, phone_book[i]->name, phone_book[i]->phone_number, phone_book[i]->email);
    }
}

// Define function to delete a contact from the phone book
void delete_contact(contact *phone_book[], int *num_contacts) {
    if (*num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("Enter the number of the contact you want to delete: \n");
    int contact_num;
    scanf("%d", &contact_num);
    getchar(); // clear input buffer
    if (contact_num < 1 || contact_num > *num_contacts) {
        printf("Error: invalid contact number.\n");
        return;
    }
    free(phone_book[contact_num - 1]); // free memory allocated for deleted contact
    for (int i = contact_num - 1; i < *num_contacts - 1; i++) {
        phone_book[i] = phone_book[i + 1]; // shift elements over to fill in gap
    }
    (*num_contacts)--;
    printf("Contact successfully deleted!\n");
}

int main() {
    printf("==========================\n");
    printf("Welcome to My Phone Book!\n");
    printf("==========================\n");
    contact *phone_book[100]; // array of pointers to store contact information
    int num_contacts = 0; // number of contacts currently stored in phone_book
    int user_choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Display all contacts\n");
        printf("3. Delete a contact\n");
        printf("4. Exit\n");
        scanf("%d", &user_choice);
        getchar(); // clear input buffer
        switch (user_choice) {
            case 1:
                add_contact(phone_book, &num_contacts);
                break;
            case 2:
                display_contacts(phone_book, num_contacts);
                break;
            case 3:
                delete_contact(phone_book, &num_contacts);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: invalid choice.\n");
        }
    } while (user_choice != 4);

    // Free memory allocated for contacts
    for (int i = 0; i < num_contacts; i++) {
        free(phone_book[i]);
    }
    return 0;
}