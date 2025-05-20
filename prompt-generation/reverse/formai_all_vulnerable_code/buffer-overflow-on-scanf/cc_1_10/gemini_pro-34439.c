//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Get the input string.
    char *input = malloc(1024);
    printf("Enter a string: ");
    scanf("%s", input);

    // Tokenize the input string.
    char **tokens = malloc(1024 * sizeof(char *));
    int num_tokens = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Create a sentiment dictionary.
    typedef struct {
        char *word;
        int sentiment;
    } sentiment_entry;

    sentiment_entry sentiment_dict[] = {
        { "good", 1 },
        { "bad", -1 },
        { "great", 2 },
        { "terrible", -2 },
        { "excellent", 3 },
        { "awful", -3 },
        { "amazing", 4 },
        { "horrible", -4 },
        { "superb", 5 },
        { "dreadful", -5 }
    };

    // Compute the sentiment of the input string.
    int sentiment = 0;
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < sizeof(sentiment_dict) / sizeof(sentiment_dict[0]); j++) {
            if (strcmp(tokens[i], sentiment_dict[j].word) == 0) {
                sentiment += sentiment_dict[j].sentiment;
            }
        }
    }

    // Print the sentiment of the input string.
    printf("The sentiment of the string is: %d\n", sentiment);

    // Free the allocated memory.
    free(input);
    free(tokens);

    return 0;
}