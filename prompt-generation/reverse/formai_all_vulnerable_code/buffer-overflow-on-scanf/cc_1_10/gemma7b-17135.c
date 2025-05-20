//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_MAIL_LENGTH 1024

typedef struct Mail {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char message[MAX_MAIL_LENGTH];
} Mail;

void add_mail(Mail **mails, int *num_mails) {
    *mails = realloc(*mails, (*num_mails + 1) * sizeof(Mail));
    (*num_mails)++;

    printf("Enter name: ");
    scanf("%s", (*mails)->name);

    printf("Enter email: ");
    scanf("%s", (*mails)->email);

    printf("Enter message: ");
    scanf("%s", (*mails)->message);
}

void print_mail(Mail *mails, int num_mails) {
    for (int i = 0; i < num_mails; i++) {
        printf("Name: %s\n", mails[i].name);
        printf("Email: %s\n", mails[i].email);
        printf("Message: %s\n", mails[i].message);
        printf("\n");
    }
}

int main() {
    Mail *mails = NULL;
    int num_mails = 0;

    printf("Enter command (add/print): ");
    char command;
    scanf(" %c", &command);

    switch (command) {
        case 'a':
            add_mail(&mails, &num_mails);
            break;
        case 'p':
            print_mail(mails, num_mails);
            break;
        default:
            printf("Invalid command.\n");
    }

    return 0;
}