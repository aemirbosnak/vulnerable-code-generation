//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECTS 100
#define MAX_BODY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODY];
} message;

int main() {
    int choice = 0;
    contact contacts[100];
    message messages[100];
    int num_contacts = 0, num_messages = 0;

    while (choice!= 4) {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Add message\n");
        printf("3. Send message\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", contacts[num_contacts].name);
            printf("Enter email: ");
            scanf("%s", contacts[num_contacts].email);
            num_contacts++;
            break;
        case 2:
            printf("Enter subject: ");
            scanf("%s", messages[num_messages].subject);
            printf("Enter body: ");
            fgets(messages[num_messages].body, MAX_BODY, stdin);
            num_messages++;
            break;
        case 3:
            printf("Enter recipient email: ");
            scanf("%s", messages[0].body);
            system("mail -s 'Subject' 'Recipient' < message.txt");
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}