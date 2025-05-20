//FormAI DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include<stdio.h>
#include<string.h>

#define MAX_CONTACTS 100 // Maximum number of contacts can be stored.

// Structure representing phone contacts.
struct Contact {
    char name[100];
    char phone[20];
};

// Function to encrypt phone number
void encrypt(char *phone) {
    int i;
    for (i = 0; phone[i] != '\0'; i++) {
        if (phone[i] >= '0' && phone[i] <= '9') {
            phone[i] = (char) (9 - phone[i] + '0');
        }
    }
}

// Function to decrypt phone number
void decrypt(char *phone) {
    int i;
    for (i = 0; phone[i] != '\0'; i++) {
        if (phone[i] >= '0' && phone[i] <= '9') {
            phone[i] = (char) (9 - phone[i] + '0');
        }
    }
}

// Function to print all contacts
void printContacts(struct Contact contacts[], int count) {
    printf("%-30s %s\n", "Name", "Phone");
    int i;
    for (i = 0; i < count; i++) {
        printf("%-30s %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS]; // Array to store contacts.
    int count = 0; // Counter to keep track of number of contacts added.

    int choice = 0;
    char name[100], phone[20];
    while (1) {
        printf("\n\n");
        printf("1. Add Contact\n");
        printf("2. Print Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter contact name: ");
                scanf("%s", name);
                printf("Enter contact phone number: ");
                scanf("%s", phone);

                encrypt(phone); // Encrypt phone number before storing in phone book.

                struct Contact newContact = {0};
                strcpy(newContact.name, name);
                strcpy(newContact.phone, phone);

                // Add the new contact to the phone book.
                contacts[count] = newContact;
                count++;

                printf("\nContact added successfully!\n");
                break;

            case 2:
                printf("\n\n");
                if (count == 0) {
                    printf("No contacts to display\n");
                } else {
                    printContacts(contacts, count);
                }
                break;

            case 3:
                // Exit the program
                return 0;

            default:
                printf("\nInvalid Choice. Try Again.");
                break;
        }
    }
}