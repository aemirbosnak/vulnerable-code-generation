//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

int main()
{
    char text[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS], i=0, j, count;

    printf("Enter text: ");

    // read text and split into words
    while(scanf("%s", text) == 1)
    {
        // remove non-alphabetic characters from start and end of word
        i=0;
        while(!isalpha(text[i]) && i < strlen(text))
            i++;
        j=strlen(text)-1;
        while(!isalpha(text[j]) && j >= 0)
            j--;

        if(j >= i)
        {
            strncpy(words[count], &text[i], j-i+1);
            words[count][j-i+1] = '\0';
            count++;
        }
    }

    // count frequency of each word
    for(i=0;i<count;i++)
    {
        freq[i] = 1;
        for(j=i+1;j<count;j++)
        {
            if(strcmp(words[i], words[j]) == 0)
            {
                freq[i]++;
                // mark words[j] as processed
                words[j][0] = '\0';
            }
        }
    }

    // print frequency of each word
    printf("\nWord frequency:\n");
    for(i=0;i<count;i++)
    {
        if(words[i][0] != '\0')
            printf("%-20s %5d\n", words[i], freq[i]);
    }

    return 0;
}