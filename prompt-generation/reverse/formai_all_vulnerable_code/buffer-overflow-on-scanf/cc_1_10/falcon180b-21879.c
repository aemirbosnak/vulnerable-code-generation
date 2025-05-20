//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_WORD 1024

// Function prototypes
void process_line(char *line);
void process_word(char *word);

int main() {
    char line[MAX_LINE];
    char word[MAX_WORD];

    printf("Enter IMAP server address: ");
    scanf("%s", line);

    printf("Enter IMAP username: ");
    scanf("%s", line);

    printf("Enter IMAP password: ");
    scanf("%s", line);

    printf("Enter recipient email address: ");
    scanf("%s", line);

    printf("Enter subject: ");
    scanf("%s", line);

    printf("Enter message body: ");
    scanf("%[^\n]", line);

    process_line(line);

    return 0;
}

void process_line(char *line) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        process_word(word);
        word = strtok(NULL, " ");
    }
}

void process_word(char *word) {
    if (strcmp(word, "IMAP") == 0) {
        printf("Connecting to IMAP server...\n");
    } else if (strcmp(word, "username") == 0) {
        printf("Logging in with username...\n");
    } else if (strcmp(word, "password") == 0) {
        printf("Authenticating with password...\n");
    } else if (strcmp(word, "recipient") == 0) {
        printf("Sending message to recipient...\n");
    } else if (strcmp(word, "subject") == 0) {
        printf("Setting subject of message...\n");
    } else if (strcmp(word, "body") == 0) {
        printf("Setting body of message...\n");
    } else {
        printf("Unknown command: %s\n", word);
    }
}