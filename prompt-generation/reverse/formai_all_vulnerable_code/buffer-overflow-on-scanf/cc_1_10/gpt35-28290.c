//FormAI DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_SIZE 100
#define NAME_SIZE 50
#define EMAIL_SIZE 100

typedef struct {
    char name[NAME_SIZE];
    char email[EMAIL_SIZE];
} Contact;

typedef struct {
    int num_contacts;
    Contact list[LIST_SIZE];
} MailingList;

void display_menu();
void add_contact(MailingList* list);
void delete_contact(MailingList* list);
void search_contacts(MailingList* list, char* search_term);
void print_contact(Contact contact);

int main() {
    MailingList list = {0};

    while (1) {
        display_menu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_contact(&list);
                break;
            case 2:
                delete_contact(&list);
                break;
            case 3: {
                char search_term[NAME_SIZE];
                printf("Enter name or email to search for: ");
                fgets(search_term, NAME_SIZE, stdin);
                strtok(search_term, "\n");  // Remove newline character
                search_contacts(&list, search_term);
                break;
            }
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

void display_menu() {
    printf("--- Mailing List Manager ---\n");
    printf("1. Add contact\n");
    printf("2. Delete contact\n");
    printf("3. Search contacts\n");
    printf("4. Exit\n");
}

void add_contact(MailingList* list) {
    if (list->num_contacts >= LIST_SIZE) {
        printf("Error: Maximum number of contacts reached.\n");
        return;
    }

    Contact contact;
    printf("Enter name: ");
    fgets(contact.name, NAME_SIZE, stdin);
    strtok(contact.name, "\n");  // Remove newline character
    printf("Enter email: ");
    fgets(contact.email, EMAIL_SIZE, stdin);
    strtok(contact.email, "\n");  // Remove newline character

    list->list[list->num_contacts] = contact;
    list->num_contacts++;

    printf("Contact added.\n");
}

void delete_contact(MailingList* list) {
    char search_term[NAME_SIZE];
    printf("Enter name or email of contact to delete: ");
    fgets(search_term, NAME_SIZE, stdin);
    strtok(search_term, "\n");  // Remove newline character

    int found = 0;
    for (int i = 0; i < list->num_contacts; i++) {
        Contact contact = list->list[i];
        if (strcmp(contact.name, search_term) == 0 || strcmp(contact.email, search_term) == 0) {
            found = 1;
            printf("Are you sure you want to delete the following contact:\n");
            print_contact(contact);

            char confirm[3];
            printf("Enter Y or N: ");
            fgets(confirm, 3, stdin);
            strtok(confirm, "\n");  // Remove newline character

            if (strcmp(confirm, "Y") == 0) {
                for (int j = i; j < list->num_contacts - 1; j++) {
                    list->list[j] = list->list[j+1];
                }
                list->num_contacts--;
                printf("Contact deleted.\n");
            } else {
                printf("Contact not deleted.\n");
            }

            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void search_contacts(MailingList* list, char* search_term) {
    int found = 0;
    for (int i = 0; i < list->num_contacts; i++) {
        Contact contact = list->list[i];
        if (strstr(contact.name, search_term) != NULL || strstr(contact.email, search_term) != NULL) {
            found = 1;
            print_contact(contact);
        }
    }

    if (!found) {
        printf("No contacts found.\n");
    }
}

void print_contact(Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Email: %s\n", contact.email);
    printf("---------------------------\n");
}