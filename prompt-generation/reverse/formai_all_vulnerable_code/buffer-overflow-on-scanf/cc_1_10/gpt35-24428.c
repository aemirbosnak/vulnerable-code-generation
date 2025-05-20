//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

// Function to translate English to Alien language
void toAlienLanguage(char sentence[])
{
    char alienSentence[1000];

    for (int i = 0; i < strlen(sentence); i++)
    {
        // Convert vowels to "o" and consonants to "p"
        if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u'
            || sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U')
        {
            alienSentence[i] = 'o';
        }
        else if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z'))
        {
            alienSentence[i] = 'p';
        }
        else
        {
            alienSentence[i] = sentence[i];
        }
    }

    alienSentence[strlen(sentence)] = '\0';

    printf("In Alien Language: %s\n", alienSentence);
}

int main()
{
    char sentence[1000];
    int choice;

    printf("Welcome to the Alien Language Translator!\n");

    do
    {
        printf("\nPlease enter the sentence you want to translate: ");
        scanf(" %[^\n]s", sentence);

        toAlienLanguage(sentence);

        printf("\nDo you want to translate another sentence? (1/0): ");
        scanf("%d", &choice);

    } while (choice != 0);

    printf("\nThank you for using our Alien Language Translator! Goodbye!\n");

    return 0;
}