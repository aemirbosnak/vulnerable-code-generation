//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECIPIENTS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} recipient;

void add_recipient(recipient* list, int num_recipients, char* email) {
    int i;
    for (i = 0; i < num_recipients; i++) {
        if (strcmp(list[i].email, email) == 0) {
            printf("Email already subscribed.\n");
            return;
        }
    }
    strcpy(list[num_recipients].email, email);
    list[num_recipients].subscribed = 1;
    printf("Email subscribed.\n");
}

void remove_recipient(recipient* list, int num_recipients, char* email) {
    int i;
    for (i = 0; i < num_recipients; i++) {
        if (strcmp(list[i].email, email) == 0) {
            list[i].subscribed = 0;
            printf("Email unsubscribed.\n");
            return;
        }
    }
    printf("Email not found.\n");
}

void send_email(recipient* list, int num_recipients, char* subject, char* message) {
    int i;
    for (i = 0; i < num_recipients; i++) {
        if (list[i].subscribed) {
            printf("Sending email to %s...\n", list[i].email);
        }
    }
}

int main() {
    recipient list[MAX_RECIPIENTS];
    int num_recipients = 0;

    while (1) {
        printf("1. Add recipient\n2. Remove recipient\n3. Send email\n4. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char email[MAX_EMAIL_LENGTH];
                printf("Enter email: ");
                scanf("%s", email);
                add_recipient(list, num_recipients, email);
                break;
            }
            case 2: {
                char email[MAX_EMAIL_LENGTH];
                printf("Enter email: ");
                scanf("%s", email);
                remove_recipient(list, num_recipients, email);
                break;
            }
            case 3: {
                char subject[MAX_EMAIL_LENGTH];
                char message[MAX_EMAIL_LENGTH];
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter message: ");
                scanf("%s", message);
                send_email(list, num_recipients, subject, message);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}