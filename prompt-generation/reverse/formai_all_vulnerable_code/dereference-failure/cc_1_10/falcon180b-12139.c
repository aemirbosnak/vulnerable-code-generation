//Falcon-180B DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10

typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
    char recipients[MAX_RECIPIENTS][100];
    int num_recipients;
} Email;

void print_email(Email* email) {
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    printf("Timestamp: %s\n", ctime(&email->timestamp));
    printf("Recipients:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("%s\n", email->recipients[i]);
    }
}

Email* create_email() {
    Email* email = (Email*) malloc(sizeof(Email));
    if (email == NULL) {
        printf("Error: Unable to allocate memory for email.\n");
        exit(1);
    }
    memset(email, 0, sizeof(Email));
    return email;
}

void add_recipient(Email* email, char* recipient) {
    if (email->num_recipients >= MAX_RECIPIENTS) {
        printf("Error: Maximum number of recipients reached.\n");
        return;
    }
    strcpy(email->recipients[email->num_recipients], recipient);
    email->num_recipients++;
}

int main() {
    Email* email = create_email();

    printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH);
    scanf("%s", email->subject);

    printf("Enter body (max %d characters): \n", MAX_BODY_LENGTH);
    fgets(email->body, MAX_BODY_LENGTH, stdin);
    email->body[strcspn(email->body, "\n")] = '\0';

    time(&email->timestamp);

    int num_recipients;
    printf("Enter number of recipients (max %d): ", MAX_RECIPIENTS);
    scanf("%d", &num_recipients);

    for (int i = 0; i < num_recipients; i++) {
        char recipient[100];
        printf("Enter recipient %d: ", i+1);
        scanf("%s", recipient);
        add_recipient(email, recipient);
    }

    print_email(email);

    return 0;
}