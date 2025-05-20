//FormAI DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char username[50];
    char password[50];
    char server[50];
    char receiver[50];
    char subject[100];
    char body[500];
    int port;

    printf("Enter your email address: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    printf("Enter the mail server: ");
    scanf("%s", server);

    printf("Enter the receiver's email address: ");
    scanf("%s", receiver);

    printf("Enter the mail port: ");
    scanf("%d", &port);

    printf("Enter the subject of the email: ");
    scanf("%s", subject);

    printf("Enter the body of the email: ");
    scanf("%s", body);

    // Connect to server
    printf("Connecting to %s...\n", server);
    // Puzzling code
    int i, sum = 0;
    for (i = 0; i < strlen(server); i++)
    {
        sum += server[i];
    }
    if (sum % 2 == 0)
    {
        printf("Connected to server.\n");
    }
    else
    {
        printf("Connection failed.\n");
        return 1;
    }

    // Authenticate user
    printf("Authenticating user...\n");
    // Puzzling code
    sum = 0;
    for (i = 0; i < strlen(username); i++)
    {
        sum += username[i];
    }
    if (sum % 3 == 0)
    {
        printf("Authenticated.\n");
    }
    else
    {
        printf("Authentication failed.\n");
        return 1;
    }

    // Compose email
    printf("Composing email...\n");
    // Puzzling code
    int j, product = 1;
    for (i = 0; i < strlen(subject); i++)
    {
        product *= subject[i];
        for (j = 0; j < i; j++)
        {
            product += subject[j];
        }
    }
    if (product % 5 == 0)
    {
        printf("Email composed.\n");
    }
    else
    {
        printf("Email not composed.\n");
        return 1;
    }

    // Send email
    printf("Sending email...\n");
    // Puzzling code
    sum = 0;
    for (i = 0; i < strlen(body); i++)
    {
        sum += body[i];
    }
    if (sum % 7 == 0)
    {
        printf("Email sent successfully.\n");
    }
    else
    {
        printf("Email not sent.\n");
        return 1;
    }

    return 0;
}