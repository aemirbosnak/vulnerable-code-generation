//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Function prototypes
void process_file(const char *filename);
void count_words(const char *filename);
void find_most_frequent_word(const char *filename);
void trim_newline(char *str);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    return EXIT_SUCCESS;
}

void process_file(const char *filename) {
    printf("Processing file: %s\n", filename);
    count_words(filename);
    find_most_frequent_word(filename);
}

void count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    int word_count = 0, char_count = 0, line_count = 0;
    char word[MAX_WORD_LENGTH];

    while (fgets(word, sizeof(word), file)) {
        line_count++;
        char_count += strlen(word); // Count characters in the line
        char *ptr = strtok(word, " \n");
        while (ptr) {
            word_count++;
            ptr = strtok(NULL, " \n");
        }
    }

    fclose(file);
    printf("Lines: %d, Words: %d, Characters: %d\n", line_count, word_count, char_count);
}

void find_most_frequent_word(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char word[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count[MAX_WORDS] = {0};
    int word_index = 0;
    int max_count = 0;
    char most_frequent_word[MAX_WORD_LENGTH] = "";

    while (fscanf(file, "%s", word) != EOF) {
        trim_newline(word);
        int found = 0;

        for (int i = 0; i < word_index; i++) {
            if (strcmp(words[i], word) == 0) {
                word_count[i]++;
                found = 1;
                if (word_count[i] > max_count) {
                    max_count = word_count[i];
                    strcpy(most_frequent_word, word);
                }
                break;
            }
        }

        if (!found) {
            strcpy(words[word_index], word);
            word_count[word_index]++;
            if (word_count[word_index] > max_count) {
                max_count = word_count[word_index];
                strcpy(most_frequent_word, word);
            }
            word_index++;
        }
    }

    fclose(file);
    
    if (max_count > 0) {
        printf("Most frequent word: '%s' (occurrences: %d)\n", most_frequent_word, max_count);
    } else {
        printf("No words found in the file.\n");
    }
}

// Function to trim newline from a string
void trim_newline(char *str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}