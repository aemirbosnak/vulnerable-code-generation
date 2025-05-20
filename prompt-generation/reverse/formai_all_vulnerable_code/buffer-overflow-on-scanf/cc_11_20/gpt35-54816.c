//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int main()
{
    char input[MAX_LEN];
    int choice = 0, len = 0, i = 0;

    printf("Welcome to the Text Processing Program!\n");

    while (1)
    {
        printf("\nEnter the text to be processed: ");
        fgets(input, MAX_LEN, stdin);
        len = strlen(input);

        printf("\nPlease select an operation to perform on the text:");
        printf("\n1. Convert text to uppercase");
        printf("\n2. Convert text to lowercase");
        printf("\n3. Capitalize first letter of every word");
        printf("\n4. Count the number of words in the text");
        printf("\n5. Count the number of characters in the text");
        printf("\n6. Reverse the text");
        printf("\n7. Exit Program");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            for (i = 0; i < len; i++)
            {
                input[i] = toupper(input[i]);
            }
            printf("\nText in uppercase: %s", input);
            break;
        case 2:
            for (i = 0; i < len; i++)
            {
                input[i] = tolower(input[i]);
            }
            printf("\nText in lowercase: %s", input);
            break;
        case 3:
            for (i = 0; i < len; i++)
            {
                if (i == 0 || input[i - 1] == ' ')
                {
                    input[i] = toupper(input[i]);
                }
                else
                {
                    input[i] = tolower(input[i]);
                }
            }
            printf("\nText with capitalized words: %s", input);
            break;
        case 4:
            i = 0;
            int wordCount = 0;
            while (input[i] != '\0')
            {
                if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
                {
                    wordCount++;
                }
                i++;
            }
            printf("\nNumber of words in the text: %d", wordCount + 1);
            break;
        case 5:
            printf("\nNumber of characters in the text: %d", strlen(input) - 1);
            break;
        case 6:
            printf("\nReversed text: ");
            for (i = strlen(input) - 2; i >= 0; i--)
            {
                printf("%c", input[i]);
            }
            break;
        case 7:
            printf("Thank you for using the Text Processing Program. Goodbye!\n");
            exit(0);
        default:
            printf("\nInvalid choice entered. Please try again.");
            break;
        }
        getchar();  // consume the newline character left in the buffer
    }

    return 0;
}