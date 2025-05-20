//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact phonebook[MAX_CONTACTS];
int contact_count = 0;

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Oops! The phone book is FULL! No more funny names can be added!\n");
        return;
    }
    
    printf("Add a new contact: (You can choose a name that makes you laugh)\n");
    
    printf("Enter name: ");
    fgets(phonebook[contact_count].name, MAX_NAME_LENGTH, stdin);
    phonebook[contact_count].name[strcspn(phonebook[contact_count].name, "\n")] = '\0'; // Strip newline

    printf("Enter phone number: ");
    fgets(phonebook[contact_count].phone, MAX_PHONE_LENGTH, stdin);
    phonebook[contact_count].phone[strcspn(phonebook[contact_count].phone, "\n")] = '\0'; // Strip newline
    
    contact_count++;
    
    printf("Contact added successfully! You now have %d contact(s) to play around with!\n", contact_count);
}

void display_contacts() {
    if (contact_count == 0) {
        printf("The phone book is empty! It’s as empty as my wallet!\n");
        return;
    }

    printf("Here are your hilarious contacts:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

void search_contact() {
    char query[MAX_NAME_LENGTH];
    printf("Whom do you want to find in this thrilling phonebook adventure? Type their name:\n");
    fgets(query, MAX_NAME_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // Strip newline

    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(phonebook[i].name, query) == 0) {
            printf("Found you a contact! %s - %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }
    printf("No contact with the name %s was found! It must be hiding!\n", query);
}

void delete_contact() {
    if (contact_count == 0) {
        printf("The phone book is still empty! No contacts to erase!\n");
        return;
    }

    display_contacts();
    int index;
    
    printf("Choose the number of the contact you wish to send to the great phonebook in the sky:\n");
    scanf("%d", &index);
    getchar(); // To consume newline after scanf
    if (index < 1 || index > contact_count) {
        printf("Are you sure that's a valid number? Please try again!\n");
        return;
    }
    
    for (int i = index - 1; i < contact_count - 1; i++) {
        phonebook[i] = phonebook[i + 1];
    }
    contact_count--;
    
    printf("Be gone! Contact %d is now surely up in phonebook heaven!\n", index);
}

void display_menu() {
    printf("\nWelcome to Larry's Laughing Phone Book! Please choose an option:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Choose wisely (1-5): ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To consume newline after scanf

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
                printf("Exiting the Phone Book with a smile! Bye-bye!\n");
                exit(0);
            default:
                printf("That's an invalid choice! Maybe drink some coffee and try again?\n");
        }
    }

    return 0;
}