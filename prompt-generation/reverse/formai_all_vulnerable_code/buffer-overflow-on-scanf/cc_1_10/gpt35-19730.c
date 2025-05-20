//FormAI DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu();
void readEmail();
void sendEmail();
void deleteEmail();

int main()
{
    displayMenu();
    return 0;
}

void displayMenu()
{
    int option;
    printf("\n\n\t\t\tWelcome to CyberMail\n\n");
    printf("1. Read Email\n2. Send Email\n3. Delete Email\n\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            readEmail();
            break;
        case 2:
            sendEmail();
            break;
        case 3:
            deleteEmail();
            break;
        default:
            printf("Invalid option chosen.\n");
            break;
    }

    displayMenu();
}

void readEmail()
{
    char emailHeader[1000];
    char emailBody[10000];
    printf("\n\t\t\t\tCyberMail Inbox\n\n");
    printf("From\t\tSubject\t\t\t\t\tMessage\n");
    strcpy(emailHeader, "TechnoRevolutionary@network.com\tWelcome to the Resistance\tHi, we are glad to have you on board.");
    strcpy(emailBody, "You have been selected to join the TechnoRevolution. We have been watching your work and think you are the perfect candidate to help us take down the megacorporations that have been oppressing us.\n\nMeet us at the following coordinates: 51.4975° N, 0.1357° W.\n\nRemember: Trust no one. Code is Law. We will be in touch.");
    printf("%s\t%s\n", strtok(emailHeader, "\t"), strtok(NULL, "\t"));
    printf("%s\n\n\n", emailBody);
}

void sendEmail()
{
    char recipient[50], subject[100], message[1000];
    printf("\n\t\t\t\tCyberMail Compose\n\n");
    printf("Enter the recipient's email address: ");
    scanf("%s", recipient);
    printf("\nEnter the subject of the email: ");
    scanf("%s", subject);
    printf("\nEnter the message: ");
    scanf("%s", message);
    printf("\nYour email has been sent successfully!");
}

void deleteEmail()
{
    char emailHeader[1000];
    int emailNumber;
    printf("\n\t\t\t\tCyberMail Inbox\n\n");
    printf("No\tFrom\t\tSubject\t\t\t\t\tMessage\n");
    strcpy(emailHeader, "1\tTechnoRevolutionary@network.com\tWelcome to the Resistance\tHi, we are glad to have you on board.");
    printf("%s\n", emailHeader);
    printf("Enter the number of the email you want to delete: ");
    scanf("%d", &emailNumber);
    printf("\nThe email has been deleted successfully!");
}