//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 128

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    printf("Enter name: ");
    scanf("%s", emails[num_emails].name);

    printf("Enter email: ");
    scanf("%s", emails[num_emails].email);

    num_emails++;
}

void remove_email() {
    int index;

    printf("Enter index of email to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_emails) {
        num_emails--;

        for (int i = index; i < num_emails; i++) {
            memcpy(&emails[i], &emails[i+1], sizeof(Email));
        }
    } else {
        printf("Invalid index\n");
    }
}

void list_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("%s (%s)\n", emails[i].name, emails[i].email);
    }
}

void send_email() {
    int index;

    printf("Enter index of email to send to: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_emails) {
        printf("Sending email to %s (%s)\n", emails[index].name, emails[index].email);
    } else {
        printf("Invalid index\n");
    }
}

int main() {
    int choice;

    do {
        printf("Mailing List Manager\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. List emails\n");
        printf("4. Send email\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                remove_email();
                break;
            case 3:
                list_emails();
                break;
            case 4:
                send_email();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);

    return 0;
}