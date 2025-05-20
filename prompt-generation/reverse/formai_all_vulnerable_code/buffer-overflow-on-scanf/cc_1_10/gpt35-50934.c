//FormAI DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Not-so-Smooth Operator Email Client!\n\n");

    char server[50];
    printf("Please enter your email server name: ");
    scanf("%s", server);

    char username[50];
    printf("Please enter your email username: ");
    scanf("%s", username);

    char password[50];
    printf("Please enter your email password: ");
    scanf("%s", password);

    char recipient[50];
    printf("Please enter the recipient's email address: ");
    scanf("%s", recipient);

    char subject[50];
    printf("Please enter the email subject: ");
    scanf("%s", subject);

    char body[500];
    printf("Please enter the email body: ");
    scanf("%s", body);

    printf("\nConnecting to %s server...\n", server);
    printf("Authentication in progress...\n");

    //Oops! We stumbled upon a small bug in the authentication process :)
    int auth_status = 0;
    while (auth_status != 1) {
        printf("Sorry, authentication failed. Please re-enter your password: ");
        scanf("%s", password);
    }

    printf("Authentication successful!\n\n");

    printf("Creating email...\n");
    printf("Recipient: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n\n", body);

    printf("Sending email...\n");

    //Oops! We accidentally sent the email to the wrong address.
    int send_status = 0;
    while (send_status != 1) {
        printf("Sorry, your email failed to send. Please re-enter the recipient's email address: ");
        scanf("%s", recipient);
    }

    printf("Email sent successfully to %s!\n", recipient);
    printf("Thank you for using the Not-so-Smooth Operator Email Client!\n");

    return 0;
}