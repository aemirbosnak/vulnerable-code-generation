//FormAI DATASET v1.0 Category: Email Client ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1024 // Buffer size for data

int main()
{
    char buffer[SIZE]; // Buffer for user input
    int choice; // Choice of operation
    char from[40]; // Sender's email address
    char to[40]; // Recipient's email address
    char subject[100]; // Email subject
    char message[SIZE]; // Email message
    FILE *fp; // File pointer to read from temp file
    char temp[SIZE]; // Temporary buffer to store file contents
    char ch; // Character to read from file

    printf("Welcome to our Email Client!\n");

    while(1)
    {
        // Display menu and get user's choice
        printf("\nWhat would you like to do?\n");
        printf("1. Compose a new email\n");
        printf("2. Read an email from Inbox\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // Compose a new email
                printf("\nCompose Email\n");
                printf("From: ");
                scanf("%s", from);
                printf("To: ");
                scanf("%s", to);
                printf("Subject: ");
                scanf("%s", subject);
                printf("Message:\n");
                scanf(" ");
                fgets(message, SIZE, stdin);

                // Write email to temp file
                fp = fopen("temp.txt", "w");
                fprintf(fp, "From: %s\n", from);
                fprintf(fp, "To: %s\n", to);
                fprintf(fp, "Subject: %s\n", subject);
                fprintf(fp, "Message: %s\n", message);
                fclose(fp);

                printf("\nEmail has been saved as a draft!\n");
                break;

            case 2:
                // Read email from temp file
                printf("\nInbox\n");

                fp = fopen("temp.txt", "r");
                if(fp == NULL)
                {
                    printf("No emails found in Inbox.\n");
                    break;
                }

                // Read each line from file and display as email
                fgets(temp, SIZE, fp);
                while(!feof(fp))
                {
                    if(strncmp(temp, "From: ", 6) == 0)
                    {
                        printf("%s", temp);
                    }
                    else if(strncmp(temp, "To: ", 4) == 0)
                    {
                        printf("%s", temp);
                    }
                    else if(strncmp(temp, "Subject: ", 9) == 0)
                    {
                        printf("%s", temp);
                    }
                    else if(strncmp(temp, "Message: ", 9) == 0)
                    {
                        printf("\n");
                        ch = fgetc(fp);
                        while(ch != EOF)
                        {
                            printf("%c", ch);
                            ch = fgetc(fp);
                        }
                    }

                    fgets(temp, SIZE, fp);
                }

                fclose(fp);
                break;

            case 3:
                // Exit program
                printf("\nGoodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please choose again.\n");
                break;
        }
    }

    return 0;
}