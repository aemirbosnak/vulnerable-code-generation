//Falcon-180B DATASET v1.0 Category: Email Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void print_emails() {
    printf("Subject\tBody\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s\t%s\n", emails[i].subject, emails[i].body);
    }
}

int main() {
    char input[1000];
    while (1) {
        printf("Enter command (send, read, exit): ");
        scanf("%s", input);

        if (strcmp(input, "send") == 0) {
            printf("Enter subject: ");
            scanf("%s", input);
            strcpy(emails[num_emails].subject, input);

            printf("Enter body: ");
            scanf("%s", input);
            strcpy(emails[num_emails].body, input);

            num_emails++;
            printf("Email sent.\n");
        } else if (strcmp(input, "read") == 0) {
            print_emails();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}