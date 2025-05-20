//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our mystical lexicon of words and their magical aura
struct Lexicon {
    char *word;
    int sentiment;
};

// A spellbook of known words and their sentiments
struct Lexicon lexicon[] = {
    {"love", 1}, {"hate", -1}, {"happy", 1}, {"sad", -1},
    {"excited", 1}, {"angry", -1}, {"beautiful", 1}, {"ugly", -1}
};

// The length of our lexicon, a gateway to emotions
int lexiconLength = sizeof(lexicon) / sizeof(lexicon[0]);

// The main function, where our adventure begins
int main() {
    // Prepare to weave the tapestry of emotions
    char input[1024];
    int result = 0;  // The net sentiment, a balance of feelings

    printf("Utter the words, traveler, and I shall unveil their hidden emotions.\n");
    scanf("%s", input);

    // Tokenize the text, breaking it into words
    char *tokens[100];
    int tokenCount = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, " ");
    }

    // Traverse the words, casting enchantments upon them
    for (int i = 0; i < tokenCount; i++) {
        for (int j = 0; j < lexiconLength; j++) {
            if (strcmp(tokens[i], lexicon[j].word) == 0) {
                // A match! The sentiment reverberates through our spell
                result += lexicon[j].sentiment;
                break;
            }
        }
    }

    // Reveal the sentiment, a symphony of emotions
    printf("Lo and behold, the sentiment entwined within those words is: %d\n", result);

    return 0; // Our journey ends, leaving a trail of analyzed emotions
}