//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[20];
} Contact;

int main() {
    int option;
    int numContacts = 0;
    Contact *phonebook = malloc(sizeof(Contact));
    printf("Hello there! Welcome to the Curious Phone Book.\n");

    do {
        printf("\nWhat would you like to do? Choose an option below:\n");
        printf("1. Add a Contact\n");
        printf("2. Search for a Contact\n");
        printf("3. List all Contacts\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1: {
                Contact newContact;
                printf("\nEnter the contact name: ");
                scanf("%s", newContact.name);
                printf("Enter the contact number: ");
                scanf("%s", newContact.number);

                numContacts++;
                phonebook = realloc(phonebook, numContacts * sizeof(Contact));
                phonebook[numContacts - 1] = newContact;

                printf("\nContact added successfully!\n");
                break;
            }
            case 2: {
                char searchName[50];
                int found = 0;

                printf("\nEnter the name of the contact you want to search for: ");
                scanf("%s", searchName);

                for(int i = 0; i < numContacts; i++) {
                    if(strcmp(phonebook[i].name, searchName) == 0) {
                        printf("\n%s's phone number is: %s\n", phonebook[i].name, phonebook[i].number);
                        found = 1;
                        break;
                    }
                }

                if(!found)
                    printf("\nContact not found.\n");

                break;
            }
            case 3: {
                if(numContacts == 0) {
                    printf("\nYour phonebook is currently empty.\n");
                    break;
                }

                printf("\nHere are all your contacts:\n");

                for(int i = 0; i < numContacts; i++) {
                    printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
                }

                break;
            }
            case 4: {
                printf("\nThank you for using Curious Phone Book! Goodbye.\n");
                break;
            }
            default: {
                printf("\nInvalid option. Please try again.\n");
                break;
            }
        }
    } while(option != 4);

    free(phonebook);
    return 0;
}