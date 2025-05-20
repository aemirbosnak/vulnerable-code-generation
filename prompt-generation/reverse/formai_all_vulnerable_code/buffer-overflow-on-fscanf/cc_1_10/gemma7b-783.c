//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    int i, sentiment_score = 0, word_count = 0;
    FILE *fp;

    // Open the file
    fp = fopen("poem.txt", "r");

    // Read the file content
    fscanf(fp, "%[^\n]", str);

    // Close the file
    fclose(fp);

    // Tokenize the text
    char *token = strtok(str, " ");

    // Iterate over the tokens
    while (token)
    {
        // Check if the token is a noun
        if (is_noun(token))
        {
            word_count++;
            sentiment_score += sentiment_score_for_noun(token);
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score
    sentiment_score /= word_count;

    // Print the sentiment score
    printf("The sentiment score is: %d", sentiment_score);

    return 0;
}

int is_noun(char *word)
{
    // Check if the word is a noun
    return isupper(word[0]) || isalpha(word[0]) && word[0] != 'a';
}

int sentiment_score_for_noun(char *word)
{
    // Assign a sentiment score for each noun
    switch (word[0])
    {
        case 'a':
            return 1;
        case 'e':
            return -1;
        case 'i':
            return 2;
        case 'o':
            return -2;
        default:
            return 0;
    }
}