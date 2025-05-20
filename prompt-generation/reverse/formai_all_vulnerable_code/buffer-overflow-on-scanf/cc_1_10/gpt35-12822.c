//FormAI DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a word is spelled correctly or not
int checkSpelling(char*);

int main()
{
    char word[50];
    int option, res;

    printf("\nRETRO STYLE SPELL CHECKER\n");

    do
    {
        printf("\nEnter a word: ");
        scanf("%s", &word);
        res = checkSpelling(word);
        
        // Display the result of spell checking
        if(res == 1)
            printf("%s is spelled correctly!", word);
        else
            printf("%s is not spelled correctly. Did you mean %s?", word, res);
        
        printf("\nDo you want to continue (1/0)? ");
        scanf("%d", &option);
        
    } while(option != 0);
    
    printf("\nThanks for using Retro Spell Checker!\n");
    
    return 0;
}


int checkSpelling(char* word)
{
    char dictionary[][50] = {"apple", "banana", "carrot", "dog", "elephant", "frog", "giraffe", "hamburger", "internet", "jacket", "kangaroo", "lion", "mountain", "newspaper", "octopus", "pizza", "queen", "rabbit", "strawberry", "television", "umbrella", "violin", "watermelon", "xylophone", "yellow", "zebra"};
    int length = sizeof(dictionary)/sizeof(dictionary[0]);
    
    char temp[50];      // to store the lower case version of word
    strcpy(temp, word);
    for(int i = 0; temp[i]; i++)
        temp[i] = tolower(temp[i]);

    // Linear Search
    for(int i = 0; i < length; i++)
        if(strcmp(dictionary[i], temp) == 0)
            return 1;

    // Edit Distance
    int min = 50, dist;
    char closest[50];

    for(int i = 0; i < length; i++)
    {
        dist = 0;
        for(int j = 0; word[j] && dictionary[i][j]; j++)
            dist += (word[j] != dictionary[i][j]);

        if(dist < min)
        {
            min = dist;
            strcpy(closest, dictionary[i]);
        }
    }

    if(min <= 2)
        return closest;     // if edit distance is less than or equal to 2, return the closest match

    return 0;       // the word is not spelled correctly
}