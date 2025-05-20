//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <string.h>

int countWords(char sentence[])
{
    int i;
    int words = 1;
    for(i = 0; sentence[i] != '\0'; i++)
    {
        if(sentence[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int countCharacters(char sentence[])
{
    int i;
    int characters = 0;
    for(i = 0; sentence[i] != '\0'; i++)
    {
        if(sentence[i] != ' ')
        {
            characters++;
        }
    }
    return characters;
}

void findWord(char sentence[], char searchWord[])
{
    char *p;
    p = strstr(sentence, searchWord);
    if(p != NULL)
    {
        printf("%s is found in the sentence\n", searchWord);
    }
    else
    {
        printf("%s is not found in the sentence\n", searchWord);
    }
}

int main()
{
    char string[500];
    char search[50];
    printf("Enter a sentence: ");
    fgets(string, 500, stdin);
    printf("\n");
    printf("The sentence entered is:\n");
    printf("%s", string);
    printf("\n");
    printf("The number of words in the sentence is: %d\n", countWords(string));
    printf("\n");
    printf("The number of characters in the sentence is: %d\n", countCharacters(string));
    printf("\n");
    printf("Enter a word to search in the sentence: ");
    scanf("%s", search);
    printf("\n");
    findWord(string, search);
    return 0;
}