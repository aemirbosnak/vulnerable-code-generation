//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTIMENT_LENGTH 255

int sentiment_analysis(char *sentence)
{
    int positive_words = 0, negative_words = 0, neutral_words = 0;
    char *positive_words_list[] = {"happy", "joy", "good", "great", "excellent"};
    char *negative_words_list[] = {"sad", "angry", "bad", "terrible", "awful"};
    char *neutral_words_list[] = {"okay", "fine", "neutral", "indifferent"};

    // Iterate over the sentence words and check if they are in the positive, negative, or neutral words list
    char *word = strtok(sentence, " ");
    while (word)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(word, positive_words_list[i]) == 0)
            {
                positive_words++;
            }
            else if (strcmp(word, negative_words_list[i]) == 0)
            {
                negative_words++;
            }
            else if (strcmp(word, neutral_words_list[i]) == 0)
            {
                neutral_words++;
            }
        }

        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score
    int sentiment_score = (positive_words - negative_words) * 100 / (positive_words + negative_words + neutral_words);

    return sentiment_score;
}

int main()
{
    char sentence[] = "I am happy today, but I am sad that I have to go to school.";

    int sentiment_score = sentiment_analysis(sentence);

    printf("The sentiment score for the sentence is: %d", sentiment_score);

    return 0;
}