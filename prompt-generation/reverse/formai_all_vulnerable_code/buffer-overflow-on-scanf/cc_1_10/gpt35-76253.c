//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

char* reverseString(char* originalString); // Function to reverse a given string
char* removeSpaces(char* originalString); // Function to remove spaces from a given string
char* capitalizeString(char* originalString); // Function to capitalize the first letter of each word in a given string

int main()
{
    char inputString[MAX_STRING_LENGTH], option;
    char* modifiedString;

    printf("Please enter a string: ");
    scanf("%[^\n]s", inputString);

    do
    {
        printf("\nPlease select an option:\n");
        printf("1. Reverse the string\n");
        printf("2. Remove spaces from the string\n");
        printf("3. Capitalize the first letter of each word in the string\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf(" %c", &option);

        switch(option)
        {
            case '1':
                modifiedString = reverseString(inputString);
                printf("\nReversed string: %s\n", modifiedString);
                free(modifiedString);
                break;
            
            case '2':
                modifiedString = removeSpaces(inputString);
                printf("\nString with spaces removed: %s\n", modifiedString);
                free(modifiedString);
                break;

            case '3':
                modifiedString = capitalizeString(inputString);
                printf("\nCapitalized string: %s\n", modifiedString);
                free(modifiedString);
                break;

            case '4':
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid option! Please try again.\n");
        }

    } while(option != '4');

    return 0;
}

char* reverseString(char* originalString)
{
    int len = strlen(originalString);

    char* reversedString = malloc(len * sizeof(char));

    for(int i = 0; i < len; i++)
    {
        reversedString[i] = originalString[len - (i + 1)];
    }

    return reversedString;
}

char* removeSpaces(char* originalString)
{
    int len = strlen(originalString);

    char* stringWithoutSpaces = malloc(len * sizeof(char));
    int j = 0;

    for(int i = 0; i < len; i++)
    {
        if(originalString[i] != ' ')
        {
            stringWithoutSpaces[j] = originalString[i];
            j++;
        }
    }

    return stringWithoutSpaces;
}

char* capitalizeString(char* originalString)
{
    int len = strlen(originalString);

    char* capitalizedString = malloc(len * sizeof(char));
    capitalizedString[0] = toupper(originalString[0]);

    for(int i = 1; i < len; i++)
    {
        if(originalString[i - 1] == ' ')
        {
            capitalizedString[i] = toupper(originalString[i]);
        }
        else
        {
            capitalizedString[i] = originalString[i];
        }
    }

    return capitalizedString;
}