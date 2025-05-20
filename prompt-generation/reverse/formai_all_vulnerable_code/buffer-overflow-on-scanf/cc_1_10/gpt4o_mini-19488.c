//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phonebook[MAX_ENTRIES];
int entry_count = 0;

void display_menu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
}

void add_contact() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Phonebook is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]%*c", phonebook[entry_count].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]%*c", phonebook[entry_count].phone);
    entry_count++;
    printf("Contact added!\n");
}

void view_contacts() {
    if (entry_count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\n--- Contacts ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

void search_contact() {
    char search_name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]%*c", search_name);
    int found = 0;
    
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < entry_count; i++) {
        if (strcasecmp(phonebook[i].name, search_name) == 0) {
            printf("Found: %s - %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void delete_contact() {
    char delete_name[NAME_LENGTH];
    printf("Enter the name to delete: ");
    scanf(" %[^\n]%*c", delete_name);
    int index = -1;

    for (int i = 0; i < entry_count; i++) {
        if (strcasecmp(phonebook[i].name, delete_name) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < entry_count - 1; i++) {
            phonebook[i] = phonebook[i + 1];
        }
        entry_count--;
        printf("Contact deleted!\n");
    } else {
        printf("Contact not found for deletion.\n");
    }
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
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
                printf("Exiting the phone book.\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 5);
    
    return 0;
}