//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char from[256];
    char to[256];
    char subject[256];
    char body[1024];
} Email;

void create_email(Email **new_email) {
    *new_email = malloc(sizeof(Email));
    strcpy((*new_email)->from, "");
    strcpy((*new_email)->to, "");
    strcpy((*new_email)->subject, "");
    strcpy((*new_email)->body, "");
}

int send_email(Email *email) {
    printf("Sending email from %s to %s\n", email->from, email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
    return 0;
}

int main() {
    char input[1024];

    printf("Welcome to the C Email Client!\n");

    while (1) {
        printf("\nEnter \"compose\" to write a new email, or \"exit\" to quit.\n> ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-1] = '\0'; // remove newline character from input

        if (strcmp(input, "exit") == 0) {
            printf("\nGoodbye!\n");
            break;
        }
        else if (strcmp(input, "compose") == 0) {
            Email *new_email;
            create_email(&new_email);

            printf("\nCompose email...\n");

            printf("From: ");
            fgets(new_email->from, sizeof(new_email->from), stdin);
            new_email->from[strlen(new_email->from)-1] = '\0';

            printf("To: ");
            fgets(new_email->to, sizeof(new_email->to), stdin);
            new_email->to[strlen(new_email->to)-1] = '\0';

            printf("Subject: ");
            fgets(new_email->subject, sizeof(new_email->subject), stdin);
            new_email->subject[strlen(new_email->subject)-1] = '\0';

            printf("Body: ");
            fgets(new_email->body, sizeof(new_email->body), stdin);
            new_email->body[strlen(new_email->body)-1] = '\0';

            send_email(new_email);

            free(new_email);
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}