//FormAI DATASET v1.0 Category: Email Client ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char username[50], password[50], recipient[50], subject[100], message[500];
    int i, choice;

    printf("\nWelcome to Unique Email Client!\n");

    printf("\nEnter your username: ");
    scanf("%s", &username);

    printf("\nEnter your password: ");
    scanf("%s", &password);

    printf("\nSuccessful login!\n");

    printf("\nChoose an option from the menu:\n");
    printf("1. Compose an email\n");
    printf("2. View inbox\n");
    printf("3. View sent emails\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter recipient's email: ");
            scanf("%s", &recipient);

            printf("\nEnter subject: ");
            scanf("%s", &subject);

            printf("\nEnter message: ");
            scanf("%s", &message);

            printf("\nEmail sent successfully to %s!\n", recipient);

            FILE *fptr;
            fptr = fopen("sent.txt", "a");

            if(fptr == NULL)
            {
                printf("Error opening file!");
                exit(1);
            }

            fprintf(fptr, "To: %s\nSubject: %s\nMessage: %s\n\n", recipient, subject, message);

            fclose(fptr);

            break;

        case 2:
            printf("\nInbox\n");

            FILE *fptr1;
            fptr1 = fopen("inbox.txt", "r");

            if(fptr1 == NULL)
            {
                printf("Error opening file!");
                exit(1);
            }

            char c = fgetc(fptr1);
            while(c != EOF)
            {
                printf("%c", c);
                c = fgetc(fptr1);
            }

            fclose(fptr1);
            
            break;

        case 3:
            printf("\nSent Emails\n");

            FILE *fptr2;
            fptr2 = fopen("sent.txt", "r");

            if(fptr2 == NULL)
            {
                printf("Error opening file!");
                exit(1);
            }

            char ch = fgetc(fptr2);
            while(ch != EOF)
            {
                printf("%c", ch);
                ch = fgetc(fptr2);
            }

            fclose(fptr2);

            break;

        case 4:
            printf("\nGoodbye!\n");
            exit(0);

        default:
            printf("\nInvalid option!\n");
            break;
    }

    return 0;
}