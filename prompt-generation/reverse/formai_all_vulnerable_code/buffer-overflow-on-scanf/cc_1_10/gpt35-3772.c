//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Define a struct to hold each email address and name
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Define a struct to hold the list of email addresses
typedef struct {
    int num_contacts;
    Contact contacts[MAX_EMAILS];
} MailingList;

// Add a new contact to the mailing list
void add_contact(MailingList* list, char* name, char* email) {
    if (list->num_contacts < MAX_EMAILS) {
        Contact new_contact;
        strcpy(new_contact.name, name);
        strcpy(new_contact.email, email);
        list->contacts[list->num_contacts++] = new_contact;
    } else {
        printf("Mailing list is full!\n");
    }
}

// Print the entire mailing list
void print_list(MailingList list) {
    printf("Mailing List:\n");
    printf("--------------\n");

    for (int i = 0; i < list.num_contacts; i++) {
        printf("%s - %s\n", list.contacts[i].name, list.contacts[i].email);
    }
    printf("\n");
}

// Remove a contact from the mailing list by name
void remove_contact(MailingList* list, char* name) {
    for (int i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            for (int j = i+1; j < list->num_contacts; j++) {
                list->contacts[j-1] = list->contacts[j];
            }
            list->num_contacts--;
            printf("%s has been removed from the mailing list.\n", name);
            return;
        }
    }
    printf("%s not found in the mailing list.\n", name);
}

// Save the mailing list to a file
void save_list(MailingList list, char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < list.num_contacts; i++) {
        fprintf(fp, "%s,%s\n", list.contacts[i].name, list.contacts[i].email);
    }

    fclose(fp);
    printf("Mailing list saved to %s!\n", filename);
}

// Load the mailing list from a file
void load_list(MailingList* list, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char buffer[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2]; // +2 for the comma and newline characters

    while (fgets(buffer, MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2, fp) != NULL) {
        char* name = strtok(buffer, ",");
        char* email = strtok(NULL, "\n");
        add_contact(list, name, email);
    }

    fclose(fp);
    printf("%d contacts loaded from %s!\n", list->num_contacts, filename);
}

int main() {
    MailingList list;
    list.num_contacts = 0;

    char choice;
    do {
        printf("Enter choice:\n");
        printf("1. Add contact\n");
        printf("2. Print list\n");
        printf("3. Remove contact\n");
        printf("4. Save list\n");
        printf("5. Load list\n");
        printf("Q. Quit\n");

        scanf(" %c", &choice);

        switch (choice) {
        case '1': {
            char name[MAX_NAME_LENGTH];
            char email[MAX_EMAIL_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_contact(&list, name, email);
            break;
        }
        case '2':
            print_list(list);
            break;
        case '3': {
            char name[MAX_NAME_LENGTH];
            printf("Enter name to remove: ");
            scanf("%s", name);
            remove_contact(&list, name);
            break;
        }
        case '4': {
            char filename[MAX_NAME_LENGTH];
            printf("Enter filename to save to: ");
            scanf("%s", filename);
            save_list(list, filename);
            break;
        }
        case '5': {
            char filename[MAX_NAME_LENGTH];
            printf("Enter filename to load from: ");
            scanf("%s", filename);
            load_list(&list, filename);
            break;
        }
        case 'Q':
        case 'q':
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice, try again.\n");
            break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}