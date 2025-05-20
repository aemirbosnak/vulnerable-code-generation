//FormAI DATASET v1.0 Category: Email Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_EMAILS 100

/* Define the email structure */
typedef struct {
    char *to;
    char *from;
    char *subject;
    char *message;
} Email;

/* Define the email queue structure */
typedef struct {
    int size;
    int front;
    int rear;
    Email *emails[MAX_EMAILS];
} EmailQueue;

/* Initialize the email queue */
void initQueue(EmailQueue *queue) {
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;
}

/* Add an email to the queue */
void enqueueEmail(EmailQueue *queue, Email *email) {
    if (queue->size >= MAX_EMAILS) {
        printf("Error: queue is full!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_EMAILS;
    queue->emails[queue->rear] = email;
    queue->size++;
}

/* Remove an email from the queue */
Email *dequeueEmail(EmailQueue *queue) {
    if (queue->size <= 0) {
        printf("Error: queue is empty!\n");
        return NULL;
    }
    Email *email = queue->emails[queue->front];
    queue->front = (queue->front + 1) % MAX_EMAILS;
    queue->size--;
    return email;
}

/* Display all emails in the queue */
void displayAllEmails(EmailQueue *queue) {
    Email *email;
    int i;
    if (queue->size <= 0) {
        printf("There are no emails in the queue.\n");
        return;
    }
    printf("Emails in the queue:\n");
    for (i = 0; i < queue->size; i++) {
        email = queue->emails[(queue->front + i) % MAX_EMAILS];
        printf("Email #%d:\n", i+1);
        printf("\tTo: %s\n", email->to);
        printf("\tFrom: %s\n", email->from);
        printf("\tSubject: %s\n", email->subject);
        printf("\tMessage: %s\n", email->message);
    }
}

/* Prompt the user for a string input */
char *promptString(char *prompt) {
    char *input = (char *) malloc(sizeof(char) * MAX_SUBJECT_LENGTH);
    printf("%s", prompt);
    fgets(input, MAX_SUBJECT_LENGTH, stdin);
    input[strlen(input)-1] = '\0'; /* remove newline character */
    return input;
}

/* Prompt the user for a message input */
char *promptMessage(char *prompt) {
    char *input = (char *) malloc(sizeof(char) * MAX_MESSAGE_LENGTH);
    printf("%s", prompt);
    fgets(input, MAX_MESSAGE_LENGTH, stdin);
    input[strlen(input)-1] = '\0'; /* remove newline character */
    return input;
}

/* Prompt the user for an email input */
Email *promptEmail() {
    Email *email = (Email *) malloc(sizeof(Email));
    email->to = promptString("To: ");
    email->from = promptString("From: ");
    email->subject = promptString("Subject: ");
    email->message = promptMessage("Message: ");
    return email;
}

/* Main function */
int main() {
    EmailQueue emailQueue;
    Email *email;
    char choice;
    initQueue(&emailQueue);
    do {
        printf("Email Client Menu:\n");
        printf("1. Add an email\n");
        printf("2. Send all emails\n");
        printf("3. Display all emails\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        getchar(); /* remove newline character from input buffer */
        switch (choice) {
            case '1':
                email = promptEmail();
                enqueueEmail(&emailQueue, email);
                printf("Email added to queue.\n");
                break;
            case '2':
                printf("Sending all emails:\n");
                while (emailQueue.size > 0) {
                    email = dequeueEmail(&emailQueue);
                    printf("Sending email to: %s\n", email->to);
                }
                printf("All emails sent!\n");
                break;
            case '3':
                displayAllEmails(&emailQueue);
                break;
            case '4':
                printf("Exiting email client...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '4');
    return 0;
}