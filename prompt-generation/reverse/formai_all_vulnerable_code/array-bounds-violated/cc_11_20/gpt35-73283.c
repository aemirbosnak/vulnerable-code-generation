//FormAI DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 500
#define MAX_WORD_LENGTH 50

int main()
{
    char input_str[MAX_WORD_LENGTH];
    char words_arr[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS];
    int i, j;
    int num_words = 0;

    printf("Enter a phrase with paranoid code: ");
    fgets(input_str, MAX_WORD_LENGTH, stdin);
    input_str[strlen(input_str) - 1] = '\0';

    for (i = 0; i < strlen(input_str); i++)
    {
        if (input_str[i] == ' ')
        {
            num_words++;
        }
    }

    num_words++;

    for (i = 0; i < num_words; i++)
    {
        for (j = 0; j < MAX_WORD_LENGTH; j++)
        {
            words_arr[i][j] = '\0';
        }
        count[i] = 0;
    }

    int word_pos = 0;
    int char_pos = 0;

    for (i = 0; i < strlen(input_str); i++)
    {
        if (input_str[i] != ' ' && input_str[i] != '\t' && input_str[i] != '\n')
        {
            if (char_pos < MAX_WORD_LENGTH)
            {
                words_arr[word_pos][char_pos++] = input_str[i];
            }
        }
        else
        {
            word_pos++;
            char_pos = 0;
        }
    }

    int flag;

    for (i = 0; i < num_words; i++)
    {
        flag = 1;
        for (j = 0; j < strlen(words_arr[i]); j++)
        {
            if (words_arr[i][j] < '0' || words_arr[i][j] > '9')
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1 && strlen(words_arr[i]) > 2)
        {
            count[i] = 1;
        }
    }

    printf("\nCode Count:\n");

    for (i = 0; i < num_words; i++)
    {
        if (count[i] == 1)
        {
            printf("Code Word: %s\n", words_arr[i]);
        }
    }

    return 0;
}