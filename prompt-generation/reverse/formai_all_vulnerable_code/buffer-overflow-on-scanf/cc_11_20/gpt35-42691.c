//FormAI DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

struct PhoneBook {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

int main() {
    struct PhoneBook contactList[MAX_CONTACTS];
    int numContacts = 0; // the number of contacts in the array
    char choice;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    while (1) {
        printf("--------------C Phone Book--------------\n\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Display Contact List\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (numContacts == MAX_CONTACTS) {
                    printf("The phone book is full. Please remove some contacts before adding new ones.\n");
                    break;
                }

                printf("Enter the name of the contact: ");
                scanf("%s", name);

                printf("Enter the phone number of the contact: ");
                scanf("%s", phone);

                strcpy(contactList[numContacts].name, name);
                strcpy(contactList[numContacts].phone, phone);

                printf("%s has been added to your phone book.\n\n", contactList[numContacts].name);
                numContacts++;
                break;

            case '2':
                if (numContacts == 0) {
                    printf("The phone book is empty.\n");
                    break;
                }

                printf("Enter the name of the contact you want to remove: ");
                scanf("%s", name);

                int i;
                for (i = 0; i < numContacts; i++) {
                    if (strcmp(contactList[i].name, name) == 0) {
                        printf("%s has been removed from your phone book.\n\n", contactList[i].name);
                        numContacts--;

                        // Move the last contact in the array to the i-th position
                        strcpy(contactList[i].name, contactList[numContacts].name);
                        strcpy(contactList[i].phone, contactList[numContacts].phone);
                        break;
                    }
                }

                if (i == numContacts) {
                    printf("Contact not found.\n");
                }

                break;

            case '3':
                if (numContacts == 0) {
                    printf("The phone book is empty.\n");
                    break;
                }

                printf("Contact List:\n");

                for (int i = 0; i < numContacts; i++) {
                    printf("%s: %s\n", contactList[i].name, contactList[i].phone);
                }

                printf("\n");
                break;

            case '4':
                printf("Exiting C Phone Book.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n\n");
                break;
        }
    }

    return 0;
}