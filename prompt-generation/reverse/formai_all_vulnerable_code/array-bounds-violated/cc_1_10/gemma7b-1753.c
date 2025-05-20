//Gemma-7B DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main()
{
    char text[] = "Montague and Capulet, two feuding families, live in Verona. The Montagues and Capulets have been at odds for generations, and the tension between the two families is thick as a fog on a cold winter night.";

    // Step 1: Convert the text to lowercase
    char lower_text[200];
    int i = 0;
    for (i = 0; text[i] != '\0'; i++)
    {
        lower_text[i] = text[i] - 32;
    }

    // Step 2: Remove punctuation from the text
    char no_punc_text[200];
    int j = 0;
    for (i = 0; lower_text[i] != '\0'; i++)
    {
        if (lower_text[i] >= 'a' && lower_text[i] <= 'z')
        {
            no_punc_text[j] = lower_text[i];
            j++;
        }
    }

    // Step 3: Find the words that appear only once in the text
    char unique_words[100];
    int k = 0;
    for (i = 0; no_punc_text[i] != '\0'; i++)
    {
        int flag = 0;
        for (j = 0; unique_words[j] != '\0'; j++)
        {
            if (no_punc_text[i] == unique_words[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            unique_words[k] = no_punc_text[i];
            k++;
        }
    }

    // Step 4: Print the unique words
    printf("The unique words in the text are:\n");
    for (i = 0; unique_words[i] != '\0'; i++)
    {
        printf("%s ", unique_words[i]);
    }

    return 0;
}