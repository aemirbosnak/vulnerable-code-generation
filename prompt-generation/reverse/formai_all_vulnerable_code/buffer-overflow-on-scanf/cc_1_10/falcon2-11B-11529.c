//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 100

int main()
{
    char words[MAX_WORDS][MAX_LEN];
    int num_words = 0;
    int i, j;
    int allowed[5] = {'A','E','I','O','U'};
    int flag = 0;

    // Get the number of words
    printf("Enter the number of words: ");
    scanf("%d", &num_words);

    // Get the words
    printf("Enter the words:\n");
    for(i=0; i<num_words; i++)
    {
        fgets(words[i], MAX_LEN, stdin);
        words[i][strcspn(words[i], "\n")] = '\0';
    }

    // Check for spelling errors
    for(i=0; i<num_words; i++)
    {
        for(j=0; j<strlen(words[i]); j++)
        {
            if(!strchr(allowed, words[i][j]))
            {
                printf("Error: '%c' is not allowed\n", words[i][j]);
                flag = 1;
            }
        }
    }

    // Print the results
    if(flag)
    {
        printf("There are spelling errors.\n");
    }
    else
    {
        printf("No spelling errors found.\n");
    }

    return 0;
}