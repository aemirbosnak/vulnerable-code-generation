//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Function to convert English to Alien Language
char* engToAlien(char* englishWord)
{
    int length = strlen(englishWord);
    char alienWord[length+1];
    for (int i=0; i<length; i++)
    {
        if (englishWord[i] == 'a')
            alienWord[i] = 'z';
        else if (englishWord[i] == 'b')
            alienWord[i] = 'y';
        else if (englishWord[i] == 'c')
            alienWord[i] = 'x';
        else if (englishWord[i] == 'd')
            alienWord[i] = 'w';
        else if (englishWord[i] == 'e')
            alienWord[i] = 'v';
        else if (englishWord[i] == 'f')
            alienWord[i] = 'u';
        else if (englishWord[i] == 'g')
            alienWord[i] = 't';
        else if (englishWord[i] == 'h')
            alienWord[i] = 's';
        else if (englishWord[i] == 'i')
            alienWord[i] = 'r';
        else if (englishWord[i] == 'j')
            alienWord[i] = 'q';
        else if (englishWord[i] == 'k')
            alienWord[i] = 'p';
        else if (englishWord[i] == 'l')
            alienWord[i] = 'o';
        else if (englishWord[i] == 'm')
            alienWord[i] = 'n';
        else if (englishWord[i] == 'n')
            alienWord[i] = 'm';
        else if (englishWord[i] == 'o')
            alienWord[i] = 'l';
        else if (englishWord[i] == 'p')
            alienWord[i] = 'k';
        else if (englishWord[i] == 'q')
            alienWord[i] = 'j';
        else if (englishWord[i] == 'r')
            alienWord[i] = 'i';
        else if (englishWord[i] == 's')
            alienWord[i] = 'h';
        else if (englishWord[i] == 't')
            alienWord[i] = 'g';
        else if (englishWord[i] == 'u')
            alienWord[i] = 'f';
        else if (englishWord[i] == 'v')
            alienWord[i] = 'e';
        else if (englishWord[i] == 'w')
            alienWord[i] = 'd';
        else if (englishWord[i] == 'x')
            alienWord[i] = 'c';
        else if (englishWord[i] == 'y')
            alienWord[i] = 'b';
        else if (englishWord[i] == 'z')
            alienWord[i] = 'a';
        else
            alienWord[i] = englishWord[i];
    }
    alienWord[length] = '\0';
    return alienWord;
}

int main()
{
    char englishWord[20];
    printf("Enter a word in English: ");
    scanf("%s", englishWord);
    
    char* alienWord = engToAlien(englishWord);
    printf("The word in Alien Language is: %s\n", alienWord);

    return 0;
}