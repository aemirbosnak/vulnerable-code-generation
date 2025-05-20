//FormAI DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int main()
{
    char email[100];
    
    printf("Welcome to C Email Client!\n");
    printf("Enter your email address: ");
    scanf("%s", email);
    printf("You are logged in as: %s\n\n", email);
    
    while(1)
    {
        int choice;
        printf("Please select one of the following options:\n");
        printf("1. Compose email.\n");
        printf("2. View Inbox.\n");
        printf("3. View Sent Items.\n");
        printf("4. Logout.\n\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice)
        {
            case 1:
            {
                char recipient[50];
                char subject[50];
                char body[200];
                printf("Enter recipient's email address: ");
                scanf("%s", recipient);
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter body: ");
                scanf("%s", body);
                printf("\nEmail sent to %s with subject '%s' and body '%s'\n\n", recipient, subject, body);
                break;
            }
            
            case 2:
            {
                printf("Viewing Inbox...\n\n");
                printf("No new messages.\n\n");
                break;
            }
            
            case 3:
            {
                printf("Viewing Sent Items...\n\n");
                printf("No sent messages.\n\n");
                break;
            }
            
            case 4:
            {
                printf("Logging out...\nGoodbye, %s!\n\n", email);
                return 0;
            }
            
            default:
            {
                printf("Invalid choice. Please try again.\n\n");
            }
        }
    }
    return 0;
}