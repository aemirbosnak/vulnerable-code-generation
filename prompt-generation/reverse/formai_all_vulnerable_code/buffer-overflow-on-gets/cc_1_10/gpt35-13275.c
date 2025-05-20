//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include<stdio.h>
#include<string.h>

// declaring the function to count words
int countWords(char *string, char *word);

int main()
{
    char string[100], word[20];
    int count = 0;

    printf("Enter a string: ");
    gets(string);

    printf("Enter the word to count: ");
    gets(word);

    count = countWords(string, word);

    printf("The frequency of '%s' in the string is %d\n", word, count);

    return 0;
}

// function to count words
int countWords(char *string, char *word)
{
    int len, i, j, count = 0;

    len = strlen(word);

    for(i=0; string[i]!='\0'; i++)
    {
        // check if 'word' is present in the 'string'
        if(string[i] == word[0])
        {
            // check if the word is present
            for(j=0; j<len; j++)
            {
                if(word[j] != string[i+j])
                {
                    break;
                }
            }

            // increase the count if the word is found in the string
            if(j == len)
            {
                count++;
            }
        }
    }

    return count;
}