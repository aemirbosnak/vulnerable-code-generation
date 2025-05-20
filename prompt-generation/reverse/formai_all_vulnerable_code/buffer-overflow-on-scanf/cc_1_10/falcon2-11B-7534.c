//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <string.h>

// Function to search for a character in a string
int searchChar(char str[], char target)
{
    // Loop through the string
    int i = 0;
    while (str[i]!= '\0')
    {
        // If we find the target character, return 1
        if (str[i] == target)
        {
            return 1;
        }

        // Move to the next character
        i++;
    }

    // If we don't find the target character, return 0
    return 0;
}

// Main function
int main()
{
    // Input string
    char str[100];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    // Prompt the user to enter a target character
    printf("Enter a target character: ");
    char target;
    scanf(" %c", &target);

    // Search for the target character in the string
    if (searchChar(str, target))
    {
        printf("Target character found!\n");
    }
    else
    {
        printf("Target character not found.\n");
    }

    return 0;
}