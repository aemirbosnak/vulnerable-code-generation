//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} contact;

int main() {

    int choice, i;
    contact contacts[100];
    int num_contacts = 0;

    printf("Welcome to the Phone Book!\n");

    while(1) {
        printf("\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. View all contacts\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter number: ");
                scanf("%s", contacts[num_contacts].number);
                num_contacts++;
                printf("\nContact added successfully!\n");
                break;

            case 2:
                printf("Enter name to search: ");
                scanf("%s", contacts[0].name);

                for(i=0; i<num_contacts; i++) {
                    if(strcmp(contacts[i].name, contacts[0].name) == 0) {
                        printf("\nName: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
                    }
                }
                break;

            case 3:
                printf("\nAll contacts:\n");
                for(i=0; i<num_contacts; i++) {
                    printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
                }
                break;

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}