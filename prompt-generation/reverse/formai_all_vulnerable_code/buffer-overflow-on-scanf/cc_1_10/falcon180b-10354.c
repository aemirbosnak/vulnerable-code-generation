//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

int main() {
    Contact phoneBook[MAX_CONTACTS];
    int numContacts = 0;
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
    char choice;
    int i;

    printf("Welcome to the Phone Book!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your phone number: ");
    scanf("%s", number);
    strcpy(phoneBook[numContacts].name, name);
    strcpy(phoneBook[numContacts].number, number);
    numContacts++;

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("a) Add a contact\n");
        printf("b) Search for a contact\n");
        printf("c) Quit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                if(numContacts >= MAX_CONTACTS) {
                    printf("Sorry, phone book is full.\n");
                } else {
                    printf("Please enter your name: ");
                    scanf("%s", name);
                    printf("Please enter your phone number: ");
                    scanf("%s", number);
                    strcpy(phoneBook[numContacts].name, name);
                    strcpy(phoneBook[numContacts].number, number);
                    numContacts++;
                    printf("Contact added successfully!\n");
                }
                break;
            case 'b':
                printf("Please enter the name you would like to search for: ");
                scanf("%s", name);
                for(i=0; i<numContacts; i++) {
                    if(strcmp(phoneBook[i].name, name) == 0) {
                        printf("Name: %s\n", phoneBook[i].name);
                        printf("Number: %s\n", phoneBook[i].number);
                    }
                }
                break;
            case 'c':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}