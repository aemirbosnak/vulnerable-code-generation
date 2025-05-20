#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECEIVERS 10
#define MAX_SUBJECT 100
#define MAX_BODY 500

void compose_email(char receivers[MAX_RECEIVERS][50], char subject[MAX_SUBJECT], char body[MAX_BODY]);
void send_email(char to[50], char subject[MAX_SUBJECT], char body[MAX_BODY]);

int main() {
    char receivers[MAX_RECEIVERS][50];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];

    printf("Compose Email\n");
    printf("Enter recipients (up to 10):\n");
    for (int i = 0; i < MAX_RECEIVERS; ++i) {
        scanf("%49s", receivers[i]);
        if (strlen(receivers[i]) == 0) break;
    }

    printf("Enter subject:\n");
    scanf("%s", subject);

    printf("Enter email body (up to 500 characters):\n");
    scanf("%499s", body);

    compose_email(receivers, subject, body);

    return 0;
}

void compose_email(char receivers[MAX_RECEIVERS][50], char subject[MAX_SUBJECT], char body[MAX_BODY]) {
    for (int i = 0; i < MAX_RECEIVERS; ++i) {
        send_email(receivers[i], subject, body);
    }
}

void send_email(char to[50], char subject[MAX_SUBJECT], char body[MAX_BODY]) {
    printf("Sending email to %s with subject: %s\n", to, subject);
    printf("Email body:\n%s\n", body);
}
