//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <string.h>

// Define the sentiment analysis function
int sentiment_analysis(char *text) {
    // Create a dictionary of positive and negative words
    char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
    char *negative_words[] = {"bad", "terrible", "horrible", "awful", "dreadful"};

    // Initialize the sentiment score
    int sentiment_score = 0;

    // Tokenize the text
    char *tokens[100];
    int num_tokens = tokenize(text, tokens);

    // Iterate over the tokens and update the sentiment score
    for (int i = 0; i < num_tokens; i++) {
        // Check if the token is a positive word
        for (int j = 0; j < sizeof(positive_words) / sizeof(char *); j++) {
            if (strcmp(tokens[i], positive_words[j]) == 0) {
                sentiment_score++;
                break;
            }
        }

        // Check if the token is a negative word
        for (int j = 0; j < sizeof(negative_words) / sizeof(char *); j++) {
            if (strcmp(tokens[i], negative_words[j]) == 0) {
                sentiment_score--;
                break;
            }
        }
    }

    // Return the sentiment score
    return sentiment_score;
}

// Define the tokenize function
int tokenize(char *text, char *tokens[]) {
    // Initialize the number of tokens
    int num_tokens = 0;

    // Create a strtok context
    char *context = NULL;

    // Tokenize the text
    char *token = strtok_r(text, " ", &context);
    while (token != NULL) {
        // Add the token to the array
        tokens[num_tokens++] = token;

        // Get the next token
        token = strtok_r(NULL, " ", &context);
    }

    // Return the number of tokens
    return num_tokens;
}

// Define the main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter the text: ");
    gets(text);

    // Perform sentiment analysis on the text
    int sentiment_score = sentiment_analysis(text);

    // Print the sentiment score
    printf("The sentiment score is: %d\n", sentiment_score);

    // Return 0
    return 0;
}