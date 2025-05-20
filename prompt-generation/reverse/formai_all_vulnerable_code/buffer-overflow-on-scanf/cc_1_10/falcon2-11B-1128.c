//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100
#define MAX_NAME_LEN 50
#define MAX_NUM_LINES 10

void search_imap_client(char* username, char* password, char* mail_server, int port) {
    int num_lines = 0;
    char line[MAX_LINE_LEN];
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LINES];

    if (username == NULL || password == NULL || mail_server == NULL || port == 0) {
        printf("Invalid input. Please provide valid username, password, mail server, and port.\n");
        return;
    }

    printf("Searching for messages...\n");
    while (num_lines < MAX_NUM_LINES) {
        memset(line, 0, MAX_LINE_LEN);

        if (fgets(line, MAX_LINE_LEN, stdin) == NULL) {
            printf("Input line too long. Please enter a shorter line.\n");
            continue;
        }

        if (strlen(line) == 0) {
            printf("Invalid input. Please enter a non-empty line.\n");
            continue;
        }

        if (strstr(line, "From: ")!= NULL) {
            strncpy(name, line + 5, MAX_NAME_LEN);
            printf("Found message from: %s\n", name);
            continue;
        }

        if (strstr(line, "Subject: ")!= NULL) {
            strncpy(num, line + 8, MAX_NUM_LINES);
            printf("Found message with subject: %s\n", num);
            continue;
        }

        printf("Message not found. Please enter a different line.\n");
    }

    printf("Search complete.\n");
}

int main() {
    char username[MAX_NAME_LEN];
    char password[MAX_NAME_LEN];
    char mail_server[MAX_NAME_LEN];
    int port = 0;

    printf("Enter username: ");
    fgets(username, MAX_NAME_LEN, stdin);

    printf("Enter password: ");
    fgets(password, MAX_NAME_LEN, stdin);

    printf("Enter mail server: ");
    fgets(mail_server, MAX_NAME_LEN, stdin);

    printf("Enter port (default is 0): ");
    scanf("%d", &port);

    search_imap_client(username, password, mail_server, port);

    return 0;
}