//FormAI DATASET v1.0 Category: Email Client ; Style: grateful
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 500

struct Email
{
    char to[SIZE];
    char from[SIZE];
    char subject[SIZE];
    char message[SIZE*2];
};

void sendEmail(struct Email email)
{
    //code to send email
}

void getNewMail()
{
    //code to check mail server for new mail
}

void viewMail()
{
    //code to display user's emails
}

int main()
{
    int choice;

    printf("Welcome to the Grateful Email Client!\n");

    do
    {
        printf("\nPlease select an option:\n");
        printf("1. Send an Email\n2. Check for New Mail\n3. View Your Emails\n4. Exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                struct Email email;

                printf("\nTo: ");
                scanf("%s", email.to);

                printf("From: ");
                scanf("%s", email.from);

                printf("Subject: ");
                scanf("%s", email.subject);

                printf("Message: ");
                scanf("%s", email.message);

                sendEmail(email);
                printf("\nEmail sent!\n");
                break;
            }

            case 2:
            {
                getNewMail();
                break;
            }

            case 3:
            {
                viewMail();
                break;
            }

            case 4:
            {
                printf("Thank you for using the Grateful Email Client!\n");
                break;
            }

            default:
            {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }while(choice != 4);

    return 0;
}