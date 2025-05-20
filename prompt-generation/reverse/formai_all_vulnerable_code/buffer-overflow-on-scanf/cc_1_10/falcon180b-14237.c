//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char phone[15];
} contact;

int main() {
    int choice, i;
    contact contacts[100];
    int num_contacts = 0;

    printf("Welcome to the Phone Book!\n");
    printf("=========================\n");

    while(1) {
        printf("Please choose an option:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter phone number: ");
                scanf("%s", contacts[num_contacts].phone);
                num_contacts++;
                printf("Contact added successfully!\n");
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", contacts[num_contacts].name);
                for(i=0; i<num_contacts; i++) {
                    if(strcmp(contacts[i].name, contacts[num_contacts].name) == 0) {
                        printf("Name: %s\nPhone number: %s\n", contacts[i].name, contacts[i].phone);
                    }
                }
                break;
            case 3:
                printf("All contacts:\n");
                for(i=0; i<num_contacts; i++) {
                    printf("Name: %s\nPhone number: %s\n", contacts[i].name, contacts[i].phone);
                }
                break;
            case 4:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}