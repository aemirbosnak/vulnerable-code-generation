//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int size;
} PhoneBook;

void initialize_phonebook(PhoneBook* pb) {
    pb->size = 0;
}

void add_contact(PhoneBook* pb, const char* name, const char* phone, const char* email) {
    if (pb->size < MAX_CONTACTS) {
        strncpy(pb->contacts[pb->size].name, name, NAME_LENGTH);
        strncpy(pb->contacts[pb->size].phone, phone, PHONE_LENGTH);
        strncpy(pb->contacts[pb->size].email, email, EMAIL_LENGTH);
        pb->size++;
        printf("Contact added: %s\n", name);
    } else {
        printf("Phone book is full, cannot add more contacts.\n");
    }
}

void display_contacts(const PhoneBook* pb) {
    if (pb->size == 0) {
        printf("No contacts found in the phone book.\n");
        return;
    }
    
    printf("\nContacts in Phone Book:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", pb->contacts[i].name);
        printf("Phone: %s\n", pb->contacts[i].phone);
        printf("Email: %s\n\n", pb->contacts[i].email);
    }
}

void search_contact(const PhoneBook* pb, const char* name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("\nContact found:\n");
            printf("Name: %s\n", pb->contacts[i].name);
            printf("Phone: %s\n", pb->contacts[i].phone);
            printf("Email: %s\n\n", pb->contacts[i].email);
            return;
        }
    }
    printf("Contact with name '%s' not found.\n", name);
}

void delete_contact(PhoneBook* pb, const char* name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->size - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->size--;
            printf("Contact '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("Contact with name '%s' not found.\n", name);
}

void update_contact(PhoneBook* pb, const char* name, const char* phone, const char* email) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            strncpy(pb->contacts[i].phone, phone, PHONE_LENGTH);
            strncpy(pb->contacts[i].email, email, EMAIL_LENGTH);
            printf("Contact '%s' updated successfully.\n", name);
            return;
        }
    }
    printf("Contact with name '%s' not found.\n", name);
}

int main() {
    PhoneBook pb;
    initialize_phonebook(&pb);
    
    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Update Contact\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter phone number: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0; // remove newline
                printf("Enter email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // remove newline
                add_contact(&pb, name, phone, email);
                break;

            case 2:
                display_contacts(&pb);
                break;

            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                search_contact(&pb, name);
                break;

            case 4:
                printf("Enter name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                delete_contact(&pb, name);
                break;

            case 5:
                printf("Enter name to update: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter new phone number: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0; // remove newline
                printf("Enter new email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // remove newline
                update_contact(&pb, name, phone, email);
                break;

            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}