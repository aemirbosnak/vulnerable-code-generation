//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define DICTIONARY_SIZE 50

typedef struct {
    char word[WORD_LENGTH];
    int is_positive;
} Word;

Word dictionary[DICTIONARY_SIZE] = {
    {"happy", 1},
    {"joy", 1},
    {"love", 1},
    {"excited", 1},
    {"amazing", 1},
    {"good", 1},
    {"beautiful", 1},
    {"great", 1},
    {"positive", 1},
    {"excelle", 1},

    {"sad", 0},
    {"depressed", 0},
    {"negative", 0},
    {"hate", 0},
    {"terrible", 0},
    {"disappointed", 0},
    {"angry", 0},
    {"frustrated", 0},
    {"miserable", 0},
    {"bad", 0},
};

int count_words(char *text, char words[][WORD_LENGTH], int *num_words) {
    int current_word = 0, i, j;
    int word_length = 0;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            words[current_word][word_length++] = tolower(text[i]);
        } else if (word_length > 0) {
            words[current_word][word_length] = '\0';
            current_word++;
            if (current_word >= MAX_WORDS) {
                return -1;
            }
            word_length = 0;
        }
    }

    if (word_length > 0) {
        words[current_word][word_length] = '\0';
        current_word++;
    }

    *num_words = current_word;
    return 0;
}

int main() {
    FILE *file;
    char filename[100], text[1024];
    Word words[MAX_WORDS];
    int num_words, i, sentiment_score = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fgets(text, sizeof(text), file);
    fclose(file);

    if (count_words(text, words, &num_words) < 0) {
        printf("Error processing text.\n");
        return 1;
    }

    for (i = 0; i < num_words; i++) {
        int index;
        for (index = 0; index < DICTIONARY_SIZE; index++) {
            if (strcmp(words[i].word, dictionary[index].word) == 0) {
                sentiment_score += dictionary[index].is_positive ? 1 : -1;
                break;
            }
        }
    }

    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}