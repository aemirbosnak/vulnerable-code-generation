//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define VOCAB_SIZE 5000
#define MIN_SENTENCE_LENGTH 10
#define SENTIMENT_THRESHOLD 0.05

typedef struct {
    char word[MAX_WORDS];
    float score;
} Word;

Word vocab[VOCAB_SIZE];
int num_words = 0;

float calculate_sentiment(char *text) {
    int num_words_in_text = 0;
    float total_score = 0.0;

    char *token = strtok(text, " .,!?:;");
    while (token != NULL) {
        int index = 0;
        for (; index < num_words; index++) {
            if (strcasecmp(token, vocab[index].word) == 0) {
                total_score += vocab[index].score;
                num_words_in_text++;
                break;
            }
        }
        if (index == num_words) {
            for (int i = 0; i < VOCAB_SIZE; i++) {
                if (strcasecmp(token, vocab[i].word) == 0) {
                    total_score += vocab[i].score;
                    num_words_in_text++;
                    break;
                }
                if (num_words < VOCAB_SIZE) {
                    strcpy(vocab[num_words].word, token);
                    vocab[num_words].score = 0.0;
                    num_words++;
                }
            }
        }
        token = strtok(NULL, " .,!?:;");
    }

    if (num_words_in_text < MIN_SENTENCE_LENGTH) {
        return 0.0;
    }

    float avg_score = total_score / num_words_in_text;
    return avg_score;
}

void preprocess_text(char *text) {
    char *token = strtok(text, " .,!?:;");
    while (token != NULL) {
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        token = strtok(NULL, " .,!?:;");
    }
}

int main() {
    char text[1000];
    float sentiment_score;

    FILE *file = fopen("vocab.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open vocabulary file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s %f", vocab[num_words].word, &vocab[num_words].score);
        num_words++;
    }

    fclose(file);

    printf("Enter text for sentiment analysis: ");
    scanf("%s", text);

    preprocess_text(text);
    sentiment_score = calculate_sentiment(text);

    if (sentiment_score > SENTIMENT_THRESHOLD) {
        printf("Positive sentiment.\n");
    } else if (sentiment_score < -SENTIMENT_THRESHOLD) {
        printf("Negative sentiment.\n");
    } else {
        printf("Neutral sentiment.\n");
    }

    return 0;
}