//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    Contact phonebook[MAX_CONTACTS];
    int numContacts = 0;
    char choice;

    do {
        printf("Phone Book\n");
        printf("1. Add Contact\n2. Search Contact\n3. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", phonebook[numContacts].name);
                printf("Enter number: ");
                scanf("%s", phonebook[numContacts].number);
                numContacts++;
                break;
            case '2':
                printf("Enter name to search: ");
                char searchName[MAX_NAME_LENGTH];
                scanf("%s", searchName);
                int found = 0;
                for(int i = 0; i < numContacts; i++) {
                    if(strcmp(phonebook[i].name, searchName) == 0) {
                        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    printf("Contact not found.\n");
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '3');

    return 0;
}