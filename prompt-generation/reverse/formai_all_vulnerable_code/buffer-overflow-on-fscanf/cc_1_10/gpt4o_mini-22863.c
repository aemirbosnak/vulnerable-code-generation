//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_word_char(char c) {
    return isalnum(c) || c == '\''; // Allow letters, numbers, and apostrophes
}

void count_words_lines_chars(FILE *file, int *line_count, int *word_count, int *char_count) {
    char ch;
    *line_count = *word_count = *char_count = 0;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        (*char_count)++;

        if (ch == '\n') {
            (*line_count)++;
        }
        
        if (is_word_char(ch)) {
            if (!in_word) {
                in_word = 1;
                (*word_count)++;
            }
        } else {
            in_word = 0; // We hit a non-word character, so it's not a word
        }
    }
}

void record_word_frequency(FILE *file, int *word_freq, char words[][MAX_WORD_LENGTH], int *unique_word_count) {
    char buffer[MAX_WORD_LENGTH];
    int n;

    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);
        int found = 0;

        for (n = 0; n < *unique_word_count; n++) {
            if (strcmp(words[n], buffer) == 0) {
                word_freq[n]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[*unique_word_count], buffer);
            word_freq[*unique_word_count] = 1;
            (*unique_word_count)++;
        }
    }
}

void display_word_frequencies(char words[][MAX_WORD_LENGTH], int *word_freq, int unique_word_count) {
    printf("\nWord Frequencies:\n");
    printf("---------------------------------\n");
    for (int i = 0; i < unique_word_count; i++) {
        printf("%s: %d\n", words[i], word_freq[i]);
    }
    printf("---------------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int line_count, word_count, char_count;
    count_words_lines_chars(file, &line_count, &word_count, &char_count);

    printf("Lines: %d\n", line_count);
    printf("Words: %d\n", word_count);
    printf("Characters: %d\n", char_count);
    
    // Reset the file pointer to the beginning for reading words
    rewind(file);

    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int word_freq[MAX_NUM_WORDS] = {0};
    int unique_word_count = 0;

    record_word_frequency(file, word_freq, words, &unique_word_count);
    
    fclose(file);
    
    display_word_frequencies(words, word_freq, unique_word_count);

    return 0;
}