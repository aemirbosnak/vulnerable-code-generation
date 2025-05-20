//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void analyze_word(char *word)
{
    int length = strlen(word);
    char flag = 0;

    // Check for common spam words
    char *spam_words[] = {"free", "lottery", "miracle", "prize", "offer", "debt", "miracle"};
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(word, spam_words[i]) == 0)
        {
            flag = 1;
            break;
        }
    }

    // Check for punctuation marks
    if (length > 1 && word[length - 1] == '.' || word[length - 1] == '!' || word[length - 1] == '?')
    {
        flag = 1;
    }

    // Check for capital letters
    for (int i = 0; i < length; i++)
    {
        if (isupper(word[i]))
        {
            flag = 1;
        }
    }

    // If flag is 1, the word is spam
    if (flag)
    {
        printf("%s is a spam word.\n", word);
    }
}

int main()
{
    char word[MAX];

    // Get the word from the user
    printf("Enter a word: ");
    scanf("%s", word);

    // Analyze the word
    analyze_word(word);

    return 0;
}