//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    char choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_contacts >= MAX_CONTACTS) {
                    printf("Contact list is full.\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", contacts[num_contacts].name);
                    printf("Enter number: ");
                    scanf("%s", contacts[num_contacts].number);
                    num_contacts++;
                    printf("Contact added successfully.\n");
                }
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", contacts[0].name);
                for(int i=1; i<=num_contacts; i++) {
                    if(strcmp(contacts[i].name, contacts[0].name) == 0) {
                        printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
                    }
                }
                break;
            case '3':
                for(int i=0; i<num_contacts; i++) {
                    printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '4');

    return 0;
}