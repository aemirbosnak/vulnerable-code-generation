//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert the given text to lowercase
void convertToLowercase(char *text)
{
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        text[i] = tolower(text[i]);
    }
}

// Function to count the positive and negative words in the given text
void getSentimentCount(char *text, int *positiveCount, int *negativeCount)
{
    char word[100];
    FILE *positiveWordsFile = fopen("positive_words.txt", "r");
    FILE *negativeWordsFile = fopen("negative_words.txt", "r");

    // Loop through every word in the text and check if it is present in the positive or negative words file
    while (sscanf(text, "%s", word) == 1)
    {
        convertToLowercase(word);
        char c;
        int foundPositive = 0, foundNegative = 0;

        // Check for positive words
        while ((c = fgetc(positiveWordsFile)) != EOF)
        {
            ungetc(c, positiveWordsFile);
            if (fscanf(positiveWordsFile, "%s", word) == 1)
            {
                convertToLowercase(word);
                if (strcmp(word, "") != 0 && strcmp(word, " ") != 0 && strcmp(word, "\n") != 0 && strcmp(word, "\r") != 0 && strcmp(word, "\t") != 0 && strcmp(word, "\0") != 0)
                {
                    if (strcmp(word, text) == 0)
                    {
                        (*positiveCount)++;
                        foundPositive = 1;
                        break;
                    }
                }
            }
        }

        // Check for negative words
        while ((c = fgetc(negativeWordsFile)) != EOF)
        {
            ungetc(c, negativeWordsFile);
            if (fscanf(negativeWordsFile, "%s", word) == 1)
            {
                convertToLowercase(word);
                if (strcmp(word, "") != 0 && strcmp(word, " ") != 0 && strcmp(word, "\n") != 0 && strcmp(word, "\r") != 0 && strcmp(word, "\t") != 0 && strcmp(word, "\0") != 0)
                {
                    if (strcmp(word, text) == 0)
                    {
                        (*negativeCount)++;
                        foundNegative = 1;
                        break;
                    }
                }
            }
        }

        // Reset the file pointers to the beginning of the files
        fseek(positiveWordsFile, 0, SEEK_SET);
        fseek(negativeWordsFile, 0, SEEK_SET);

        // If the word is not present in any of the files, consider it neutral
        if (!foundPositive && !foundNegative)
        {
            // Do nothing
        }

        text += strlen(word);

        // If there are any leading spaces, skip them
        while (*text == ' ')
        {
            text++;
        }
    }

    // Close the files
    fclose(positiveWordsFile);
    fclose(negativeWordsFile);
}

// Function to calculate the sentiment score
float calculateSentimentScore(int positiveCount, int negativeCount)
{
    float sentimentScore;

    if (positiveCount == 0 && negativeCount == 0)
    {
        sentimentScore = 0;
    }
    else
    {
        sentimentScore = (float)(positiveCount - negativeCount) / (positiveCount + negativeCount);
    }

    return sentimentScore;
}

int main()
{
    char text[1000];
    printf("Enter some text to analyze the sentiment: ");
    fgets(text, sizeof(text), stdin);

    // Remove the newline character from the text
    if (text[strlen(text) - 1] == '\n')
    {
        text[strlen(text) - 1] = '\0';
    }

    int positiveCount = 0, negativeCount = 0;
    getSentimentCount(text, &positiveCount, &negativeCount);

    // Calculate the sentiment score
    float sentimentScore = calculateSentimentScore(positiveCount, negativeCount);

    // Determine the sentiment
    if (sentimentScore > 0.3)
    {
        printf("\nThe sentiment of the text is Positive! \n");
    }
    else if (sentimentScore < -0.3)
    {
        printf("\nThe sentiment of the text is Negative! \n");
    }
    else
    {
        printf("\nThe sentiment of the text is Neutral! \n");
    }

    return 0;
}