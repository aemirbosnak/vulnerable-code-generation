//Falcon-180B DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to trim whitespace from the beginning and end of a string
void trim(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            strcpy(str, &str[i]);
            break;
        }
    }
    for (i = strlen(str) - 1; i >= 0; i--) {
        if (!isspace(str[i])) {
            str[i + 1] = '\0';
            break;
        }
    }
}

// Function to read a line of input from the user
char* read_line() {
    char* line = malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, stdin);
    trim(line);
    return line;
}

// Function to send an email
void send_email(char* subject, char* body, char* to) {
    char* cmd = malloc(strlen("mailx -s \"") + strlen(subject) + strlen("\" ") + strlen(to) + 2);
    sprintf(cmd, "mailx -s \"%s\" %s", subject, to);
    system(cmd);
    free(cmd);
}

// Function to read an email
void read_email(char* from) {
    char* cmd = malloc(strlen("mailx -f ") + strlen(from) + 2);
    sprintf(cmd, "mailx -f %s", from);
    system(cmd);
    free(cmd);
}

// Function to compose an email
void compose_email() {
    char* to = read_line();
    char* subject = read_line();
    char* body = read_line();

    send_email(subject, body, to);

    printf("Email sent to %s\n", to);
}

// Function to read emails
void read_emails() {
    char* from = read_line();

    read_email(from);
}

// Function to display the main menu
void main_menu() {
    printf("Email Client\n");
    printf("1. Compose email\n");
    printf("2. Read emails\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    while (1) {
        main_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compose_email();
                break;
            case 2:
                read_emails();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}