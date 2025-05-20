//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_EMAIL_SIZE 100
#define MAX_NAME_SIZE 50

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} contact;

contact contacts[100];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf(" %[^\n]", contacts[num_contacts].name);
    printf("Enter email: ");
    scanf(" %[^\n]", contacts[num_contacts].email);
    num_contacts++;
}

void remove_contact() {
    printf("Enter email to remove: ");
    char email[MAX_EMAIL_SIZE];
    scanf("%s", email);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            memmove(&contacts[i], &contacts[i+1], sizeof(contact) * (num_contacts - i - 1));
            num_contacts--;
            break;
        }
    }
}

void send_email(char* to, char* subject, char* body) {
    printf("Sending email to %s with subject %s:\n%s\n", to, subject, body);
}

void send_to_all() {
    printf("Enter subject: ");
    char subject[MAX_LINE_SIZE];
    scanf(" %[^\n]", subject);
    printf("Enter body: ");
    char body[MAX_LINE_SIZE];
    scanf(" %[^\n]", body);
    for (int i = 0; i < num_contacts; i++) {
        send_email(contacts[i].email, subject, body);
    }
}

void main() {
    printf("Welcome to the mailing list manager!\n");
    while (1) {
        printf("1. Add contact\n2. Remove contact\n3. Send email to all\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                send_to_all();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}