#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define NUM_WORDS 10

typedef struct {
    char word[50];
    int sentiment;
} Word;

int main() {
    Word words[NUM_WORDS] = {
        {"I", 1},
        {"LOVE", 1},
        {"HAPPY", 1},
        {"EXCITED", 1},
        {"YES", 1},
        {"GOOD", 1},
        {"PLEASE", 0},
        {"SAD", 0},
        {"NO", 0},
        {"BAD", 0}
    };

    char input[1000];
    char *token;
    int positive = 0, negative = 0, total = 0;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, " .,!?");
    while (token != NULL) {
        for (int i = 0; i < NUM_WORDS; ++i) {
            if (strcmp(token, words[i].word) == 0) {
                total++;
                if (words[i].sentiment > 0)
                    positive++;
                else
                    negative++;
                break;
            }
        }
        token = strtok(NULL, " .,!?");
    }

    printf("Positive words: %d\n", positive);
    printf("Negative words: %d\n", negative);
    printf("Total words: %d\n", total);

    if (total > 0)
        printf("Sentiment score: %.2f\n", (float)positive / total);

    return 0;
}
