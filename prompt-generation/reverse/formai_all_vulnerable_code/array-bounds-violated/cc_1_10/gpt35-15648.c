//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Defines a structure for storing the contact information
struct Contact {
    char name[50];
    char phone_number[20];
    char email[50];
};

// Function to print the menu of options
void print_menu() {
    printf("\n\nC PHONE BOOK v1.0\n\n");
    printf("1. Add Contact\n");
    printf("2. Search by Name\n");
    printf("3. Search by Phone Number\n");
    printf("4. Search by Email\n");
    printf("5. Display All Contacts\n");
    printf("6. Exit\n\n");
    printf("Enter your choice: ");
}

// Function to get a valid phone number from the user
void get_valid_phone_number(char *phone_number) {
    int i, len;
    char input[20], valid_chars[] = "0123456789-() ";
    
    do {
        printf("Enter phone number: ");
        fgets(input, sizeof(input), stdin);
        len = strlen(input);
        
        // Remove newline character from input
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }
        
        // Verify that all characters in input are valid
        for (i = 0; i < len; i++) {
            if (!strchr(valid_chars, input[i])) {
                break;
            }
        }
    } while (i < len);
    
    // Copy the input phone number to the output argument
    strcpy(phone_number, input);
}

// Function to add a new contact to the phone book
void add_contact(struct Contact *phone_book, int *num_contacts) {
    printf("\nADD CONTACT\n\n");
    
    // Prompt the user for information about the new contact
    printf("Enter name: ");
    fgets(phone_book[*num_contacts].name, sizeof(phone_book->name), stdin);
    printf("Enter email: ");
    fgets(phone_book[*num_contacts].email, sizeof(phone_book->email), stdin);
    get_valid_phone_number(phone_book[*num_contacts].phone_number);
    
    // Increment the number of contacts
    (*num_contacts)++;
    
    printf("\nContact added successfully!\n");
}

// Function to search for a contact by name
void search_by_name(struct Contact *phone_book, int num_contacts) {
    char search_term[50];
    int i, matches = 0;
    
    // Prompt the user for the search term
    printf("\nSEARCH BY NAME\n\n");
    printf("Enter name: ");
    fgets(search_term, sizeof(search_term), stdin);
    
    // Convert search term to lowercase for case-insensitivity
    for (i = 0; search_term[i]; i++) {
        search_term[i] = tolower(search_term[i]);
    }
    
    // Loop through all contacts and print any matches
    for (i = 0; i < num_contacts; i++) {
        char *name = phone_book[i].name;
        for (int j = 0; name[j]; j++) {
            name[j] = tolower(name[j]);
        }
        
        if (strstr(name, search_term) != NULL) {
            printf("%s\n%s\n%s\n\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
            matches++;
        }
    }
    
    // If no matches were found, inform the user
    if (matches == 0) {
        printf("No matches found!\n");
    }
}

// Function to search for a contact by phone number
void search_by_phone_number(struct Contact *phone_book, int num_contacts) {
    char search_term[20];
    int i, matches = 0;
    
    // Prompt the user for the search term
    printf("\nSEARCH BY PHONE NUMBER\n\n");
    get_valid_phone_number(search_term);
    
    // Loop through all contacts and print any matches
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].phone_number, search_term) == 0) {
            printf("%s\n%s\n%s\n\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
            matches++;
        }
    }
    
    // If no matches were found, inform the user
    if (matches == 0) {
        printf("No matches found!\n");
    }
}

// Function to search for a contact by email
void search_by_email(struct Contact *phone_book, int num_contacts) {
    char search_term[50];
    int i, matches = 0;
    
    // Prompt the user for the search term
    printf("\nSEARCH BY EMAIL\n\n");
    printf("Enter email: ");
    fgets(search_term, sizeof(search_term), stdin);
    
    // Loop through all contacts and print any matches
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].email, search_term) == 0) {
            printf("%s\n%s\n%s\n\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
            matches++;
        }
    }
    
    // If no matches were found, inform the user
    if (matches == 0) {
        printf("No matches found!\n");
    }
}

// Function to display all contacts in the phone book
void display_all_contacts(struct Contact *phone_book, int num_contacts) {
    int i;
    
    printf("\nDISPLAY ALL CONTACTS\n\n");
    
    // Loop through all contacts and print their information
    for (i = 0; i < num_contacts; i++) {
        printf("%s\n%s\n%s\n\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
    }
    
    // If no contacts exist, inform the user
    if (num_contacts == 0) {
        printf("No contacts found!\n");
    }
}

int main()
{
    struct Contact phone_book[100];  // Maximum of 100 contacts
    int num_contacts = 0;  // Keeps track of the number of contacts
    
    int choice;  // Variable for the user's menu choice
    
    do {
        print_menu();
        scanf("%d", &choice);
        getchar();  // Consume newline character left in input buffer
        
        switch (choice) {
            case 1:
                add_contact(phone_book, &num_contacts);
                break;
            case 2:
                search_by_name(phone_book, num_contacts);
                break;
            case 3:
                search_by_phone_number(phone_book, num_contacts);
                break;
            case 4:
                search_by_email(phone_book, num_contacts);
                break;
            case 5:
                display_all_contacts(phone_book, num_contacts);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);
    
    return 0;
}