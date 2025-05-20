//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 500
#define MAX_USERS 10

typedef struct {
    char name[50];
    char email[50];
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user(char *name, char *email) {
    if (num_users < MAX_USERS) {
        strcpy(users[num_users].name, name);
        strcpy(users[num_users].email, email);
        num_users++;
    } else {
        printf("Sorry, the email client is full! You can't add any more users. :(");
    }
}

void send_email(char *to, char *subject, char *body) {
    printf("Sending email to %s with subject %s and body %s...\n", to, subject, body);
    // simulate sending email by printing out the message
    printf("Message sent! :D\n");
}

int main() {
    char name[50];
    char email[50];
    char subject[50];
    char body[50];

    // simulate login
    printf("Login to your email account...\n");
    scanf("%s%s", name, email);
    add_user(name, email);

    // simulate composing an email
    printf("Compose an email to %s...\n", name);
    scanf("%s%s%s", subject, body);
    send_email(name, subject, body);

    // simulate sending an email
    printf("Sending an email to %s...\n", name);
    send_email(name, "Subject", "Body");

    // simulate logging out
    printf("Logging out...\n");
    return 0;
}