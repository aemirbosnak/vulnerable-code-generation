//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECTS 100
#define MAX_BODY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODY];
} message;

int main() {
    int choice;
    contact contacts[100];
    int num_contacts = 0;
    message messages[100];
    int num_messages = 0;

    do {
        system("clear");
        printf("Mailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Send message\n");
        printf("4. View contacts\n");
        printf("5. Exit\n");
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
                printf("Enter subject: ");
                scanf("%s", messages[num_messages].subject);
                printf("Enter message body: ");
                scanf("%s", messages[num_messages].body);
                num_messages++;
                break;
            case 4:
                printf("Contacts:\n");
                for(int i = 0; i < num_contacts; i++) {
                    printf("%s: %s\n", contacts[i].name, contacts[i].email);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}