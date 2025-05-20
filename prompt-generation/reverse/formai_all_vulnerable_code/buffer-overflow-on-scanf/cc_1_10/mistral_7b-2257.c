//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define WORD_LENGTH 20

typedef struct {
    char word[WORD_LENGTH];
    int sentiment;
} Word;

Word words[MAX_WORDS] = {
    {"good", 1},
    {"great", 1},
    {"happy", 1},
    {"joy", 1},
    {"love", 1},
    {"nice", 1},
    {"positive", 1},
    {"satisfied", 1},
    {"smile", 1},
    {"yes", 1},

    {"bad", -1},
    {"terrible", -1},
    {"sad", -1},
    {"miserable", -1},
    {"angry", -1},
    {"disappointed", -1},
    {"no", -1},
    {"negative", -1},
    {"hate", -1},
    {"suffer", -1},
};

int analyze(char *text) {
    char current_word[WORD_LENGTH];
    int score = 0;
    bool is_word_ended = false;

    for (int i = 0; i < strlen(text); ++i) {
        if (isspace(text[i])) {
            if (!is_word_ended) {
                current_word[i] = '\0';
                int index = -1;
                for (int j = 0; j < MAX_WORDS; ++j) {
                    if (strcmp(words[j].word, current_word) == 0) {
                        index = j;
                        break;
                    }
                }
                if (index >= 0) {
                    score += words[index].sentiment;
                }
                is_word_ended = true;
            }
            continue;
        }

        current_word[i] = text[i];
    }

    if (!is_word_ended) {
        int index = -1;
        for (int i = 0; i < MAX_WORDS; ++i) {
            if (strcmp(words[i].word, current_word) == 0) {
                index = i;
                break;
            }
        }
        if (index >= 0) {
            score += words[index].sentiment;
        }
    }

    return score;
}

int main() {
    char text[100];

    printf("Enter text: ");
    scanf("%s", text);

    int sentiment_score = analyze(text);

    printf("Sentiment score: %d\n", sentiment_score);

    if (sentiment_score > 0) {
        printf("Sentiment is positive.\n");
    } else if (sentiment_score < 0) {
        printf("Sentiment is negative.\n");
    } else {
        printf("Sentiment is neutral.\n");
    }

    return 0;
}