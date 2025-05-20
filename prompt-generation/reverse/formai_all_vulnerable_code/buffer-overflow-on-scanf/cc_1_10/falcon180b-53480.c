//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
} contact;

int main() {
    contact phoneBook[MAX_ENTRIES];
    int numEntries = 0;

    char choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numEntries == MAX_ENTRIES) {
                    printf("Phone book is full. Cannot add more contacts.\n");
                }
                else {
                    printf("Enter first name: ");
                    scanf("%s", phoneBook[numEntries].firstName);
                    printf("Enter last name: ");
                    scanf("%s", phoneBook[numEntries].lastName);
                    printf("Enter phone number: ");
                    scanf("%s", phoneBook[numEntries].phoneNumber);
                    numEntries++;
                    printf("Contact added successfully.\n");
                }
                break;

            case '2':
                printf("Enter first name to search: ");
                scanf("%s", phoneBook[0].firstName);
                for(int i=1; i<=numEntries; i++) {
                    if(strcmp(phoneBook[i].firstName, phoneBook[0].firstName) == 0) {
                        printf("\nContact found:\n");
                        printf("First Name: %s\n", phoneBook[i].firstName);
                        printf("Last Name: %s\n", phoneBook[i].lastName);
                        printf("Phone Number: %s\n", phoneBook[i].phoneNumber);
                    }
                }
                break;

            case '3':
                printf("Displaying all contacts:\n");
                for(int i=0; i<numEntries; i++) {
                    printf("\n");
                    printf("First Name: %s\n", phoneBook[i].firstName);
                    printf("Last Name: %s\n", phoneBook[i].lastName);
                    printf("Phone Number: %s\n", phoneBook[i].phoneNumber);
                }
                break;

            case '4':
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= '4');

    return 0;
}