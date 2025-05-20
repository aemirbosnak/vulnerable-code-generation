//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: shocked
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

Contact phone_book[MAX_CONTACTS];
int contact_count = 0;

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Oh no! The phone book is full! No more contacts can be added!\n");
        return;
    }
    
    Contact new_contact;
    printf("Enter the name of the new contact: ");
    scanf(" %[^\n]", new_contact.name);
    printf("Enter the phone number of %s: ", new_contact.name);
    scanf("%s", new_contact.phone);
    
    phone_book[contact_count++] = new_contact;
    printf("Contact %s added with phone number %s!\n", new_contact.name, new_contact.phone);
}

void display_contacts() {
    if (contact_count == 0) {
        printf("The phone book is empty... How eerie!\n");
        return;
    }
    
    printf("Displaying all contacts:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d. %s - %s\n", i + 1, phone_book[i].name, phone_book[i].phone);
    }
}

void search_contact() {
    char search_name[NAME_LENGTH];
    printf("Enter the name of the contact to search for: ");
    scanf(" %[^\n]", search_name);
    
    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(phone_book[i].name, search_name) == 0) {
            printf("Found! %s's phone number is %s.\n", phone_book[i].name, phone_book[i].phone);
            return;
        }
    }
    
    printf("%s is not found in the phone book... Spooky!\n", search_name);
}

void delete_contact() {
    char delete_name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", delete_name);
    
    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(phone_book[i].name, delete_name) == 0) {
            for (int j = i; j < contact_count - 1; j++) {
                phone_book[j] = phone_book[j + 1];
            }
            contact_count--;
            printf("%s has been deleted from the phone book! How tragic...\n", delete_name);
            return;
        }
    }
    
    printf("%s could not be found for deletion... The horror!\n", delete_name);
}

void menu() {
    int choice;
    do {
        printf("\n=== My Spooky Phone Book ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("Exiting the phone book... Until next time!\n");
                break;
            default:
                printf("Invalid choice! That was... unexpected!\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Spooky Phone Book!\n");
    menu();
    return 0;
}