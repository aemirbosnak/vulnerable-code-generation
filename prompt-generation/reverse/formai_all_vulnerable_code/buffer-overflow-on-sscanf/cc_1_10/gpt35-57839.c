//FormAI DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLine(char* line) {
    printf("%s\n", line);
}

void printEmail(char* subject, char* from, char* body) {
    printLine("Subject: ");
    printLine(subject);
    printLine("From: ");
    printLine(from);
    printLine("Message: ");
    printLine(body);
    printLine("-------------------------------");
}

void sendEmail(char* subject, char* to, char* body) {
    printf("Sending email to: %s\n", to);
    // Code to send email goes here
    printf("Subject: %s\nMessage: %s\n", subject, body);
}

int main() {
    char* subject = "Hello World";
    char* to = "example@mail.com";
    char* from = "sender@mail.com";
    char* body = "This is a test email.";

    char input[50];
    int selection;

    do {
        printf("Press 1 to view email\nPress 2 to send email\nPress 3 to quit\n");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &selection);

        switch (selection) {
            case 1:
                printEmail(subject, from, body);
                break;
            case 2:
                printf("Enter recipient's email: ");
                fgets(input, 50, stdin);
                sscanf(input, "%s", to);

                printf("Enter subject: ");
                fgets(input, 50, stdin);
                sscanf(input, "%s", subject);

                printf("Enter message: ");
                fgets(input, 50, stdin);
                sscanf(input, "%s", body);

                sendEmail(subject, to, body);
                break;
            case 3:
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    } while (selection != 3);

    return 0;
}