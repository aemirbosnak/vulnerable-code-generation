//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_NAME 100
#define MAX_SUBJECT 200
#define MAX_BODY 1000

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAILS];
} contact;

typedef struct {
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
    time_t timestamp;
} email;

int num_contacts;
contact contacts[MAX_EMAILS];
int num_emails;
email emails[MAX_EMAILS];

void add_contact() {
    printf("Enter the name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter the email: ");
    scanf("%s", contacts[num_contacts].email);
    num_contacts++;
}

void send_email() {
    printf("Enter the subject: ");
    scanf("%s", emails[num_emails].subject);
    printf("Enter the body: ");
    scanf("%s", emails[num_emails].body);
    emails[num_emails].timestamp = time(0);
    num_emails++;
}

void view_emails() {
    int i;
    for (i = 0; i < num_emails; i++) {
        printf("%s\n%s\n%s\n%s\n", emails[i].subject, emails[i].body, ctime(&emails[i].timestamp));
    }
}

void search_contact(char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Email: %s\n", contacts[i].email);
        }
    }
}

int main() {
    int choice;
    char name[MAX_NAME];

    printf("Welcome to the Mailing List Manager!\n");
    printf("1. Add contact\n2. Send email\n3. View emails\n4. Search contact\n5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                send_email();
                break;
            case 3:
                view_emails();
                break;
            case 4:
                printf("Enter the name to search: ");
                scanf("%s", name);
                search_contact(name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}