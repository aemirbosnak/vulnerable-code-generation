//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
// Sentiment Analysis Tool
#include <stdio.h>
#include <string.h>

// Function to calculate sentiment score of the input text
int sentimentScore(char text[])
{
    int score = 0;
    char word[100];
    char *token = strtok(text, " "); // Tokenize input text into words

    while (token != NULL) // Loop through each word
    {
        strcpy(word, token); // Copy word into a string
        int len = strlen(word);

        // Check if word ends with '?' or '!'
        if (word[len - 1] == '?' || word[len - 1] == '!')
        {
            // Remove punctuation from end of word
            word[len - 1] = '\0';
            len--;
        }

        // Check if the word has a positive or negative sentiment
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0)
        {
            score++;
        }
        else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "horrible") == 0)
        {
            score--;
        }

        token = strtok(NULL, " "); // Move to next word
    }

    return score;
}

int main()
{
    char text[1000];

    printf("Enter your text: ");
    fgets(text, sizeof(text), stdin); // Read input text from user

    // Remove newline character from input text
    int len = strlen(text);
    if (text[len-1] == '\n')
    {
        text[len-1] = '\0';
    }

    // Calculate sentiment score of input text
    int score = sentimentScore(text);

    if (score > 0) // Positive sentiment
    {
        printf("The sentiment score of your text is positive (%d).\n", score);
    }
    else if (score < 0) // Negative sentiment
    {
        printf("The sentiment score of your text is negative (%d).\n", score);
    }
    else // Neutral sentiment
    {
        printf("The sentiment score of your text is neutral (%d).\n", score);
    }

    return 0;
}