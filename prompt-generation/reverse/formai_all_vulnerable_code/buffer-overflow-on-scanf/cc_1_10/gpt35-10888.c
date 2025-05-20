//FormAI DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 100
#define MAX_PHONE 20

struct contact {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    char phone[MAX_PHONE];
};

void add_new_contact(FILE *file) {
    struct contact new_contact;

    printf("Enter new contact name: ");
    fgets(new_contact.name, MAX_NAME, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0;

    printf("Enter new contact email: ");
    fgets(new_contact.email, MAX_EMAIL, stdin);
    new_contact.email[strcspn(new_contact.email, "\n")] = 0;

    printf("Enter new contact phone number: ");
    fgets(new_contact.phone, MAX_PHONE, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0;

    fprintf(file, "%s %s %s\n", new_contact.name, new_contact.email, new_contact.phone);
}

void display_all_contacts(FILE *file) {
    struct contact current_contact;
    int count = 0;

    printf("\nAll Contacts:");
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s %s %s", current_contact.name, current_contact.email, current_contact.phone) != EOF) {
        printf("\n%d. Name: %s", ++count, current_contact.name);
        printf("\n   Email: %s", current_contact.email);
        printf("\n   Phone: %s", current_contact.phone);
    }
    printf("\n");
}

int main() {
    FILE *contacts_file;
    char filename[] = "contacts.txt";
    char choice;

    contacts_file = fopen(filename, "a+"); // open file in append mode or create new if doesn't exist 
    if (contacts_file == NULL) {
        printf("Error: Unable to open file!");
        return 1;
    }

    do {
        printf("\nContact Manager Menu:");
        printf("\n=====================");
        printf("\n1. Add new contact");
        printf("\n2. Display all contacts");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%c", &choice);
        getchar(); // consume newline from stdin

        switch (choice) {
            case '1':
                add_new_contact(contacts_file);
                break;
            case '2':
                display_all_contacts(contacts_file);
                break;
            case '3':
                printf("Exiting the program...");
                break;
            default:
                printf("Invalid choice! Please try again.");
                break;
        }
    } while (choice != '3');

    fclose(contacts_file);

    return 0;
}