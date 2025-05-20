//FormAI DATASET v1.0 Category: Email Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 500

typedef struct {
    char* to;
    char* from;
    char* subject;
    char* message;
} Email;

void* send_email(void* arg) {
    Email* email = (Email*) arg;

    printf("Sending email from %s to %s with subject: %s\n", email->from, email->to, email->subject);
    printf("Message: %s\n", email->message);

    free(email->to);
    free(email->from);
    free(email->subject);
    free(email->message);
    free(email);

    pthread_exit(NULL);
}

int main() {
    pthread_t tid;

    char* to = malloc(sizeof(char) * MAX_SUBJECT_LENGTH);
    char* from = malloc(sizeof(char) * MAX_SUBJECT_LENGTH);
    char* subject = malloc(sizeof(char) * MAX_SUBJECT_LENGTH);
    char* message = malloc(sizeof(char) * MAX_MESSAGE_LENGTH);

    printf("Enter recipient email address: ");
    scanf("%s", to);

    printf("Enter sender email address: ");
    scanf("%s", from);

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email message: ");
    scanf("%s", message);

    Email* email = malloc(sizeof(Email));
    email->to = to;
    email->from = from;
    email->subject = subject;
    email->message = message;

    int result = pthread_create(&tid, NULL, send_email, (void*) email);
    if (result != 0) {
        printf("Error creating thread\n");
        exit(1);
    }

    printf("Email sent successfully!\n");

    pthread_exit(NULL);
}