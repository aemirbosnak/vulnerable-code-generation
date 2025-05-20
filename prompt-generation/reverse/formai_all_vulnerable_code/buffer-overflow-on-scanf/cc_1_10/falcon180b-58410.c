//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    Contact phoneBook[MAX_CONTACTS];
    int numContacts = 0;
    char choice;
    int index;

    do {
        printf("\nPhone Book\n");
        printf("=============\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", phoneBook[numContacts].name);
                printf("Enter number: ");
                scanf("%s", phoneBook[numContacts].number);
                numContacts++;
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", phoneBook[numContacts - 1].name);
                index = numContacts - 1;
                while (index >= 0) {
                    if (strcmp(phoneBook[index].name, phoneBook[numContacts - 1].name) == 0) {
                        printf("Name found!\n");
                        printf("Number: %s\n", phoneBook[index].number);
                        break;
                    }
                    index--;
                }
                break;
            case '3':
                for (int i = 0; i < numContacts; i++) {
                    printf("Name: %s\n", phoneBook[i].name);
                    printf("Number: %s\n", phoneBook[i].number);
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '4');

    return 0;
}