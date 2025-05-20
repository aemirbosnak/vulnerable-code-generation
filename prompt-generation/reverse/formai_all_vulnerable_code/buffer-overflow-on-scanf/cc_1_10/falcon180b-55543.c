//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char name[50];
    char email[100];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* name, char* email) {
    if (num_emails >= MAX_EMAILS) {
        printf("ERROR: Mailing list is full.\n");
        return;
    }

    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);
    num_emails++;
}

void remove_email(char* email) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            memmove(&emails[i], &emails[i+1], sizeof(Email) * (num_emails - i - 1));
            num_emails--;
            break;
        }
    }
}

void print_emails() {
    int i;
    for (i = 0; i < num_emails; i++) {
        printf("%s <%s>\n", emails[i].name, emails[i].email);
    }
}

int main() {
    char command[100];
    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[50];
            char email[100];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_email(name, email);
        } else if (strcmp(command, "remove") == 0) {
            char email[100];
            printf("Enter email: ");
            scanf("%s", email);
            remove_email(email);
        } else if (strcmp(command, "list") == 0) {
            print_emails();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}