//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    Contact phonebook[MAX_CONTACTS];
    int numContacts = 0;
    char choice;
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    int index;

    do {
        printf("Phone Book\n");
        printf("A - Add contact\n");
        printf("S - Search contact\n");
        printf("D - Delete contact\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'A':
                printf("Enter name: ");
                scanf(" %s", name);
                printf("Enter number: ");
                scanf(" %s", number);
                for(index = 0; index < numContacts; index++) {
                    if(strcmp(phonebook[index].name, name) == 0) {
                        printf("Contact already exists.\n");
                        break;
                    }
                }
                if(index == numContacts) {
                    strcpy(phonebook[numContacts].name, name);
                    strcpy(phonebook[numContacts].number, number);
                    numContacts++;
                }
                break;
            case 'S':
                printf("Enter name to search: ");
                scanf(" %s", name);
                for(index = 0; index < numContacts; index++) {
                    if(strcmp(phonebook[index].name, name) == 0) {
                        printf("Name: %s\nNumber: %s\n", phonebook[index].name, phonebook[index].number);
                    }
                }
                break;
            case 'D':
                printf("Enter name to delete: ");
                scanf(" %s", name);
                for(index = 0; index < numContacts; index++) {
                    if(strcmp(phonebook[index].name, name) == 0) {
                        memset(phonebook[index].name, '\0', MAX_NAME_LENGTH);
                        memset(phonebook[index].number, '\0', MAX_NUMBER_LENGTH);
                        numContacts--;
                        break;
                    }
                }
                break;
            case 'Q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 'Q');

    return 0;
}