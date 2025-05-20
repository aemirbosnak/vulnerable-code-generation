//FormAI DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main()
{
    // Welcome message
    printf("Welcome to String Manipulation Program!\n\n");

    // Prompt the user to enter a string
    char str[50];
    printf("Please enter a string (maximum 50 characters): ");
    scanf("%[^\n]", str);

    // Display the original string
    printf("\nThe original string is: %s\n", str);

    // Count the number of vowels in the string
    int vowels = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        switch (str[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowels++;
                break;
            default:
                break;
        }
    }
    printf("\nThe number of vowels in the string is: %d\n", vowels);

    // Reverse the string
    char rev_str[50];
    int j = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        rev_str[j] = str[i];
        j++;
    }
    rev_str[j] = '\0';
    printf("\nThe reversed string is: %s\n", rev_str);

    // Capitalize the string
    char cap_str[50];
    for (int i = 0; i < strlen(str); i++)
    {
        cap_str[i] = toupper(str[i]);
    }
    cap_str[strlen(str)] = '\0';
    printf("\nThe capitalized string is: %s\n", cap_str);

    // Remove all whitespace from the string
    char no_space_str[50];
    j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            no_space_str[j] = str[i];
            j++;
        }
    }
    no_space_str[j] = '\0';
    printf("\nThe string without spaces is: %s\n", no_space_str);

    // Exit message
    printf("\nThanks for using String Manipulation Program!\n");

    return 0;
}