//FormAI DATASET v1.0 Category: Email Client ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 50
#define MAX_EMAILS 10

typedef struct
{
    char sender[MAX_LEN];
    char subject[MAX_LEN];
    char message[MAX_LEN];
} Email;

Email inbox[MAX_EMAILS];
int emailCount = 0;

void sendEmail()
{
    Email newEmail;
    printf("To: ");
    scanf("%s", newEmail.sender);
    printf("Subject: ");
    scanf("%s", newEmail.subject);
    printf("Message: ");
    scanf("%s", newEmail.message);
    inbox[emailCount++] = newEmail;
    printf("Email sent successfully!\n");
}

void viewInbox()
{
    if(emailCount == 0)
    {
        printf("Inbox is empty.\n");
        return;
    }
    printf("Inbox:\n");
    for(int i=0; i<emailCount; i++)
    {
        printf("Sender: %s\n", inbox[i].sender);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Message: %s\n", inbox[i].message);
    }
}

int main()
{
    int choice;
    do
    {
        printf("Choose an option:\n");
        printf("1. Send email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                sendEmail();
                break;
            case 2:
                viewInbox();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);
    return 0;
}