//FormAI DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char name[50];
    char number[20];
    char address[100];
    char occupation[50];
    int age;
} Contact;

int main() {
    Contact contacts[100];
    int numContacts = 0;

    while (1) {
        int choice;
        printf("\nWelcome to the Medieval Phone Book!\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Contact newContact;
                printf("\nEnter contact name: ");
                scanf("%s", newContact.name);
                printf("Enter contact number: ");
                scanf("%s", newContact.number);
                printf("Enter contact address: ");
                scanf("%s", newContact.address);
                printf("Enter contact occupation: ");
                scanf("%s", newContact.occupation);
                printf("Enter contact age: ");
                scanf("%d", &newContact.age);
                contacts[numContacts++] = newContact;
                printf("\nContact added to the Medieval Phone Book!\n");
                break;
            }
            case 2: {
                if (numContacts == 0) {
                    printf("\nThe Medieval Phone Book is empty!\n");
                } else {
                    printf("\nMedieval Phone Book\n");
                    printf("-------------------\n");
                    for (int i = 0; i < numContacts; i++) {
                        printf("Name: %s\n", contacts[i].name);
                        printf("Number: %s\n", contacts[i].number);
                        printf("Address: %s\n", contacts[i].address);
                        printf("Occupation: %s\n", contacts[i].occupation);
                        printf("Age: %d\n", contacts[i].age);
                        printf("-------------------\n");
                    }
                }
                break;
            }
            case 3: {
                if (numContacts == 0) {
                    printf("\nThe Medieval Phone Book is empty!\n");
                } else {
                    char name[50];
                    printf("\nEnter name of contact to delete: ");
                    scanf("%s", name);
                    int found = 0;
                    for (int i = 0; i < numContacts; i++) {
                        if (strcmp(name, contacts[i].name) == 0) {
                            for (int j = i; j < numContacts - 1; j++) {
                                contacts[j] = contacts[j+1];
                            }
                            numContacts--;
                            found = 1;
                            printf("\nContact deleted from the Medieval Phone Book!\n");
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nContact not found in the Medieval Phone Book!\n");
                    }
                }
                break;
            }
            case 4: {
                printf("\nFarewell, kind sir or madam!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice! Try again!\n");
                break;
            }
        }
    }

    return 0;
}