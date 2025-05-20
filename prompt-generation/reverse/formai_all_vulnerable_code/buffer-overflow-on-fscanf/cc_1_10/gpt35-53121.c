//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
// This C program checks the spelling of words using Shannon entropy.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD_LENGTH 100
#define ALPHABET_SIZE 26

double calc_entropy(int n, int freq[]) { 
    double entropy = 0.0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i] > 0) {
            double p = (double)freq[i] / n;
            entropy -= p * log2(p); // calculate entropy using Shannon formula
        }
    }
    return entropy;
}

int main() {
    char word[MAX_WORD_LENGTH];
    int freq[ALPHABET_SIZE];
    int total_words = 0, misspelled_words = 0;
    double avg_entropy = 0.0;

    FILE* dictionary = fopen("dictionary.txt", "r");
    if (!dictionary) {
        printf("Error: could not open dictionary file.\n");
        return EXIT_FAILURE;
    }

    // read dictionary file and populate array of known words
    char** known_words = malloc(sizeof(char*) * 10000);
    int known_words_count = 0;
    while (fscanf(dictionary, "%s", word) == 1) {
        known_words[known_words_count] = strdup(word);
        known_words_count++;
    }
    fclose(dictionary);

    printf("Enter some text to spell-check:\n");

    // read input text and check spelling of each word
    while (scanf("%s", word) == 1) {
        total_words++;
        memset(freq, 0, sizeof(freq)); // zero out letter frequency array
        int word_length = strlen(word);
        for (int i = 0; i < word_length; i++) {
            int c = word[i] - 'a'; // convert character to index into frequency array
            freq[c]++;
        }
        double entropy = calc_entropy(word_length, freq); // calculate entropy of word
        avg_entropy += entropy;

        int found_word = 0;
        for (int i = 0; i < known_words_count; i++) {
            if (strcmp(word, known_words[i]) == 0) {
                found_word = 1;
                break;
            }
        }
        if (!found_word) {
            misspelled_words++;
            printf("%s is misspelled (entropy=%.2f)\n", word, entropy);
        }
    }
    if (total_words > 0) {
        avg_entropy /= total_words;
        printf("Average entropy of input text: %.2f\n", avg_entropy);
    }
    printf("%d misspelled words found.\n", misspelled_words);
    
    // release memory used by known_words array
    for (int i = 0; i < known_words_count; i++) {
        free(known_words[i]);
    }
    free(known_words);

    return EXIT_SUCCESS;
}