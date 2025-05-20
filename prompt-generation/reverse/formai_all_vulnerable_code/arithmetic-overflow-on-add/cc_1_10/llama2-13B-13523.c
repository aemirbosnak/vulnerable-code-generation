//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20
#define MIN_SENTENCE_LENGTH 5
#define MAX_SENTENCE_LENGTH 200

// Structure to represent a sentence
typedef struct {
    char *words[10];
    int word_count;
} sentence;

// Function to generate a random sentence
sentence *generate_sentence(int min_words, int max_words) {
    sentence *sentence = malloc(sizeof(sentence));
    int i, j;

    // Generate random words
    for (i = 0; i < min_words; i++) {
        sentence->words[i] = (char *)malloc(10);
        for (j = 0; j < 10; j++) {
            sentence->words[i][j] = 'a' + (rand() % 26);
        }
    }

    // Add random words to the sentence
    for (i = 0; i < max_words - min_words; i++) {
        sentence->words[i + min_words] = (char *)malloc(10);
        for (j = 0; j < 10; j++) {
            sentence->words[i + min_words][j] = 'a' + (rand() % 26);
        }
    }

    // Calculate the sentence length
    sentence->word_count = min_words + (max_words - min_words) / 2;

    return sentence;
}

// Function to print the sentence
void print_sentence(sentence *sentence) {
    int i;

    printf("The sentence contains the following words: ");
    for (i = 0; i < sentence->word_count; i++) {
        printf("%s ", sentence->words[i]);
    }
    printf("\n");
}

int main() {
    sentence *sentence;
    int min_words, max_words;

    // Ask the user for the minimum and maximum number of words in the sentence
    printf("Enter the minimum number of words in the sentence (default is 3): ");
    scanf("%d", &min_words);
    printf("Enter the maximum number of words in the sentence (default is 20): ");
    scanf("%d", &max_words);

    // Generate a random sentence
    sentence = generate_sentence(min_words, max_words);

    // Print the sentence
    print_sentence(sentence);

    // Free the memory
    free(sentence->words[0]);
    for (int i = 1; i < sentence->word_count; i++) {
        free(sentence->words[i]);
    }
    free(sentence);

    return 0;
}