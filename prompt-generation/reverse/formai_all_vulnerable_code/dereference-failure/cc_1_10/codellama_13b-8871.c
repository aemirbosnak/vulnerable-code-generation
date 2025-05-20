//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
/*
 * Unique Word Frequency Counter
 *
 * This program reads a text file and counts the frequency of each unique word in the file.
 * It ignores words that are in the ignore list and prints the top 10 most frequently occurring words.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store a word and its frequency
typedef struct {
    char *word;
    int freq;
} word_freq;

// Function to compare two words based on their frequency
int cmp_word_freq(const void *a, const void *b) {
    const word_freq *wf1 = a;
    const word_freq *wf2 = b;
    return wf2->freq - wf1->freq;
}

int main(int argc, char **argv) {
    // Check if the input file name is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    // Initialize the ignore list
    char *ignore_list[] = {"the", "a", "an", "and", "or", "but", "not", "with", "by", "at", "of", "in", "as", "on", "for", "with", "to", "from", "is", "be", "are", "was", "were", "been", "being", "have", "has", "had", "do", "does", "did", "will", "will", "are", "would", "can", "could", "may", "might", "must", "shall", "should", "ought", "i", "you", "he", "she", "it", "we", "they"};
    int ignore_list_size = sizeof(ignore_list) / sizeof(char *);

    // Initialize the word frequency array
    word_freq *word_freq_arr = malloc(sizeof(word_freq) * ignore_list_size);
    for (int i = 0; i < ignore_list_size; i++) {
        word_freq_arr[i].word = ignore_list[i];
        word_freq_arr[i].freq = 0;
    }

    // Read the input file and update the frequency of each word
    char word[100];
    while (fscanf(fp, "%99s", word) != EOF) {
        for (int i = 0; i < ignore_list_size; i++) {
            if (strcmp(word, ignore_list[i]) == 0) {
                word_freq_arr[i].freq++;
                break;
            }
        }
    }

    // Sort the word frequency array based on the frequency
    qsort(word_freq_arr, ignore_list_size, sizeof(word_freq), cmp_word_freq);

    // Print the top 10 most frequently occurring words
    printf("Top 10 most frequently occurring words:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", word_freq_arr[i].word, word_freq_arr[i].freq);
    }

    // Close the input file
    fclose(fp);

    return 0;
}