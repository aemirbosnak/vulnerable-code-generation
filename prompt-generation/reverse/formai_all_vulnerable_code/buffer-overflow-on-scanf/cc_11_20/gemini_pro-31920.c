//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the emotions
#define HAPPY 1
#define SAD 2
#define ANGRY 3
#define FEARFUL 4
#define SURPRISED 5

// Define the sentiment scores
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

// Define the stop words
const char *stop_words[] = {"a", "an", "the", "of", "in", "to", "for", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "will", "would", "should", "could", "may", "might", "must", "can", "cannot", "but", "or", "nor", "so", "because", "although", "though", "unless", "since", "while", "before", "after", "until", "with", "without", "upon", "above", "below", "between", "among", "around", "near", "far", "from", "to", "towards", "of", "off", "on", "upon", "under", "beneath", "over", "above", "around", "round", "out", "in", "into", "out", "through", "with", "without", "along", "by", "past", "under", "over", "above", "around", "round", "out", "in", "into", "out", "through", "with", "without", "like", "as", "than", "more", "less", "too", "enough", "all", "some", "any", "none", "each", "every", "other", "another", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "hundred", "thousand", "million", "billion", "trillion", "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth"};

// Define the sentiment lexicon
const char *sentiment_lexicon[] = {
    // Positive words
    "happy", "joyful", "excited", "thrilled", "ecstatic",
    "love", "adore", "cherish", "treasure", "value",
    "great", "wonderful", "amazing", "fantastic", "superb",
    "beautiful", "pretty", "handsome", "gorgeous", "stunning",
    "nice", "kind", "friendly", "compassionate", "caring",

    // Negative words
    "sad", "depressed", "unhappy", "miserable", "despair",
    "hate", "despise", "loathe", "detest", "abhor",
    "bad", "terrible", "horrible", "awful", "dreadful",
    "ugly", "repulsive", "hideous", "grotesque", "disgusting",
    "mean", "cruel", "evil", "wicked", "hateful",
};

// Main function
int main()
{
    // Get the input text from the user
    char input[1024];
    printf("Enter some text: ");
    scanf("%s", input);

    // Tokenize the input text
    char *tokens[1024];
    int num_tokens = 0;
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Remove the stop words from the token list
    int num_filtered_tokens = 0;
    for (int i = 0; i < num_tokens; i++)
    {
        int is_stop_word = 0;
        for (int j = 0; j < sizeof(stop_words) / sizeof(char *); j++)
        {
            if (strcmp(tokens[i], stop_words[j]) == 0)
            {
                is_stop_word = 1;
                break;
            }
        }
        if (!is_stop_word)
        {
            tokens[num_filtered_tokens++] = tokens[i];
        }
    }

    // Compute the sentiment score of the input text
    int sentiment_score = 0;
    for (int i = 0; i < num_filtered_tokens; i++)
    {
        int is_positive = 0;
        int is_negative = 0;
        for (int j = 0; j < sizeof(sentiment_lexicon) / sizeof(char *); j++)
        {
            if (strcmp(tokens[i], sentiment_lexicon[j]) == 0)
            {
                if (j < sizeof(sentiment_lexicon) / sizeof(char *) / 2)
                {
                    is_positive = 1;
                }
                else
                {
                    is_negative = 1;
                }
                break;
            }
        }
        if (is_positive)
        {
            sentiment_score += POSITIVE;
        }
        else if (is_negative)
        {
            sentiment_score += NEGATIVE;
        }
    }

    // Print the sentiment score of the input text
    if (sentiment_score > 0)
    {
        printf("The input text has a positive sentiment.\n");
    }
    else if (sentiment_score < 0)
    {
        printf("The input text has a negative sentiment.\n");
    }
    else
    {
        printf("The input text has a neutral sentiment.\n");
    }

    return 0;
}