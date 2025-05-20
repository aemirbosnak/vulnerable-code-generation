//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

int main()
{
    char words[MAX_WORDS][20];
    int i, j, word_count = 0, flag = 0;

    printf("Enter sentences: ");

    // Get the sentences from the user
    for (i = 0; i < MAX_WORDS; i++)
    {
        gets(words[i]);
    }

    // Count the number of words in each sentence
    for (i = 0; i < MAX_WORDS; i++)
    {
        char *sentence = words[i];
        int word_num = 0;

        // Tokenize the sentence into words
        char *word = strtok(sentence, " ");

        // Count the number of words
        while (word)
        {
            word_num++;
            word = strtok(NULL, " ");
        }

        words[i][word_num] = '\0';
        word_count++;
    }

    // Check if the number of words in a sentence exceeds the threshold
    for (i = 0; i < MAX_WORDS; i++)
    {
        if (strlen(words[i]) > 200)
        {
            flag = 1;
        }
    }

    // Print the sentences with excessive word count
    if (flag)
    {
        printf("The following sentences have an excessive number of words:\n");
        for (i = 0; i < MAX_WORDS; i++)
        {
            if (strlen(words[i]) > 200)
            {
                printf("%s\n", words[i]);
            }
        }
    }

    return 0;
}