//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

// Define sentiment lexicon
char *positive_words[] = {
    "good", "great", "excellent", "wonderful", "amazing",
    "awesome", "superb", "fantastic", "marvelous", "incredible"
};

char *negative_words[] = {
    "bad", "terrible", "awful", "horrible", "dreadful",
    "appalling", "disgusting", "sickening", "nauseating", "repulsive"
};

// Tokenize a string into an array of words
char **tokenize(char *str) {
    char **words = malloc(MAX_WORDS * sizeof(char *));
    int i = 0;
    char *word = strtok(str, " ");
    while (word != NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }
    words[i] = NULL;
    return words;
}

// Convert a string to lowercase
char *to_lowercase(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

// Analyse sentiment of a text
int analyse_sentiment(char *text) {
    int positive_count = 0;
    int negative_count = 0;

    // Tokenize the text
    char **words = tokenize(text);

    // Convert each word to lowercase and count its sentiment
    int i;
    for (i = 0; words[i] != NULL; i++) {
        char *word = to_lowercase(words[i]);
        int j;
        for (j = 0; j < 10; j++) {
            if (strcmp(word, positive_words[j]) == 0) {
                positive_count++;
                break;
            }
            if (strcmp(word, negative_words[j]) == 0) {
                negative_count++;
                break;
            }
        }
    }

    // Free memory allocated for words
    free(words);

    // Return the sentiment score
    return positive_count - negative_count;
}

int main() {
    // Get the input text from the user
    char text[MAX_LEN];
    printf("Enter your text: ");
    gets(text);

    // Analyse the sentiment of the text
    int sentiment = analyse_sentiment(text);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment);
    if (sentiment > 0) {
        printf("The text has a positive sentiment.\n");
    } else if (sentiment < 0) {
        printf("The text has a negative sentiment.\n");
    } else {
        printf("The text has a neutral sentiment.\n");
    }

    return 0;
}