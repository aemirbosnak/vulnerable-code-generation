//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i = 0;
    printf("You are in a dark and dusty attic. A mysterious letter rests on the table in front of you.\n");
    printf("Please examine the letter carefully and enter your observations below:");
    scanf("%s", str);

    // Analyze the letter
    for (i = 0; str[i] != '\0'; i++)
    {
        // Check for vowels
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            printf("The letter contains a vowel: %c\n", str[i]);
        }

        // Check for consonants
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            printf("The letter contains a consonant: %c\n", str[i]);
        }

        // Check for numbers
        else if (str[i] >= '0' && str[i] <= '9')
        {
            printf("The letter contains a number: %c\n", str[i]);
        }

        // Check for other characters
        else
        {
            printf("The letter contains a special character: %c\n", str[i]);
        }
    }

    printf("Based on your observations, what do you think is the content of the letter?:");
    scanf("%s", str);

    // Compare the letter content to the guess
    if (strcmp(str, "The letter contains a secret message.") == 0)
    {
        printf("You are correct! The letter contains a secret message.\n");
    }
    else
    {
        printf("Your guess is incorrect. The letter does not contain a secret message.\n");
    }

    return 0;
}