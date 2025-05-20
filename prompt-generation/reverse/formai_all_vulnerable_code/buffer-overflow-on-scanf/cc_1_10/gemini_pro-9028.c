//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", "1", "2", "3", "4",
    "5", "6", "7", "8", "9", "0", ".", ",", "?", "!",
    " "
};

// Define the human language dictionary
char *human_dict[] = {
    "alpha", "bravo", "charlie", "delta", "echo", "foxtrot",
    "golf", "hotel", "india", "juliet", "kilo", "lima",
    "mike", "november", "oscar", "papa", "quebec", "romeo",
    "sierra", "tango", "uniform", "victor", "whiskey", "xray",
    "yankee", "zulu", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "zero", "period", "comma",
    "question", "exclamation", "space"
};

// Function to translate a string from alien to human language
char *alien_to_human(char *alien)
{
    // Allocate memory for the translated string
    char *human = malloc(strlen(alien) + 1);

    // Translate each character in the alien string
    for (int i = 0; i < strlen(alien); i++)
    {
        // Find the index of the character in the alien dictionary
        int index = -1;
        for (int j = 0; j < sizeof(alien_dict) / sizeof(char *); j++)
        {
            if (strcmp(alien[i], alien_dict[j]) == 0)
            {
                index = j;
                break;
            }
        }

        // If the character is not found in the alien dictionary, leave it as is
        if (index == -1)
        {
            human[i] = alien[i];
        }
        // Otherwise, translate the character to human language
        else
        {
            human[i] = human_dict[index];
        }
    }

    // Add a null terminator to the end of the translated string
    human[strlen(alien)] = '\0';

    // Return the translated string
    return human;
}

// Function to translate a string from human to alien language
char *human_to_alien(char *human)
{
    // Allocate memory for the translated string
    char *alien = malloc(strlen(human) + 1);

    // Translate each character in the human string
    for (int i = 0; i < strlen(human); i++)
    {
        // Find the index of the character in the human dictionary
        int index = -1;
        for (int j = 0; j < sizeof(human_dict) / sizeof(char *); j++)
        {
            if (strcmp(human[i], human_dict[j]) == 0)
            {
                index = j;
                break;
            }
        }

        // If the character is not found in the human dictionary, leave it as is
        if (index == -1)
        {
            alien[i] = human[i];
        }
        // Otherwise, translate the character to alien language
        else
        {
            alien[i] = alien_dict[index];
        }
    }

    // Add a null terminator to the end of the translated string
    alien[strlen(human)] = '\0';

    // Return the translated string
    return alien;
}

// Main function
int main()
{
    // Get the input string from the user
    char input[100];
    printf("Enter a string to translate: ");
    scanf("%s", input);

    // Translate the string from alien to human language
    char *human = alien_to_human(input);

    // Print the translated string
    printf("Alien: %s\n", input);
    printf("Human: %s\n", human);

    // Free the memory allocated for the translated string
    free(human);

    // Translate the string from human to alien language
    char *alien = human_to_alien(input);

    // Print the translated string
    printf("Human: %s\n", input);
    printf("Alien: %s\n", alien);

    // Free the memory allocated for the translated string
    free(alien);

    return 0;
}