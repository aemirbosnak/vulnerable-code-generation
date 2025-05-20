//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 1000000
#define MAX_WORD_LENGTH 200

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_log_file(FILE *log_file, WordFrequency *word_frequencies) {
    char line[MAX_LOG_SIZE];
    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    while (fgets(line, MAX_LOG_SIZE, log_file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (isalpha(token[0])) {
                strcpy(word, toupper(token));
                word_frequencies[hash(word) % MAX_WORD_LENGTH].count++;
            }
            token = strtok(NULL, " ");
        }
    }
}

int hash(char *word) {
    int hash_value = 0;
    int i = 0;

    while (word[i]!= '\0') {
        hash_value += word[i];
        i++;
    }

    return hash_value % MAX_WORD_LENGTH;
}

void print_word_frequencies(WordFrequency *word_frequencies) {
    int i = 0;

    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word_frequencies[i].count > 0) {
            printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
        }
    }
}

int main() {
    FILE *log_file;
    WordFrequency word_frequencies[MAX_WORD_LENGTH];

    log_file = fopen("logfile.txt", "r");

    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    read_log_file(log_file, word_frequencies);
    fclose(log_file);

    print_word_frequencies(word_frequencies);

    return 0;
}