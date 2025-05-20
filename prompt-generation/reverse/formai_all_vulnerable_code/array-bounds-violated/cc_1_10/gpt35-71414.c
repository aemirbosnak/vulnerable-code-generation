//FormAI DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a string is a valid email address
int validateEmail(char *email)
{
    int atCount = 0, dotCount = 0;
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
            atCount++;
        if (email[i] == '.')
            dotCount++;
    }
    if (atCount != 1 || dotCount < 1)
        return 0;
    return 1;
}

// function to send an email
void sendEmail(char *senderEmail, char *recipientEmail, char *subject, char *message)
{
    // set up SMTP connection and authenticate sender
    // code for this is not included in this example

    // construct email message
    char *email = malloc(strlen(message) + strlen(subject) + strlen(senderEmail) + strlen(recipientEmail) + 200);
    sprintf(email, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", senderEmail, recipientEmail, subject, message);

    // send email
    // code for this is not included in this example

    printf("Email sent successfully!\n");

    // close SMTP connection
    // code for this is not included in this example
}

int main()
{
    char senderEmail[100], recipientEmail[100], subject[100], message[1000];

    // prompt user for sender's email address
    printf("Enter your email address (example: username@example.com): ");
    fgets(senderEmail, 100, stdin);
    senderEmail[strlen(senderEmail) - 1] = '\0';

    // validate sender's email address
    if (!validateEmail(senderEmail))
    {
        printf("Invalid email address. Please enter a valid email address.\n");
        exit(1);
    }

    // prompt user for recipient's email address
    printf("Enter recipient's email address (example: username@example.com): ");
    fgets(recipientEmail, 100, stdin);
    recipientEmail[strlen(recipientEmail) - 1] = '\0';

    // validate recipient's email address
    if (!validateEmail(recipientEmail))
    {
        printf("Invalid email address. Please enter a valid email address.\n");
        exit(1);
    }

    // prompt user for email subject
    printf("Enter email subject: ");
    fgets(subject, 100, stdin);
    subject[strlen(subject) - 1] = '\0';

    // prompt user for email message
    printf("Enter email message: ");
    fgets(message, 1000, stdin);
    message[strlen(message) - 1] = '\0';

    // send email
    sendEmail(senderEmail, recipientEmail, subject, message);

    return 0;
}