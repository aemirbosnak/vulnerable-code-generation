//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a word
struct word {
    char *word;
    int count;
};

// A function to compare two words
int compare_words(const void *a, const void *b) {
    const struct word *word1 = (const struct word *)a;
    const struct word *word2 = (const struct word *)b;

    return strcmp(word1->word, word2->word);
}

// A function to count the words in a string
int count_words(const char *string) {
    int word_count = 0;
    char *word = strtok((char *)string, " \t\n");

    while (word != NULL) {
        word_count++;
        word = strtok(NULL, " \t\n");
    }

    return word_count;
}

// A function to create a word structure
struct word *create_word(const char *word) {
    struct word *new_word = (struct word *)malloc(sizeof(struct word));

    new_word->word = strdup(word);
    new_word->count = 1;

    return new_word;
}

// A function to add a word to a word array
void add_word(struct word **word_array, int *word_count, const char *word) {
    int i;

    // Check if the word is already in the array
    for (i = 0; i < *word_count; i++) {
        if (strcmp(word_array[i]->word, word) == 0) {
            word_array[i]->count++;
            return;
        }
    }

    // Add the word to the array
    word_array = (struct word **)realloc(word_array, (*word_count + 1) * sizeof(struct word *));
    word_array[*word_count] = create_word(word);
    (*word_count)++;
}

// A function to print the word array
void print_word_array(struct word **word_array, int word_count) {
    int i;

    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_array[i]->word, word_array[i]->count);
    }
}

// A function to free the memory allocated for the word array
void free_word_array(struct word **word_array, int word_count) {
    int i;

    for (i = 0; i < word_count; i++) {
        free(word_array[i]->word);
        free(word_array[i]);
    }

    free(word_array);
}

int main() {
    char string[1000];
    struct word **word_array = NULL;
    int word_count = 0;

    // Get the string from the user
    printf("Enter a string: ");
    gets(string);

    // Count the words in the string
    word_count = count_words(string);

    // Create the word array
    word_array = (struct word **)malloc(word_count * sizeof(struct word *));

    // Add the words to the word array
    char *word = strtok((char *)string, " \t\n");

    while (word != NULL) {
        add_word(word_array, &word_count, word);
        word = strtok(NULL, " \t\n");
    }

    // Sort the word array
    qsort(word_array, word_count, sizeof(struct word *), compare_words);

    // Print the word array
    print_word_array(word_array, word_count);

    // Free the memory allocated for the word array
    free_word_array(word_array, word_count);

    return 0;
}