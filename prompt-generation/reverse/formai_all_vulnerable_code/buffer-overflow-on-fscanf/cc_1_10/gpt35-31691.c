//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for sentiment analysis
typedef struct {
    char word[20];
    int score;
} Sentiment;

// Function to extract sentiment data from file
void read_sentiments(Sentiment *sentiments, int *num_sentiments) {
    FILE *file = fopen("sentiments.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        exit(1);
    }

    char word[20];
    int score;
    int count = 0;
    while (fscanf(file, "%s %d", word, &score) == 2) {
        strcpy(sentiments[count].word, word);
        sentiments[count].score = score;
        count++;
    }

    fclose(file);
    *num_sentiments = count;
}

// Function to calculate sentiment score for a sentence
int sentiment_score(char *sentence, Sentiment *sentiments, int num_sentiments) {
    int score = 0;
    char *token = strtok(sentence, " .,");
    while (token != NULL) {
        for (int i = 0; i < num_sentiments; i++) {
            if (strcmp(token, sentiments[i].word) == 0) {
                score += sentiments[i].score;
                break;
            }
        }
        token = strtok(NULL, " .,");
    }
    return score;
}

int main() {
    Sentiment sentiments[100];
    int num_sentiments;

    read_sentiments(sentiments, &num_sentiments);

    char sentence[200];
    printf("Enter a sentence: ");
    fgets(sentence, 200, stdin);

    int score = sentiment_score(sentence, sentiments, num_sentiments);

    if (score > 0) {
        printf("Positive sentiment\n");
    } else if (score < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}