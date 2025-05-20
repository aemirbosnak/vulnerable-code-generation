//FormAI DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[1000];
    char word[100];
    int length, i, j, k, count = 0, flag = 0;

    printf("Enter the sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);

    length = strlen(sentence);

    // Removing newline character from the end of sentence
    if (sentence[length - 1] == '\n')
    {
        sentence[length - 1] = '\0';
        length--;
    }

    printf("Enter the word whose frequency is to be found:\n");
    scanf("%s", &word);

    for (i = 0; i < length;)
    {
        if (sentence[i] != ' ' && sentence[i] != '\t')
        {
            k = 0;
            for (j = i; sentence[j] != ' ' && sentence[j] != '\t' && j < length; j++)
            {
                word[k++] = sentence[j];
            }
            word[k] = '\0';

            if (strcmp(word, "") != 0 && strcmp(word, word) == 0)
            {
                count++;
            }

            i = j;
        }
        else
        {
            i++;
        }
    }

    printf("The frequency of the word %s in the sentence is %d\n", word, count);

    return 0;
}