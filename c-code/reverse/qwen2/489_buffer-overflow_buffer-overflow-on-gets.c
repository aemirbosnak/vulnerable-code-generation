#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

int is_positive(const char *word) {
    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 ||
        strcmp(word, "happy") == 0 || strcmp(word, "excited") == 0)
        return 1;
    return 0;
}

int is_negative(const char *word) {
    if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 ||
        strcmp(word, "sad") == 0 || strcmp(word, "angry") == 0)
        return 1;
    return 0;
}

void analyze_sentiment() {
    char sentence[MAX_LEN];
    int pos_count = 0, neg_count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    char *token = strtok(sentence, " \n");
    while (token != NULL) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        if (is_positive(token)) pos_count++;
        else if (is_negative(token)) neg_count++;
        token = strtok(NULL, " \n");
    }

    if (pos_count > neg_count) printf("Positive\n");
    else if (neg_count > pos_count) printf("Negative\n");
    else printf("Neutral\n");
}

int main() {
    analyze_sentiment();
    return 0;
}
