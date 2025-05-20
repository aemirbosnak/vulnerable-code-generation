//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ada Lovelace Email Client

typedef struct {
    char *name;
    char *email;
} contact;

int main() {
    int choice;
    char input[100];
    contact contacts[100];
    int num_contacts = 0;

    // Welcome message
    printf("Welcome to the Ada Lovelace Email Client!\n");

    // Menu loop
    while(1) {
        printf("\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. Send an email\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the contact: ");
                scanf("%s", input);
                printf("Enter the email of the contact: ");
                scanf("%s", input);
                contacts[num_contacts].name = strdup(input);
                contacts[num_contacts].email = strdup(input);
                num_contacts++;
                break;
            case 2:
                printf("Enter the name of the contact to remove: ");
                scanf("%s", input);
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(contacts[i].name, input) == 0) {
                        free(contacts[i].name);
                        free(contacts[i].email);
                        contacts[i] = contacts[num_contacts-1];
                        num_contacts--;
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter the name of the contact to send an email to: ");
                scanf("%s", input);
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(contacts[i].name, input) == 0) {
                        printf("Enter the subject of the email: ");
                        scanf("%s", input);
                        printf("Enter the body of the email: ");
                        scanf("%s", input);
                        printf("Email sent to %s!\n", contacts[i].email);
                        break;
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}