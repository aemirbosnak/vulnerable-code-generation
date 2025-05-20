//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

int main() {
    int choice, num_contacts = 0;
    contact *contacts = NULL;

    printf("Welcome to the Mailing List Manager!\n\n");
    printf("1. Add contact\n2. Remove contact\n3. View contacts\n4. Exit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                break;

            case 2:
                printf("Enter email to remove: ");
                scanf("%s", contacts[num_contacts-1].email);
                num_contacts--;
                break;

            case 3:
                printf("\nContacts:\n");
                for(int i=0; i<num_contacts; i++) {
                    printf("%s - %s\n", contacts[i].name, contacts[i].email);
                }
                break;

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}