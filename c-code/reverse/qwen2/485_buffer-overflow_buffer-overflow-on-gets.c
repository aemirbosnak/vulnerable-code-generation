#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

int is_positive(char *word) {
    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 ||
        strcmp(word, "happy") == 0 || strcmp(word, "excited") == 0)
        return 1;
    return 0;
}

int is_negative(char *word) {
    if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 ||
        strcmp(word, "sad") == 0 || strcmp(word, "angry") == 0)
        return 1;
    return 0;
}

void analyze_sentiment() {
    char sentence[MAX_LEN];
    int pos_count = 0, neg_count = 0;

    printf("Enter a sentence: ");
    gets(sentence);

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        if (is_positive(token)) pos_count++;
        else if (is_negative(token)) neg_count++;
        token = strtok(NULL, " ");
    }

    printf("Positive words: %d\n", pos_count);
    printf("Negative words: %d\n", neg_count);
}

int main() {
    analyze_sentiment();
    return 0;
}
