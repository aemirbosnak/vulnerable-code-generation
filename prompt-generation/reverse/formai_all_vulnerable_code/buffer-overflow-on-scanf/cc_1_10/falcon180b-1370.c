//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int main() {
    int choice, num_contacts = 0;
    contact contacts[MAX_EMAILS];

    while(1) {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Search contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_contacts >= MAX_EMAILS) {
                    printf("Maximum number of contacts reached.\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", contacts[num_contacts].name);
                    printf("Enter email: ");
                    scanf("%s", contacts[num_contacts].email);
                    num_contacts++;
                }
                break;

            case 2:
                printf("Enter name of contact to remove: ");
                scanf("%s", contacts[num_contacts-1].name);
                printf("Contact removed.\n");
                num_contacts--;
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", contacts[num_contacts-1].name);
                if(strcmp(contacts[num_contacts-1].name, "")!= 0) {
                    printf("Email: %s\n", contacts[num_contacts-1].email);
                } else {
                    printf("Contact not found.\n");
                }
                break;

            case 4:
                printf("All contacts:\n");
                for(int i = 0; i < num_contacts; i++) {
                    printf("%s - %s\n", contacts[i].name, contacts[i].email);
                }
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}