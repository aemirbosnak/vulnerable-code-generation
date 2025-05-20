//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50
#define THRESHOLD 0.8

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[1000];
    struct word_count *word_counts = (struct word_count *)malloc(MAX_WORDS * sizeof(struct word_count));
    int total_words = 0;
    int num_spam = 0;
    int num_ham = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        total_words += count_words(line, word_counts);
    }

    fclose(input_file);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            double spam_probability = (double)word_counts[i].count / total_words;
            if (spam_probability >= THRESHOLD) {
                printf("Spam word: %s\n", word_counts[i].word);
                num_spam++;
            } else {
                printf("Ham word: %s\n", word_counts[i].word);
                num_ham++;
            }
        }
    }

    printf("Total words: %d\n", total_words);
    printf("Number of spam words: %d\n", num_spam);
    printf("Number of ham words: %d\n", num_ham);

    return 0;
}

int count_words(char *line, struct word_count *word_counts) {
    int words = 0;
    char *token = strtok(line, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORD_LENGTH; i++) {
            if (isalpha(token[i])) {
                strncpy(word_counts[words].word, token, MAX_WORD_LENGTH);
                word_counts[words].word[MAX_WORD_LENGTH - 1] = '\0';
                word_counts[words].count++;
                break;
            }
        }
        words++;
        token = strtok(NULL, " ");
    }
    return words;
}