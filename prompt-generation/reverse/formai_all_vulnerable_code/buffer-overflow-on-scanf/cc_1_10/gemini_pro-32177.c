//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000

typedef struct {
    char* word;
    int count;
} Word;

Word* words[MAX_WORDS];
int num_words = 0;

void add_word(char* word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i]->word, word) == 0) {
            words[i]->count++;
            return;
        }
    }

    words[num_words] = malloc(sizeof(Word));
    words[num_words]->word = strdup(word);
    words[num_words]->count = 1;
    num_words++;
}

void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->count);
    }
}

int main() {
    // Holy guacamole! This program is going to count the frequency of words in a text file.

    // Get the file name from the user.
    printf("Enter the name of the text file: ");
    char filename[100];
    scanf("%s", filename);

    // Open the file.
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read the file line by line.
    char line[1000];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Split the line into words.
        char* word = strtok(line, " ");
        while (word != NULL) {
            // Add the word to the list of words.
            add_word(word);

            // Get the next word.
            word = strtok(NULL, " ");
        }
    }

    // Close the file.
    fclose(file);

    // Print the list of words and their frequencies.
    print_words();

    // Free the memory allocated for the words.
    for (int i = 0; i < num_words; i++) {
        free(words[i]->word);
        free(words[i]);
    }

    return 0;
}