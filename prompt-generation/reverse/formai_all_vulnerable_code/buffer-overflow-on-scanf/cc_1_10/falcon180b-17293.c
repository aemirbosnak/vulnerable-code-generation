//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 5000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
} message;

int main() {
    contact contacts[100];
    int num_contacts = 0;
    message messages[100];
    int num_messages = 0;

    char choice;
    while(1) {
        printf("\nOptions:\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Send message\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                break;

            case '2':
                printf("Enter email to remove: ");
                scanf("%s", contacts[0].email);
                for(int i=0; i<num_contacts-1; i++) {
                    strcpy(contacts[i].email, contacts[i+1].email);
                    strcpy(contacts[i].name, contacts[i+1].name);
                }
                num_contacts--;
                break;

            case '3':
                printf("Enter subject: ");
                scanf("%s", messages[num_messages].subject);
                printf("Enter message: ");
                scanf("%s", messages[num_messages].message);
                num_messages++;
                break;

            case '4':
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}