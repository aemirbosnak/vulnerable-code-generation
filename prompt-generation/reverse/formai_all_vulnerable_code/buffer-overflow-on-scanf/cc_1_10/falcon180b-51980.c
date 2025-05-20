//Falcon-180B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* subject, char* body) {
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    emails[num_emails].timestamp = time(NULL);
    num_emails++;
}

void print_emails() {
    printf("Subject\t\tBody\t\tTimestamp\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s\t\t%s\t\t%s\n", emails[i].subject, emails[i].body, ctime(&emails[i].timestamp));
    }
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command (add/print/exit): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            char subject[MAX_SUBJECT_LENGTH];
            char body[MAX_BODY_LENGTH];
            printf("Enter subject: ");
            scanf("%s", subject);
            printf("Enter body: ");
            fgets(body, MAX_BODY_LENGTH, stdin);
            body[strcspn(body, "\n")] = '\0'; // remove newline character
            add_email(subject, body);
        } else if (strcmp(input, "print") == 0) {
            print_emails();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}