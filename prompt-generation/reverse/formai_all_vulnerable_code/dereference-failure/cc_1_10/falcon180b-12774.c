//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_CHAR_LENGTH 256

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *word_counts;
    int num_words;
} WordFrequency;

void initialize_word_counts(WordFrequency *word_frequency) {
    word_frequency->word_counts = (WordCount *) malloc(sizeof(WordCount) * MAX_LINE_LENGTH);
    word_frequency->num_words = 0;
    int i;
    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        word_frequency->word_counts[i].word = NULL;
        word_frequency->word_counts[i].count = 0;
    }
}

void free_word_counts(WordFrequency *word_frequency) {
    int i;
    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        if (word_frequency->word_counts[i].word!= NULL) {
            free(word_frequency->word_counts[i].word);
        }
    }
    free(word_frequency->word_counts);
}

void add_word(WordFrequency *word_frequency, char *word) {
    int i;
    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        if (word_frequency->word_counts[i].word == NULL) {
            word_frequency->word_counts[i].word = strdup(word);
            word_frequency->word_counts[i].count = 1;
            word_frequency->num_words++;
            return;
        } else if (strcmp(word_frequency->word_counts[i].word, word) == 0) {
            word_frequency->word_counts[i].count++;
            return;
        }
    }
}

void print_word_counts(WordFrequency *word_frequency) {
    int i;
    printf("Word\tCount\n");
    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        if (word_frequency->word_counts[i].word!= NULL) {
            printf("%s\t%d\n", word_frequency->word_counts[i].word, word_frequency->word_counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    char *token;
    WordFrequency word_frequency;
    initialize_word_counts(&word_frequency);
    log_file = fopen("log_file.txt", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }
    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            add_word(&word_frequency, word);
            token = strtok(NULL, " ");
        }
    }
    fclose(log_file);
    print_word_counts(&word_frequency);
    free_word_counts(&word_frequency);
    return 0;
}