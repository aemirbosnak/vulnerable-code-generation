//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

void print_usage() {
    printf("Usage: ./wordcount <filename>\n");
    printf("Counts the number of words in the specified text file.\n");
}

int is_word_char(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
           (c >= '0' && c <= '9') || c == '\'' || c == '-';
}

int count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return -1;
    }

    char c, prev_char = ' ';
    int word_count = 0;
    int in_word = 0;

    while ((c = fgetc(file)) != EOF) {
        if (is_word_char(c)) {
            if (!in_word) {
                in_word = 1;
                word_count++;
            }
        } else {
            in_word = 0;
        }
        prev_char = c;
    }

    fclose(file);
    return word_count;
}

void list_frequent_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS] = {0};
    int word_index = 0;
  
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        int found = 0;
        for (int i = 0; i < word_index; i++) {
            if (strcmp(words[i], buffer) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found && word_index < MAX_WORDS) {
            strcpy(words[word_index], buffer);
            count[word_index] = 1;
            word_index++;
        }
    }

    fclose(file);

    printf("Word Frequency:\n");
    for (int i = 0; i < word_index; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }
  
    char *filename = argv[1];
    
    int total_words = count_words(filename);
    if (total_words != -1) {
        printf("Total words in %s: %d\n", filename, total_words);
        list_frequent_words(filename);
    }

    return EXIT_SUCCESS;
}