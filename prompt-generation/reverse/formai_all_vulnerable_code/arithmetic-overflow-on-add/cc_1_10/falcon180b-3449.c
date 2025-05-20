//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact recipient;
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} email;

int main() {
    int choice, num_contacts, i, j;
    contact contacts[100];
    email emails[100];

    printf("Welcome to the Happy Mailing List Manager!\n");
    printf("Please choose an option:\n");
    printf("1. Add contact\n");
    printf("2. Remove contact\n");
    printf("3. Send email\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
        case 1:
            printf("Enter name (max %d characters): ", MAX_NAME_LENGTH - 1);
            scanf("%s", contacts[num_contacts].name);
            printf("Enter email (max %d characters): ", MAX_EMAIL_LENGTH - 1);
            scanf("%s", contacts[num_contacts].email);
            num_contacts++;
            break;
        case 2:
            printf("Enter name of contact to remove: ");
            scanf("%s", contacts[0].name);
            for (i = 0; i < num_contacts - 1; i++) {
                if (strcmp(contacts[i].name, contacts[0].name) == 0) {
                    for (j = i; j < num_contacts - 1; j++) {
                        strcpy(contacts[j].name, contacts[j + 1].name);
                        strcpy(contacts[j].email, contacts[j + 1].email);
                    }
                    num_contacts--;
                    break;
                }
            }
            break;
        case 3:
            printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
            scanf("%s", emails[0].subject);
            printf("Enter message (max %d characters): ", MAX_MESSAGE_LENGTH - 1);
            fgets(emails[0].message, MAX_MESSAGE_LENGTH, stdin);
            printf("Enter recipient name: ");
            scanf("%s", emails[0].recipient.name);
            for (i = 0; i < num_contacts; i++) {
                if (strcmp(emails[0].recipient.name, contacts[i].name) == 0) {
                    strcpy(emails[0].recipient.email, contacts[i].email);
                    break;
                }
            }
            printf("Email sent to %s (%s)\n", emails[0].recipient.name, emails[0].recipient.email);
            break;
        default:
            printf("Invalid choice\n");
        }
        choice = 0;
    }

    return 0;
}