//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 100
#define MAX_RECIPIENTS 1000
#define MAX_MESSAGE_LENGTH 10000

typedef struct {
    char subject[MAX_SUBJECTS];
    char message[MAX_MESSAGE_LENGTH];
    int num_recipients;
    char **recipients;
} Message;

void add_recipient(Message *message, char *recipient) {
    message->num_recipients++;
    message->recipients = realloc(message->recipients, sizeof(char *) * message->num_recipients);
    message->recipients[message->num_recipients - 1] = recipient;
}

int main() {
    int num_messages, i;
    Message *messages;

    printf("Enter the number of messages: ");
    scanf("%d", &num_messages);

    messages = malloc(sizeof(Message) * num_messages);

    for (i = 0; i < num_messages; i++) {
        printf("Enter the subject for message %d: ", i + 1);
        scanf("%s", messages[i].subject);

        printf("Enter the message for message %d: ", i + 1);
        fgets(messages[i].message, MAX_MESSAGE_LENGTH, stdin);

        printf("Enter the number of recipients for message %d: ", i + 1);
        scanf("%d", &messages[i].num_recipients);

        messages[i].recipients = malloc(sizeof(char *) * messages[i].num_recipients);

        printf("Enter the recipients for message %d (one per line):\n", i + 1);
        for (int j = 0; j < messages[i].num_recipients; j++) {
            char recipient[MAX_RECIPIENTS];
            fgets(recipient, MAX_RECIPIENTS, stdin);
            add_recipient(&messages[i], recipient);
        }
    }

    // send messages here

    for (i = 0; i < num_messages; i++) {
        free(messages[i].recipients);
    }
    free(messages);

    return 0;
}