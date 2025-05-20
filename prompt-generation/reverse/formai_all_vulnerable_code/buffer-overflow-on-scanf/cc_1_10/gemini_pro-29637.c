//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct contact {
    char name[50];
    char phone_number[20];
} contact;

// Create an array of contacts
contact phone_book[MAX_CONTACTS];

// Get the number of contacts in the phone book
int get_num_contacts() {
    int num_contacts;
    printf("How many contacts do you want to store? ");
    scanf("%d", &num_contacts);
    return num_contacts;
}

// Get the details of a contact
void get_contact_details(contact *contact) {
    printf("Enter the name of the contact: ");
    scanf("%s", contact->name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", contact->phone_number);
}

// Add a contact to the phone book
void add_contact(int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        get_contact_details(&phone_book[i]);
    }
}

// Search for a contact in the phone book
void search_contact() {
    char name[50];
    printf("Enter the name of the contact you want to search for: ");
    scanf("%s", name);
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone number: %s\n", phone_book[i].phone_number);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Display all contacts in the phone book
void display_contacts(int num_contacts) {
    printf("Here are all the contacts in your phone book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i + 1, phone_book[i].name, phone_book[i].phone_number);
    }
}

// Main function
int main() {
    int num_contacts = get_num_contacts();
    add_contact(num_contacts);
    search_contact();
    display_contacts(num_contacts);
    return 0;
}