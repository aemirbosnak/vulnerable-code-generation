#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void send_email(char *recipient, char *subject, char *body, int length) {
    printf("Sending email to %s with subject: %s\n", recipient, subject);
    printf("Email body:\n%s\n", body);
}

int main() {
    char recipient[100];
    char subject[100];
    char body[500];

    printf("Enter recipient:\n");
    scanf("%s", recipient);

    printf("Enter subject:\n");
    scanf("%s", subject);

    printf("Enter email body (up to 500 characters):\n");
    scanf("%s", body);

    send_email(recipient, subject, body, strlen(body));

    return 0;
}
