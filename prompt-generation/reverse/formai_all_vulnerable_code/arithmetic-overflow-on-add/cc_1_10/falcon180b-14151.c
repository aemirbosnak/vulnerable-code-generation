//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_log_file(FILE *log_file, WordFrequency *word_frequencies, int *num_words) {
    char line[MAX_LOG_SIZE];
    while (fgets(line, MAX_LOG_SIZE, log_file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < *num_words; i++) {
                if (strcmp(token, word_frequencies[i].word) == 0) {
                    word_frequencies[i].frequency++;
                    break;
                }
            }
            if (i == *num_words) {
                WordFrequency new_word;
                strcpy(new_word.word, token);
                new_word.frequency = 1;
                word_frequencies[*num_words] = new_word;
                (*num_words)++;
            }
            token = strtok(NULL, " ");
        }
    }
}

void print_word_frequencies(WordFrequency *word_frequencies, int num_words) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main() {
    FILE *log_file;
    log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    WordFrequency word_frequencies[MAX_WORD_LENGTH];
    int num_words = 0;

    read_log_file(log_file, word_frequencies, &num_words);

    printf("Word Frequencies:\n");
    print_word_frequencies(word_frequencies, num_words);

    fclose(log_file);
    return 0;
}