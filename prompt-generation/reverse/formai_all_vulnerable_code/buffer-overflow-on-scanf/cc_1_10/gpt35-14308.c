//FormAI DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_EMAILS 100

typedef struct Email {
    char sender[MAX_BUFFER_SIZE];
    char recipients[MAX_BUFFER_SIZE];
    char subject[MAX_BUFFER_SIZE];
    char body[MAX_BUFFER_SIZE];
} Email;

typedef struct EmailClient {
    Email emails[MAX_EMAILS];
    int num_emails;
} EmailClient;

int main(void) {
    EmailClient client;
    client.num_emails = 0;
    
    int option = 0;
    while (option != 4) {
        printf("Email Client Options:\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Delete All Emails\n");
        printf("4. Quit\n");
        
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1: {
                Email email;
                printf("Enter sender email address: ");
                scanf("%s", email.sender);
                
                printf("Enter recipients email address: ");
                scanf("%s", email.recipients);
                
                printf("Enter email subject: ");
                getchar();
                fgets(email.subject, MAX_BUFFER_SIZE, stdin);
                
                printf("Enter email body: ");
                fgets(email.body, MAX_BUFFER_SIZE, stdin);
                
                client.emails[client.num_emails] = email;
                client.num_emails++;
                printf("Email sent!\n");
                break;
            }
            case 2: {
                if (client.num_emails == 0) {
                    printf("Inbox is empty!\n");
                    break;
                }
                
                printf("Inbox:\n");
                for (int i = 0; i < client.num_emails; i++) {
                    printf("Email %d:\n", i+1);
                    printf("From: %s\n", client.emails[i].sender);
                    printf("To: %s\n", client.emails[i].recipients);
                    printf("Subject: %s\n", client.emails[i].subject);
                    printf("Body: %s\n", client.emails[i].body);
                }
                
                break;
            }
            case 3: {
                printf("Deleting all emails...\n");
                client.num_emails = 0;
                break;
            }
            case 4: {
                printf("Quitting email client...\n");
                break;
            }
            default: {
                printf("Invalid option. Try again.\n");
                break;
            }
        }
    }
    
    return EXIT_SUCCESS;
}