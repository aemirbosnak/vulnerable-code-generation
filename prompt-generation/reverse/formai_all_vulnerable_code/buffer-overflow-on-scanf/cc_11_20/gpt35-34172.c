//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 1000

typedef struct {
    char name[50];
    int age;
    char email[100];
} Person;

typedef struct {
    char subject[100];
    char message[500];
} Email;

int main() {
    Person contacts[MAX_EMAILS];
    Email emails[MAX_EMAILS];
    int numContacts = 0, numEmails = 0;
    int option;

    do {
        printf("Select an option:\n");
        printf("1. Add a contact\n");
        printf("2. List all contacts\n");
        printf("3. Add an email\n");
        printf("4. List all emails\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                if (numContacts >= MAX_EMAILS) {
                    printf("Sorry, you have reached the maximum number of contacts allowed.\n");
                } else {
                    Person newContact;

                    printf("Enter the name of the new contact: ");
                    scanf("%s", newContact.name);

                    printf("Enter the age of the new contact: ");
                    scanf("%d", &newContact.age);

                    printf("Enter the email of the new contact: ");
                    scanf("%s", newContact.email);

                    contacts[numContacts] = newContact;
                    numContacts++;

                    printf("New contact added!\n");
                }
                break;
            }
            case 2: {
                if (numContacts == 0) {
                    printf("Sorry, there are no contacts to display.\n");
                } else {
                    printf("Contacts:\n");
                    for (int i = 0; i < numContacts; i++) {
                        printf("%d. %s\t%d\t%s\n", i+1, contacts[i].name, contacts[i].age, contacts[i].email);
                    }
                }
                break;
            }
            case 3: {
                if (numEmails >= MAX_EMAILS) {
                    printf("Sorry, you have reached the maximum number of emails allowed.\n");
                } else {
                    Email newEmail;

                    printf("Enter the subject of the new email: ");
                    scanf("%s", newEmail.subject);

                    printf("Enter the message of the new email: ");
                    scanf("%s", newEmail.message);

                    emails[numEmails] = newEmail;
                    numEmails++;

                    printf("New email added!\n");
                }
                break;
            }
            case 4: {
                if (numEmails == 0) {
                    printf("Sorry, there are no emails to display.\n");
                } else {
                    printf("Emails:\n");
                    for (int i = 0; i < numEmails; i++) {
                        printf("%d. Subject: %s\tMessage: %s\n", i+1, emails[i].subject, emails[i].message);
                    }
                }
                break;
            }
            case 5: {
                printf("Exiting the program...\n");
                break;
            }
            default: {
                printf("Sorry, invalid option. Please select again.\n");
                break;
            }
        }
    } while (option != 5);

    return 0;
}