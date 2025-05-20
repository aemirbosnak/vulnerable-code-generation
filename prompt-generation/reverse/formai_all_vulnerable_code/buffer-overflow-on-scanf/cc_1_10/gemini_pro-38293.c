//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
const int SENTIMENT_SCORES[] = {
    [0] = 0,  // "a"
    [1] = 1,  // "an"
    [2] = 2,  // "and"
    [3] = 3,  // "are"
    [4] = 4,  // "as"
    [5] = 5,  // "at"
    [6] = 6,  // "be"
    [7] = 7,  // "but"
    [8] = 8,  // "by"
    [9] = 9,  // "can"
    [10] = 10, // "do"
    [11] = 11, // "for"
    [12] = 12, // "from"
    [13] = 13, // "have"
    [14] = 14, // "he"
    [15] = 15, // "her"
    [16] = 16, // "his"
    [17] = 17, // "I"
    [18] = 18, // "if"
    [19] = 19, // "in"
    [20] = 20, // "is"
    [21] = 21, // "it"
    [22] = 22, // "its"
    [23] = 23, // "me"
    [24] = 24, // "my"
    [25] = 25, // "not"
    [26] = 26, // "of"
    [27] = 27, // "on"
    [28] = 28, // "or"
    [29] = 29, // "our"
    [30] = 30, // "out"
    [31] = 31, // "she"
    [32] = 32, // "so"
    [33] = 33, // "some"
    [34] = 34, // "that"
    [35] = 35, // "the"
    [36] = 36, // "their"
    [37] = 37, // "them"
    [38] = 38, // "then"
    [39] = 39, // "there"
    [40] = 40, // "these"
    [41] = 41, // "they"
    [42] = 42, // "this"
    [43] = 43, // "those"
    [44] = 44, // "to"
    [45] = 45, // "too"
    [46] = 46, // "under"
    [47] = 47, // "up"
    [48] = 48, // "us"
    [49] = 49, // "very"
    [50] = 50, // "was"
    [51] = 51, // "we"
    [52] = 52, // "were"
    [53] = 53, // "what"
    [54] = 54, // "when"
    [55] = 55, // "where"
    [56] = 56, // "which"
    [57] = 57, // "who"
    [58] = 58, // "why"
    [59] = 59, // "will"
    [60] = 60, // "with"
    [61] = 61, // "would"
    [62] = 62, // "you"
    [63] = 63, // "your"
};

// Get the sentiment score for a word
int get_sentiment_score(const char *word) {
    int score = 0;
    for (int i = 0; i < strlen(word); i++) {
        score += SENTIMENT_SCORES[word[i] - 'a'];
    }
    return score;
}

// Get the sentiment score for a sentence
int get_sentence_sentiment(const char *sentence) {
    int score = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        score += get_sentiment_score(token);
        token = strtok(NULL, " ");
    }
    return score;
}

// Print the sentiment of a sentence
void print_sentiment(const char *sentence) {
    int score = get_sentence_sentiment(sentence);
    if (score > 0) {
        printf("The sentence '%s' is positive.\n", sentence);
    } else if (score < 0) {
        printf("The sentence '%s' is negative.\n", sentence);
    } else {
        printf("The sentence '%s' is neutral.\n", sentence);
    }
}

int main() {
    // Get the sentence from the user
    char sentence[1024];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Print the sentiment of the sentence
    print_sentiment(sentence);

    return 0;
}