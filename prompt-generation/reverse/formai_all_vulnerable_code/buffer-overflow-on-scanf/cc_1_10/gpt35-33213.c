//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <string.h>

// Define the cat language dictionary
const char *catDictionary[] = {"meow", "purr", "hiss", "scratch", "lick", "sleep", "eat", "play", "climb", "jump"};

// Define the English language dictionary
const char *englishDictionary[] = {"Hello", "I love you", "No", "Stop it", "Give me attention", "I'm tired", "I'm hungry", "Let's play", "Let's climb", "Jump with me"};

// Function to translate cat language to English
void catToEnglish(char *catInput)
{
    // Check if the input word is valid cat word
    int isValid = 0;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(catInput, catDictionary[i]) == 0)
        {
            printf("%s", englishDictionary[i]);
            isValid = 1;
            break;
        }
    }
    // Print error message if the input word is not a valid cat word
    if (isValid == 0)
    {
        printf("I don't understand what the cat is saying.\n");
    }
}

// Function to translate English to cat language
void englishToCat(char *englishInput)
{
    // Check if the input word is valid English word
    int isValid = 0;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(englishInput, englishDictionary[i]) == 0)
        {
            printf("%s", catDictionary[i]);
            isValid = 1;
            break;
        }
    }
    // Print error message if the input word is not a valid English word
    if (isValid == 0)
    {
        printf("I don't know how to say that in cat language.\n");
    }
}

int main()
{
    char input[100];
    int option = 0;

    printf("Welcome to the Cat Language Translator.\n");
    // Loop to keep asking for input until user decides to exit
    while (option != 3)
    {
        printf("What do you want to do?\n");
        printf("1. Translate from cat to English.\n");
        printf("2. Translate from English to cat.\n");
        printf("3. Exit.\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the word in cat language: ");
            scanf("%s", input);
            catToEnglish(input);
            break;
        case 2:
            printf("Enter the word in English: ");
            scanf("%s", input);
            englishToCat(input);
            break;
        case 3:
            printf("Thank you for using the Cat Language Translator.\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
    return 0;
}