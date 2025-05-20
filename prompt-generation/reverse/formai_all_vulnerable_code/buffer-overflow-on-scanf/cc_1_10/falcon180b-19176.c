//Falcon-180B DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10

// Struct to store email information
typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int num_recipients;
    char recipients[MAX_RECIPIENTS][100];
} Email;

// Function to send email
void send_email(Email* email) {
    printf("Sending email...\n");
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    printf("Recipients:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("%s\n", email->recipients[i]);
    }
}

// Function to add recipient to email
void add_recipient(Email* email, char* recipient) {
    strcpy(email->recipients[email->num_recipients], recipient);
    email->num_recipients++;
}

// Function to compose email
void compose_email(Email* email) {
    printf("Composing email...\n");
    printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH);
    scanf("%[^\n]", email->subject);

    printf("Enter body (max %d characters): ", MAX_BODY_LENGTH);
    fgets(email->body, MAX_BODY_LENGTH, stdin);
    email->body[strcspn(email->body, "\n")] = '\0';

    printf("Enter number of recipients: ");
    scanf("%d", &email->num_recipients);

    for (int i = 0; i < email->num_recipients; i++) {
        printf("Enter recipient %d: ", i+1);
        scanf("%[^\n]", email->recipients[i]);
    }
}

int main() {
    Email email;

    compose_email(&email);
    send_email(&email);

    return 0;
}