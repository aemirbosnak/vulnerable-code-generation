//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[30];
    char phone_num[15];
};

void add_contact(struct contact**, int*);
void view_contacts(struct contact*, int);
void delete_contact(struct contact**, int*);
void search_contact(struct contact*, int);

int main() {
    struct contact* contacts = NULL;
    int num_contacts = 0;
    int choice;

    printf("Welcome to the C Phone Book\n");

    do {
        printf("\nMain Menu\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contacts\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_contact(&contacts, &num_contacts);
                break;
            case 2:
                view_contacts(contacts, num_contacts);
                break;
            case 3:
                delete_contact(&contacts, &num_contacts);
                break;
            case 4:
                search_contact(contacts, num_contacts);
                break;
            case 5:
                printf("Exiting C Phone Book... Goodbye!\n");
                break;
            default:
                printf("Invalid choice... please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_contact(struct contact** contacts_ptr, int* num_contacts_ptr) {
    struct contact new_contact;

    printf("\nAdd Contact\n");

    printf("Name: ");
    fgets(new_contact.name, sizeof(new_contact.name), stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = '\0';

    printf("Phone Number (format xxx-xxx-xxxx): ");
    scanf("%s", new_contact.phone_num);
    getchar();

    (*num_contacts_ptr)++;
    *contacts_ptr = (struct contact*) realloc(*contacts_ptr, *num_contacts_ptr * sizeof(struct contact));
    (*contacts_ptr)[*num_contacts_ptr - 1] = new_contact;

    printf("Contact added successfully!\n");
}

void view_contacts(struct contact* contacts, int num_contacts) {
    if (num_contacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("\nView Contacts\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone Number: %s\n", contacts[i].phone_num);
        printf("\n");
    }
}

void delete_contact(struct contact** contacts_ptr, int* num_contacts_ptr) {
    char name[30];
    int index = -1;

    if (*num_contacts_ptr == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("\nDelete Contact\n");

    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < *num_contacts_ptr; i++) {
        if (strcmp(name, (*contacts_ptr)[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int i = index; i < *num_contacts_ptr - 1; i++) {
        (*contacts_ptr)[i] = (*contacts_ptr)[i + 1];
    }

    (*num_contacts_ptr)--;
    *contacts_ptr = (struct contact*) realloc(*contacts_ptr, *num_contacts_ptr * sizeof(struct contact));

    printf("Contact deleted successfully!\n");
}

void search_contact(struct contact* contacts, int num_contacts) {
    char search_term[30];
    int num_results = 0;

    if (num_contacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("\nSearch Contacts\n");

    printf("Enter search term: ");
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = '\0';

    for (int i = 0; i < num_contacts; i++) {
        if (strstr(contacts[i].name, search_term) != NULL ||
                strstr(contacts[i].phone_num, search_term) != NULL) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phone_num);
            printf("\n");
            num_results++;
        }
    }

    if (num_results == 0) {
        printf("No results found.\n");
    } else {
        printf("Found %d matches.\n", num_results);
    }
}