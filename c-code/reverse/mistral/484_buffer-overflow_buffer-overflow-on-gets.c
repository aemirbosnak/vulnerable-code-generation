#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256

int is_positive(char *sentence) {
    int score = 0, pos_words = 0, neg_words = 0;
    char *pos_keywords[] = {"happy", "joy", "love", "excited", "pleased"};
    char *neg_keywords[] = {"sad", "miserable", "angry", "disappointed", "frustrated"};

    for (int i = 0; i < strlen(sentence); ++i) {
        if (i > MAX_INPUT - 1) return -1; // Buffer overflow check
        sentence[i] = tolower(sentence[i]);
    }

    for (int i = 0; i < 5; ++i) {
        if (strstr(sentence, pos_keywords[i]) != NULL) ++pos_words;
        if (strstr(sentence, neg_keywords[i]) != NULL) ++neg_words;
    }

    score = pos_words - neg_words;
    return score > 0 ? score : 0;
}

int main() {
    char input[MAX_INPUT];
    printf("Enter a sentence: ");
    gets(input);
    printf("Sentiment score: %d\n", is_positive(input));
    return 0;
}
