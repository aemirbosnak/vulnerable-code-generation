//FormAI DATASET v1.0 Category: Email Client ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_SUBJECT_SIZE 255
#define MAX_BODY_SIZE 500
#define MAX_EMAIL_SIZE 1024

struct Email {
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
};

int validateEmail(char email[]) {
    int size = strlen(email);
    int at = -1, dot = -1;

    if(size < 5 || size > 50)
        return 0;

    for(int i = 0; i < size; i++) {
        if(email[i] == '@')
            at = i;
        else if(email[i] == '.')
            dot = i;
    }

    if(at < 1 || dot < (at + 2) || (dot + 2) >= size)
        return 0;

    return 1;
}

void sendEmail(struct Email* email) {
    char* emailText = (char*)malloc(MAX_EMAIL_SIZE * sizeof(char));

    if(emailText == NULL) {
        printf("Could not allocate memory for email Text.|n");
        return;
    }

    sprintf(emailText, "Sender: %s\nReceiver: %s\nSubject: %s\n\n%s\n", email->sender, email->receiver, email->subject, email->body);
    printf("\n-----Email Sent-----\n\n%s\n", emailText);
    free(emailText);
}

void getEmailDetails(struct Email* email) {
    printf("\nEnter sender's email address: ");
    scanf("%s", email->sender);

    while(!validateEmail(email->sender)) {
        printf("\nInvalid sender's email address! Enter a valid one: ");
        scanf("%s", email->sender);
    }

    printf("\nEnter receiver's email address: ");
    scanf("%s", email->receiver);

    while(!validateEmail(email->receiver)) {
        printf("\nInvalid receiver's email address! Enter a valid one: ");
        scanf("%s", email->receiver);
    }

    printf("\nEnter email subject: ");
    getchar();
    fgets(email->subject, MAX_SUBJECT_SIZE, stdin);

    printf("\nEnter email body: ");
    fgets(email->body, MAX_BODY_SIZE, stdin);
}

int main() {
    printf("\n\tMy Super Email Client\n");

    struct Email email;
    getEmailDetails(&email);
    sendEmail(&email);

    return 0;
}