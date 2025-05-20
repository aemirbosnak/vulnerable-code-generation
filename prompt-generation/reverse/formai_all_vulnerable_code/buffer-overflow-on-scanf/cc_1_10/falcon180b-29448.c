//Falcon-180B DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
} Contact;

int main() {
    Contact contacts[10]; // store up to 10 contacts
    int num_contacts = 0; // keep track of how many contacts are stored
    char input[MAX_EMAIL_LENGTH]; // buffer for user input
    char choice; // user's choice of action

    do {
        printf("Happy Email Client\n");
        printf("===================\n");
        printf("Enter a command:\n");
        printf("A - Add contact\n");
        printf("S - Send email\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", contacts[num_contacts].email);
                printf("Enter subject: ");
                scanf("%s", contacts[num_contacts].subject);
                num_contacts++;
                break;
            case 'S':
                printf("Enter recipient's name: ");
                scanf("%s", input);
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(input, contacts[i].name) == 0) {
                        printf("Sending email to %s...\n", contacts[i].email);
                        break;
                    }
                }
                break;
            case 'Q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid command.\n");
        }
    } while(choice!= 'Q');

    return 0;
}