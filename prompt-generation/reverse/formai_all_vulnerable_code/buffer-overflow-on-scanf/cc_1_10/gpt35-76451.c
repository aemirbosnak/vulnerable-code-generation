//FormAI DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // Maximum number of emails that can be stored
#define MAX_EMAIL_LEN 100 // Maximum length of an email address
#define MAX_NAME_LEN 50 // Maximum length of a name

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

Contact mailing_list[MAX_EMAILS]; // Mailing list array
int num_emails = 0; // Number of emails currently stored in the mailing list

// Function to add a new contact to the mailing list
void add_contact() {
    if (num_emails >= MAX_EMAILS) {
        printf("Mailing list is full\n");
        return;
    }
    Contact new_contact;
    printf("Enter contact name: ");
    scanf("%s", new_contact.name);
    printf("Enter contact email: ");
    scanf("%s", new_contact.email);
    mailing_list[num_emails] = new_contact;
    num_emails++;
    printf("Contact added to mailing list\n");
}

// Function to print the contents of the mailing list
void print_list() {
    for (int i = 0; i < num_emails; i++) {
        printf("%s: %s\n", mailing_list[i].name, mailing_list[i].email);
    }
}

// Function to search for a contact in the mailing list
void search_contact() {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(mailing_list[i].name, search_name) == 0) {
            printf("Contact found:\n%s: %s\n", mailing_list[i].name, mailing_list[i].email);
            return;
        }
    }
    printf("Contact not found\n");
}

int main() {
    int choice;
    while (1) {
        printf("Mailing List Manager\n\n");
        printf("1. Add contact\n");
        printf("2. Print mailing list\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                print_list();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("\n");
    }
    return 0;
}