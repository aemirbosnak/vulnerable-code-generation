//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHRASE_LENGTH 256
#define MAX_KEYWORDS 100

typedef struct {
    char *word;
    int sentiment; // 1 for positive, -1 for negative
} Keyword;

typedef struct {
    Keyword *keywords;
    int count;
} KeywordList;

KeywordList load_keywords(const char *filename) {
    KeywordList list;
    list.keywords = malloc(MAX_KEYWORDS * sizeof(Keyword));
    list.count = 0;

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open keyword file.\n");
        exit(1);
    }

    char word[MAX_PHRASE_LENGTH];
    int sentiment;

    while (fscanf(file, "%s %d", word, &sentiment) != EOF) {
        list.keywords[list.count].word = strdup(word);
        list.keywords[list.count].sentiment = sentiment;
        list.count++;
        if (list.count >= MAX_KEYWORDS) {
            break; // Avoid overflow
        }
    }
    fclose(file);
    return list;
}

int analyze_sentiment(const char *phrase, KeywordList list) {
    int score = 0;

    char *token = strtok(strdup(phrase), " ");
    while (token != NULL) {
        for (int i = 0; i < list.count; i++) {
            if (strcmp(token, list.keywords[i].word) == 0) {
                score += list.keywords[i].sentiment;
                break; // Keyword found, no need to check others
            }
        }
        token = strtok(NULL, " ");
    }
    return score;
}

void free_keywords(KeywordList list) {
    for (int i = 0; i < list.count; i++) {
        free(list.keywords[i].word);
    }
    free(list.keywords);
}

int main() {
    KeywordList keywords = load_keywords("keywords.txt");

    char phrase[MAX_PHRASE_LENGTH];
    printf("Enter a phrase (type 'exit' to quit):\n");

    while (1) {
        printf(">> ");
        fgets(phrase, MAX_PHRASE_LENGTH, stdin);
        phrase[strcspn(phrase, "\n")] = '\0'; // Remove newline character

        if (strcmp(phrase, "exit") == 0) {
            break;
        }

        int sentiment_score = analyze_sentiment(phrase, keywords);
        
        if (sentiment_score > 0) {
            printf("Sentiment: Positive (Score: %d)\n", sentiment_score);
        } else if (sentiment_score < 0) {
            printf("Sentiment: Negative (Score: %d)\n", sentiment_score);
        } else {
            printf("Sentiment: Neutral (Score: %d)\n", sentiment_score);
        }
    }

    free_keywords(keywords);
    return 0;
}