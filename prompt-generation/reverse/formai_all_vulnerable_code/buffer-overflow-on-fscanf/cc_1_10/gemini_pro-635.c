//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store word and its count
typedef struct word_count {
    char *word;
    int count;
} word_count;

// Function to compare two word_count structures
int compare_word_count(const void *a, const void *b) {
    const word_count *wa = (const word_count *)a;
    const word_count *wb = (const word_count *)b;
    return strcmp(wa->word, wb->word);
}

// Function to count words in a file
int count_words(const char *filename, word_count **words) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return -1;
    }

    // Allocate memory for the words array
    *words = malloc(sizeof(word_count) * 1000);
    if (*words == NULL) {
        perror("malloc");
        fclose(file);
        return -1;
    }

    // Read the file and count the words
    int num_words = 0;
    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp((*words)[i].word, word) == 0) {
                (*words)[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it
        if (!found) {
            (*words)[num_words].word = strdup(word);
            (*words)[num_words].count = 1;
            num_words++;
        }
    }

    // Close the file
    fclose(file);

    // Sort the words by count
    qsort(*words, num_words, sizeof(word_count), compare_word_count);

    return num_words;
}

// Function to print the word count
void print_word_count(const word_count *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    // Get the filename from the user
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Count the words in the file
    word_count *words;
    int num_words = count_words(filename, &words);
    if (num_words == -1) {
        return EXIT_FAILURE;
    }

    // Print the word count
    print_word_count(words, num_words);

    // Free the memory allocated for the words array
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);

    return EXIT_SUCCESS;
}