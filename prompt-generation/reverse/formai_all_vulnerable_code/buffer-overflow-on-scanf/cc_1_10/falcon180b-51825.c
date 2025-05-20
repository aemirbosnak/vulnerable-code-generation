//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int main() {
    int choice;
    int num_contacts = 0;
    contact contacts[100];

    printf("Welcome to the mailing list manager!\n");
    printf("Please choose an option:\n");
    printf("1. Add a contact\n");
    printf("2. Search for a contact\n");
    printf("3. Print the list of contacts\n");
    printf("4. Quit\n");

    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the name of the contact: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter the email of the contact: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                break;
            case 2:
                printf("Enter the name of the contact to search for: ");
                scanf("%s", contacts[num_contacts].name);
                num_contacts++;
                break;
            case 3:
                for(int i = 0; i < num_contacts; i++) {
                    printf("%s - %s\n", contacts[i].name, contacts[i].email);
                }
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}