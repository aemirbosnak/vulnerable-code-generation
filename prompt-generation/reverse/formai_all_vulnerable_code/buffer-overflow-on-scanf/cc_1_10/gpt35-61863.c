//FormAI DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_WORD_LENGTH 20
#define DICTIONARY_SIZE 6

const char *DICTIONARY[] = {"apple", "banana", "carrot", "dog", "elephant", "funny"};

char *strtolower(char *str)
{
    int i;
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
    return str;
}

void check_spelling(char *word)
{
    int i;
    int found = 0;
    char lower_word[MAX_WORD_LENGTH];
    strcpy(lower_word, word);
    strtolower(lower_word);

    for (i = 0; i < DICTIONARY_SIZE; i++)
    {
        if (strcmp(lower_word, DICTIONARY[i]) == 0)
        {
            printf("%s is spelled correctly!\n", word);
            found = 1;
            break;
        }
    }
    
    if (!found)
    {
        printf("Sorry, I am not smart enough to know how to spell %s.\n", word);
        printf("But, let me help you with a funny suggestion!\n");
        printf("How about %s?\n", DICTIONARY[rand() % DICTIONARY_SIZE]);
    }
}

int main()
{
    char input[MAX_WORD_LENGTH];
    printf("Welcome to the funny spell checking program!\n");
    printf("Please enter a word or type 'quit' to exit.\n\n");

    while (1)
    {
        printf("> ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0)
        {
            printf("Bye bye!");
            break;
        }
        check_spelling(input);
    }
    return 0;
}