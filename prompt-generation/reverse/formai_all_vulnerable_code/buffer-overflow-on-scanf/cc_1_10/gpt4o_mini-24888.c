//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void add_contact(Contact contacts[], int *count);
void view_contacts(const Contact contacts[], int count);
void search_contact(const Contact contacts[], int count);
void delete_contact(Contact contacts[], int *count);
void display_menu();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf

        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                view_contacts(contacts, count);
                break;
            case 3:
                search_contact(contacts, count);
                break;
            case 4:
                delete_contact(contacts, &count);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n--- Contact Management System ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void add_contact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full! Cannot add more contacts.\n");
        return;
    }

    printf("Enter the contact's name: ");
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = '\0';  // Remove newline

    printf("Enter the contact's phone number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = '\0';  // Remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void view_contacts(const Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void search_contact(const Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available to search.\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            printf("Found contact: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact(Contact contacts[], int *count) {
    if (*count == 0) {
        printf("No contacts available to delete.\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];  // Shift contacts left
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found.\n");
}