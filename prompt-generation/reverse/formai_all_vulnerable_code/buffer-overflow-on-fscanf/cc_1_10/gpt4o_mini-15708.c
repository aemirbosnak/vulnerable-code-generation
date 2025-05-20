//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 5000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int word_exists(WordCount words[], int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;  // Not found
}

void add_word(WordCount words[], int *size, const char *word) {
    int index = word_exists(words, *size, word);
    if (index != -1) {
        words[index].count++;
    } else {
        strcpy(words[*size].word, word);
        words[*size].count = 1;
        (*size)++;
    }
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    WordCount words[MAX_WORDS];
    int size = 0;
    char buffer[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", buffer) == 1) {
        // Remove punctuation
        for (int i = 0, j = 0; buffer[i]; i++) {
            if (isalpha(buffer[i]) || buffer[i] == '\'') {
                buffer[j++] = buffer[i];
            }
        }
        buffer[strlen(buffer)] = '\0'; // Null-terminate the cleaned string
        
        // Convert to lowercase
        to_lowercase(buffer);
        
        if (strlen(buffer) > 0) {
            add_word(words, &size, buffer);
        }
    }
    fclose(file);

    // Sort words by their count in descending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (words[i].count < words[j].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print the word frequencies
    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < size; i++) {
        printf("%-20s : %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    
    return EXIT_SUCCESS;
}