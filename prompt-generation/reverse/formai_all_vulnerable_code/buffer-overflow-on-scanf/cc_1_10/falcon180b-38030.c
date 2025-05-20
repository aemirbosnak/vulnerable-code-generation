//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15

typedef struct contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;

int main() {
    int num_contacts = 0;
    Contact contacts[MAX_CONTACTS];

    char choice;
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. View All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if (num_contacts >= MAX_CONTACTS) {
                    printf("Sorry, phone book is full.\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", contacts[num_contacts].name);
                    printf("Enter phone number: ");
                    scanf("%s", contacts[num_contacts].phone);
                    num_contacts++;
                    printf("Contact added successfully.\n");
                }
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", contacts[0].name);
                int i;
                for (i = 0; i < num_contacts; i++) {
                    if (strcmp(contacts[i].name, contacts[0].name) == 0) {
                        printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
                    }
                }
                break;
            case '3':
                printf("Phone Book:\n");
                int j;
                for (j = 0; j < num_contacts; j++) {
                    printf("Name: %s\nPhone: %s\n", contacts[j].name, contacts[j].phone);
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}