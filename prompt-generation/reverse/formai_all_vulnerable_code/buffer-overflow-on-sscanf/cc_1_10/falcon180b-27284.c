//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000
#define MAX_RECIPIENTS 1000

typedef struct {
    char subject[MAX_SUBJECT_LEN+1];
    char body[MAX_BODY_LEN+1];
    time_t timestamp;
    int num_recipients;
    char *recipients[MAX_RECIPIENTS];
} message_t;

message_t *messages = NULL;
int num_messages = 0;

void add_message(message_t *msg) {
    messages = realloc(messages, sizeof(message_t) * ++num_messages);
    memcpy(&messages[num_messages-1], msg, sizeof(message_t));
}

int main() {
    message_t msg;
    char input[1024];

    while (fgets(input, sizeof(input), stdin)) {
        if (input[0] =='s') {
            sscanf(input, "s %[^\n]", msg.subject);
            fgets(input, sizeof(input), stdin);
            sscanf(input, "b %[^\n]", msg.body);
            msg.timestamp = time(NULL);
            msg.num_recipients = 0;

            char *token = strtok(input, " ");
            while (token!= NULL) {
                if (msg.num_recipients >= MAX_RECIPIENTS) {
                    printf("Too many recipients.\n");
                    break;
                }
                msg.recipients[msg.num_recipients++] = strdup(token);
                token = strtok(NULL, " ");
            }

            add_message(&msg);
            printf("Message added.\n");
        } else if (input[0] == 'l') {
            int i;
            for (i = 0; i < num_messages; ++i) {
                printf("%ld %s (%d recipients)\n", messages[i].timestamp, messages[i].subject, messages[i].num_recipients);
            }
        } else if (input[0] == 'q') {
            break;
        }
    }

    return 0;
}