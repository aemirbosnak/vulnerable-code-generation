//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct {
    char name[50];
    char number[20];
} contact;

// Create an array of contacts
contact contacts[MAX_CONTACTS];

// Get the number of contacts in the phone book
int get_num_contacts() {
    int num_contacts = 0;
    FILE *fp = fopen("phonebook.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%s %s", contacts[num_contacts].name, contacts[num_contacts].number) != EOF) {
            num_contacts++;
        }
        fclose(fp);
    }
    return num_contacts;
}

// Add a contact to the phone book
void add_contact(char *name, char *number) {
    int num_contacts = get_num_contacts();
    if (num_contacts < MAX_CONTACTS) {
        strcpy(contacts[num_contacts].name, name);
        strcpy(contacts[num_contacts].number, number);
        FILE *fp = fopen("phonebook.txt", "a");
        if (fp != NULL) {
            fprintf(fp, "%s %s\n", name, number);
            fclose(fp);
        }
    } else {
        printf("The phone book is full.\n");
    }
}

// Delete a contact from the phone book
void delete_contact(char *name) {
    int num_contacts = get_num_contacts();
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            break;
        }
    }
    if (i < num_contacts) {
        for (i = i + 1; i < num_contacts; i++) {
            strcpy(contacts[i - 1].name, contacts[i].name);
            strcpy(contacts[i - 1].number, contacts[i].number);
        }
        FILE *fp = fopen("phonebook.txt", "w");
        if (fp != NULL) {
            for (i = 0; i < num_contacts - 1; i++) {
                fprintf(fp, "%s %s\n", contacts[i].name, contacts[i].number);
            }
            fclose(fp);
        }
    } else {
        printf("The contact does not exist.\n");
    }
}

// Search for a contact in the phone book
void search_contact(char *name) {
    int num_contacts = get_num_contacts();
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }
    printf("The contact does not exist.\n");
}

// Print the phone book
void print_phonebook() {
    int num_contacts = get_num_contacts();
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].number);
    }
}

// Main function
int main() {
    // Add some contacts to the phone book
    add_contact("Alice", "555-1212");
    add_contact("Bob", "555-1213");
    add_contact("Carol", "555-1214");

    // Print the phone book
    print_phonebook();

    // Search for a contact
    search_contact("Bob");

    // Delete a contact
    delete_contact("Carol");

    // Print the phone book again
    print_phonebook();

    return 0;
}