//Gemma-7B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 10

typedef struct Message {
    char sender[50];
    char recipient[50];
    char subject[50];
    char message[1000];
} Message;

Message messages[MAX_MESSAGES];

void read_messages() {
    FILE *fp = fopen("messages.txt", "r");
    if (fp) {
        int i = 0;
        while (fscanf(fp, "%s %s %s %s\n", messages[i].sender, messages[i].recipient, messages[i].subject, messages[i].message) != EOF) {
            i++;
        }
        fclose(fp);
    }
}

void write_messages() {
    FILE *fp = fopen("messages.txt", "w");
    if (fp) {
        int i = 0;
        for (i = 0; messages[i].sender[0] != '\0'; i++) {
            fprintf(fp, "%s %s %s %s\n", messages[i].sender, messages[i].recipient, messages[i].subject, messages[i].message);
        }
        fclose(fp);
    }
}

int main() {
    read_messages();
    // Display messages
    for (int i = 0; messages[i].sender[0] != '\0'; i++) {
        printf("From: %s\n", messages[i].sender);
        printf("To: %s\n", messages[i].recipient);
        printf("Subject: %s\n", messages[i].subject);
        printf("Message: %s\n", messages[i].message);
        printf("\n");
    }

    // Write a new message
    Message new_message;
    printf("Enter sender: ");
    scanf("%s", new_message.sender);
    printf("Enter recipient: ");
    scanf("%s", new_message.recipient);
    printf("Enter subject: ");
    scanf("%s", new_message.subject);
    printf("Enter message: ");
    scanf("%s", new_message.message);

    messages[MAX_MESSAGES - 1] = new_message;
    write_messages();

    return 0;
}