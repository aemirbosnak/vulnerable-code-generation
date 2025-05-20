//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int numEmails = 0;

void addEmail(char* name, char* email) {
    strcpy(emails[numEmails].name, name);
    strcpy(emails[numEmails].email, email);
    numEmails++;
}

void removeEmail(int index) {
    if (index >= 0 && index < numEmails) {
        memmove(&emails[index], &emails[index+1], sizeof(Email) * (MAX_EMAILS - index - 1));
        numEmails--;
    }
}

void printEmails() {
    printf("Name\tEmail\n");
    for (int i = 0; i < numEmails; i++) {
        printf("%s\t%s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    char input[100];
    while (1) {
        printf("\nEnter command: ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            char name[MAX_NAME_LENGTH];
            char email[MAX_EMAIL_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            addEmail(name, email);
            printf("Email added.\n");
        } else if (strcmp(input, "remove") == 0) {
            int index;
            printf("Enter index of email to remove: ");
            scanf("%d", &index);
            removeEmail(index);
            printf("Email removed.\n");
        } else if (strcmp(input, "print") == 0) {
            printEmails();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}