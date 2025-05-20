//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

struct Contact {
    char name[50];
    char phoneNumber[15];
};

int main() {
    int option, numContacts = 0, i;
    struct Contact phoneBook[MAX_CONTACTS];

    printf("Welcome to the C Phone Book!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a new contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if(numContacts >= MAX_CONTACTS) {
                    printf("\nSorry, the phone book is full.\n");
                    break;
                }
                
                printf("\nEnter the name of the contact: ");
                scanf("%s", phoneBook[numContacts].name);

                printf("Enter the phone number (format: 123-456-7890): ");
                scanf("%s", phoneBook[numContacts].phoneNumber);
                numContacts++;
                printf("\nContact added successfully!\n");
                break;

            case 2:
                if(numContacts == 0) {
                    printf("\nPhone book is empty.\n");
                    break;
                }

                printf("\n%-25s %s\n", "Name", "Phone Number");

                for(i = 0; i < numContacts; i++) {
                    printf("%-25s %s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
                }

                break;

            case 3:
                if(numContacts == 0) {
                    printf("\nPhone book is empty.\n");
                    break;
                }

                char searchName[50];
                printf("\nEnter the name of the contact to search for: ");
                scanf("%s", searchName);

                for(i = 0; i < numContacts; i++) {
                    if(strcmp(searchName, phoneBook[i].name) == 0) {
                        printf("\n%-25s %s\n", "Name", "Phone Number");
                        printf("%-25s %s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
                        break;
                    }
                }

                if(i == numContacts) {
                    printf("\nContact not found.\n");
                }

                break;

            case 4:
                printf("\nThank you for using C Phone Book!\n");
                break;

            default:
                printf("\nSorry, invalid option.\n");
        }

    } while(option != 4);

    return 0;
}