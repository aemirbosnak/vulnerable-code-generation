//FormAI DATASET v1.0 Category: Text processing ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int i, j, choice;

    printf("Welcome to the message processing program!\n");
    printf("Please enter a message for processing: ");
    fgets(message, 100, stdin);

    printf("\nPlease select a processing option:\n");
    printf("1. Reverse the message\n");
    printf("2. Convert message to uppercase\n");
    printf("3. Convert message to lowercase\n");
    printf("4. Count the number of vowels in the message\n");

    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nReversed message: ");
            for(i=strlen(message)-1; i>=0; i--)
            {
                printf("%c", message[i]);
            }
            break;

        case 2:
            printf("\nUppercase message: ");
            for(i=0; i<strlen(message); i++)
            {
                printf("%c", toupper(message[i]));
            }
            break;

        case 3:
            printf("\nLowercase message: ");
            for(i=0; i<strlen(message); i++)
            {
                printf("%c", tolower(message[i]));
            }
            break;

        case 4:
            printf("\nNumber of vowels in the message: ");
            int count = 0;
            for(i=0; i<strlen(message); i++)
            {
                if(message[i]=='a' || message[i]=='e' || message[i]=='i' || message[i]=='o' || message[i]=='u' || message[i]=='A' || message[i]=='E' || message[i]=='I' || message[i]=='O' || message[i]=='U')
                {
                    count++;
                }
            }
            printf("%d", count);
            break;

        default:
            printf("\nInvalid choice! Please choose between 1 and 4.");
    }

    printf("\n");

    return 0;
}