//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 1000
#define MAX_RECIPIENTS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} recipient_t;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
    int num_recipients;
    recipient_t *recipients;
} message_t;

int read_recipients_from_file(FILE *file, recipient_t *recipients) {
    int num_recipients = 0;
    while (fscanf(file, "%s %s\n", recipients[num_recipients].name, recipients[num_recipients].email)!= EOF) {
        num_recipients++;
    }
    return num_recipients;
}

void send_message(message_t *message, recipient_t *recipients) {
    for (int i = 0; i < message->num_recipients; i++) {
        printf("Sending message to %s (%s)\n", recipients[i].name, recipients[i].email);
    }
}

int main() {
    FILE *input_file;
    input_file = fopen("recipients.txt", "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    recipient_t recipients[MAX_RECIPIENTS];
    int num_recipients = read_recipients_from_file(input_file, recipients);

    message_t message;
    message.subject[0] = '\0';
    message.message[0] = '\0';
    message.num_recipients = num_recipients;
    message.recipients = recipients;

    printf("Enter message subject:\n");
    fgets(message.subject, MAX_SUBJECT_LEN, stdin);

    printf("Enter message:\n");
    fgets(message.message, MAX_MESSAGE_LEN, stdin);

    send_message(&message, recipients);

    fclose(input_file);
    return 0;
}