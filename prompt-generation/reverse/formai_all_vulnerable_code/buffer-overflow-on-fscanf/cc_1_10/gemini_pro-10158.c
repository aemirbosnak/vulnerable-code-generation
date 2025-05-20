//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct {
    char name[50];
    char phone_number[20];
    char email[50];
} contact;

// Define the phone book as an array of contacts
contact phone_book[MAX_CONTACTS];

// Get the number of contacts in the phone book
int get_num_contacts() {
    int num_contacts = 0;

    FILE *fp = fopen("phone_book.txt", "r");
    if (fp == NULL) {
        return 0;
    }

    while (fscanf(fp, "%s %s %s", phone_book[num_contacts].name, phone_book[num_contacts].phone_number, phone_book[num_contacts].email) != EOF) {
        num_contacts++;
    }

    fclose(fp);

    return num_contacts;
}

// Add a new contact to the phone book
void add_contact(char *name, char *phone_number, char *email) {
    int num_contacts = get_num_contacts();

    strcpy(phone_book[num_contacts].name, name);
    strcpy(phone_book[num_contacts].phone_number, phone_number);
    strcpy(phone_book[num_contacts].email, email);

    FILE *fp = fopen("phone_book.txt", "a");
    if (fp == NULL) {
        printf("Error opening phone book file\n");
        return;
    }

    fprintf(fp, "%s %s %s\n", phone_book[num_contacts].name, phone_book[num_contacts].phone_number, phone_book[num_contacts].email);

    fclose(fp);
}

// Delete a contact from the phone book
void delete_contact(char *name) {
    int num_contacts = get_num_contacts();

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_contacts) {
        printf("Contact not found\n");
        return;
    }

    for (i = i + 1; i < num_contacts; i++) {
        strcpy(phone_book[i - 1].name, phone_book[i].name);
        strcpy(phone_book[i - 1].phone_number, phone_book[i].phone_number);
        strcpy(phone_book[i - 1].email, phone_book[i].email);
    }

    FILE *fp = fopen("phone_book.txt", "w");
    if (fp == NULL) {
        printf("Error opening phone book file\n");
        return;
    }

    for (i = 0; i < num_contacts - 1; i++) {
        fprintf(fp, "%s %s %s\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
    }

    fclose(fp);
}

// Search for a contact in the phone book
void search_contact(char *name) {
    int num_contacts = get_num_contacts();

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_contacts) {
        printf("Contact not found\n");
        return;
    }

    printf("Name: %s\n", phone_book[i].name);
    printf("Phone number: %s\n", phone_book[i].phone_number);
    printf("Email: %s\n", phone_book[i].email);
}

// Print the phone book
void print_phone_book() {
    int num_contacts = get_num_contacts();

    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s %s %s\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
    }
}

// Main function
int main() {
    // Add some contacts to the phone book
    add_contact("John Doe", "555-1212", "john.doe@example.com");
    add_contact("Jane Doe", "555-1213", "jane.doe@example.com");
    add_contact("John Smith", "555-1214", "john.smith@example.com");
    add_contact("Jane Smith", "555-1215", "jane.smith@example.com");

    // Print the phone book
    print_phone_book();

    // Search for a contact
    search_contact("John Doe");

    // Delete a contact
    delete_contact("John Doe");

    // Print the phone book
    print_phone_book();

    return 0;
}