//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phonebook[MAX_CONTACTS];
int contact_count = 0;

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    fgets(phonebook[contact_count].name, NAME_LENGTH, stdin);
    phonebook[contact_count].name[strcspn(phonebook[contact_count].name, "\n")] = '\0'; // Remove newline

    printf("Enter phone number: ");
    fgets(phonebook[contact_count].phone, PHONE_LENGTH, stdin);
    phonebook[contact_count].phone[strcspn(phonebook[contact_count].phone, "\n")] = '\0'; // Remove newline

    contact_count++;
    printf("Contact added successfully!\n");
}

void view_contacts() {
    if (contact_count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Phone Book Contacts ---\n");
    for (int i = 0; i < contact_count; i++) {
        printf("Contact #%d: %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

void search_contact() {
    char search_name[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(search_name, NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; // Remove newline

    printf("\n--- Search Results for '%s' ---\n", search_name);
    int found = 0;

    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(phonebook[i].name, search_name) == 0) {
            printf("Found: %s - %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No contacts found with the name '%s'.\n", search_name);
    }
}

void delete_contact() {
    char delete_name[NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(delete_name, NAME_LENGTH, stdin);
    delete_name[strcspn(delete_name, "\n")] = '\0'; // Remove newline

    int found = 0;

    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(phonebook[i].name, delete_name) == 0) {
            found = 1;
            for (int j = i; j < contact_count - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            contact_count--;
            printf("Contact '%s' deleted successfully!\n", delete_name);
            break;
        }
    }
    if (!found) {
        printf("No contacts found with the name '%s' to delete.\n", delete_name);
    }
}

void display_menu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline left in the buffer

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("Exiting the phone book application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose between 1 and 5.\n");
        }
    }

    return 0;
}