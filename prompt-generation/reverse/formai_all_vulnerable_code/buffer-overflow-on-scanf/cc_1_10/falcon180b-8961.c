//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define MAX_NAME 50
#define MAX_SUBJECT 100

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAILS];
    char subject[MAX_SUBJECT];
} contact;

int num_contacts = 0;
contact contacts[MAX_EMAILS];

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter email: ");
    scanf("%s", contacts[num_contacts].email);

    printf("Enter subject: ");
    scanf("%s", contacts[num_contacts].subject);

    num_contacts++;
}

void remove_contact() {
    printf("Enter email to remove: ");
    scanf("%s", contacts[num_contacts - 1].email);

    num_contacts--;
}

void view_contacts() {
    printf("Name\tEmail\tSubject\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\t%s\n", contacts[i].name, contacts[i].email, contacts[i].subject);
    }
}

void send_email() {
    printf("Enter email to send: ");
    scanf("%s", contacts[num_contacts - 1].email);

    printf("Enter subject: ");
    scanf("%s", contacts[num_contacts - 1].subject);

    printf("Enter message: ");
    scanf("%s", contacts[num_contacts - 1].subject);
}

int main() {
    int choice;

    do {
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. View contacts\n");
        printf("4. Send email\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact();
            break;

        case 2:
            remove_contact();
            break;

        case 3:
            view_contacts();
            break;

        case 4:
            send_email();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}