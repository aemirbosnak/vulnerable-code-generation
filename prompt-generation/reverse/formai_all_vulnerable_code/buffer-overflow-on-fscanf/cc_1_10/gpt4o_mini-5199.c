//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Shockingly, let's add a function to convert a word to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to find the word in the array
int find_word(WordFrequency *words, int num_words, const char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1; // Word not found
}

// A shocking revelation: a function to update word frequency
void update_word_count(WordFrequency *words, int *num_words, const char *word) {
    int index = find_word(words, *num_words, word);
    if (index != -1) {
        words[index].count++;
    } else {
        if (*num_words < MAX_WORDS) {
            strcpy(words[*num_words].word, word);
            words[*num_words].count = 1;
            (*num_words)++;
        } else {
            printf("Whoa! Maximum number of words reached. Can't add more!\n");
        }
    }
}

// The absolute necessity: a function to process the file
void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Oops! Could not open file: %s\n", filename);
        return;
    }

    WordFrequency words[MAX_WORDS];
    int num_words = 0;
    char buffer[MAX_WORD_LENGTH];
    
    // Read the file word by word
    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer); // Shocking conversion to lowercase
        update_word_count(words, &num_words, buffer);
    }

    fclose(file);
    // Display shocking results
    printf("\n** Word Frequency Results **\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

// And now, the moment we've all been waiting for: main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Ahhh! Shocking Word Frequency Counter is set to analyze the file: %s\n", argv[1]);
    
    process_file(argv[1]);

    printf("Count completed. What a shocking number of words encountered!\n");
    return 0;
}