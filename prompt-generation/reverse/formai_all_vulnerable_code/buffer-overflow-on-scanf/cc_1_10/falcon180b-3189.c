//Falcon-180B DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 500
#define MAX_SUBJECT_LENGTH 100
#define MAX_RECIPIENTS 10
#define MAX_RECIPIENT_LENGTH 50

typedef struct {
    char *name;
    char *email;
} recipient;

typedef struct {
    char *from;
    char *to;
    char *subject;
    char *body;
    time_t timestamp;
    recipient recipients[MAX_RECIPIENTS];
    int num_recipients;
} email;

void add_recipient(recipient *recipients, int *num_recipients, char *name, char *email) {
    if (*num_recipients >= MAX_RECIPIENTS) {
        printf("ERROR: Too many recipients.\n");
        return;
    }
    recipients[*num_recipients].name = strdup(name);
    recipients[*num_recipients].email = strdup(email);
    (*num_recipients)++;
}

int main() {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    recipient recipients[MAX_RECIPIENTS];
    int num_recipients = 0;
    int i;

    printf("Welcome to the Excited Email Client!\n");

    printf("Enter your name: ");
    scanf("%s", from);
    printf("Enter recipient name: ");
    scanf("%s", recipients[num_recipients].name);
    printf("Enter recipient email: ");
    scanf("%s", recipients[num_recipients].email);
    add_recipient(recipients, &num_recipients, "", "");

    printf("\nEnter email subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
    scanf("%s", subject);

    printf("\nEnter email body (max %d characters): ", MAX_EMAIL_LENGTH - 1);
    fgets(body, MAX_EMAIL_LENGTH, stdin);
    body[strcspn(body, "\n")] = '\0';

    email email = {
       .from = strdup(from),
       .to = strdup(recipients[0].email),
       .subject = strdup(subject),
       .body = strdup(body),
       .timestamp = time(NULL),
       .recipients = recipients,
       .num_recipients = num_recipients
    };

    printf("\nEmail sent successfully!\n");

    return 0;
}