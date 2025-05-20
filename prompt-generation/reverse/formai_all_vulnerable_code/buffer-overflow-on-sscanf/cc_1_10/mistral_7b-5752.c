//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_WORDS 10000
#define WORD_SIZE 50
#define LINE_SIZE 1024

typedef struct {
    char word[WORD_SIZE];
    int sentiment;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open dictionary file\n");
        exit(1);
    }

    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, fp)) {
        char word[WORD_SIZE];
        int sentiment;
        sscanf(line, "%s %d", word, &sentiment);

        strcpy(dictionary[num_words].word, word);
        dictionary[num_words].sentiment = sentiment;
        num_words++;
    }

    fclose(fp);
}

int analyze_sentiment(const char* text) {
    int num_positive = 0;
    int num_negative = 0;
    int total_words = 0;

    char words[MAX_WORDS][WORD_SIZE];
    char* token = strtok(strdup(text), " .,\n");

    while (token) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcasecmp(token, dictionary[i].word) == 0) {
                total_words++;
                if (dictionary[i].sentiment > 0)
                    num_positive++;
                else
                    num_negative++;
                break;
            }
        }

        if (i == num_words) {
            // Unknown word, assume neutral
            total_words++;
        }

        token = strtok(NULL, " .,\n");
    }

    int sentiment = (num_positive - num_negative) / total_words * 10;
    return sentiment;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        exit(1);
    }

    load_dictionary("dictionary.txt");

    clock_t start = clock();
    int sentiment = analyze_sentiment(argv[1]);
    clock_t end = clock();

    printf("Sentiment: %d%%\n", sentiment);
    printf("Time taken: %f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);

    return 0;
}