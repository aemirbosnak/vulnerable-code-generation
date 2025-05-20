//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    int positive = 0;
    int negative = 0;
    int neutral = 0;
    
    printf("Enter a sentence:\n");
    scanf("%[^\n]", sentence);
    
    char *word = strtok(sentence, " ");
    
    while (word != NULL)
    {
        if (strcmp(word, "love") == 0 || strcmp(word, "passion") == 0 || strcmp(word, "heart") == 0)
        {
            positive++;
        }
        else if (strcmp(word, "hate") == 0 || strcmp(word, "kill") == 0 || strcmp(word, "death") == 0)
        {
            negative++;
        }
        else
        {
            neutral++;
        }
        word = strtok(NULL, " ");
    }
    
    printf("\nSentiment Analysis:\n");
    
    if (positive > negative && positive > neutral)
    {
        printf("Oh, joyous tidings! Your words speak of love's sweet embrace.\n");
    }
    else if (negative > positive && negative > neutral)
    {
        printf("Alas, your words are heavy with the burden of hate and death.\n");
    }
    else if (neutral > positive && neutral > negative)
    {
        printf("Your words are impartial, neither shaded with light nor darkness.\n");
    }
    else
    {
        printf("Your words are a tempest of emotions. Perhaps take time to gather your thoughts.\n");
    }
    
    return 0;
}