//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100     // Maximum length of word in input file
#define MAX_WORDS 10000 // Maximum number of distinct words 

// Node structure for storing word and frequency
struct word_freq {
    char word[MAX_LEN];
    int freq;
};

// Function to read input from file and store unique words in an array of word_freq structs
int read_input(const char *filename, struct word_freq *word_freqs) {
    FILE *fptr;
    char buffer[MAX_LEN];
    int i, j, k, found, len, num_words;

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Unable to open input file\n");
        exit(EXIT_FAILURE);
    }

    // Read input file
    num_words = 0;
    while (fscanf(fptr, "%s", buffer) == 1 && num_words < MAX_WORDS) {
        // Strip non-alphabetic characters from word
        len = strlen(buffer);
        i = 0;
        j = 0;
        while (i < len) {
            if (isalpha(buffer[i])) {
                buffer[j] = tolower(buffer[i]);
                j++;
            }
            i++;
        }
        buffer[j] = '\0';

        // Check if word already exists in array
        found = 0;
        for (k = 0; k < num_words; k++) {
            if (strcmp(buffer, word_freqs[k].word) == 0) {
                word_freqs[k].freq++;
                found = 1;
                break;
            }
        }

        // If word is not found in array, add it as a new word
        if (!found) {
            strcpy(word_freqs[num_words].word, buffer);
            word_freqs[num_words].freq = 1;
            num_words++;
        }
    }

    // Close input file
    fclose(fptr);

    return num_words;
}

// Function to sort array of word_freq structs in descending order of frequency
void sort_word_freqs(struct word_freq *word_freqs, int num_words) {
    int i, j;
    struct word_freq temp;

    for (i = 0; i < num_words - 1; i++) {
        for (j = 0; j < num_words - i - 1; j++) {
            if (word_freqs[j].freq < word_freqs[j+1].freq) {
                temp = word_freqs[j];
                word_freqs[j] = word_freqs[j+1];
                word_freqs[j+1] = temp;
            }
        }
    }
}

// Function to print array of word_freq structs
void print_word_freqs(struct word_freq *word_freqs, int num_words) {
    int i;

    printf("%-15s%s\n", "Words", "Frequency");
    for (i = 0; i < num_words; i++) {
        printf("%-15s%d\n", word_freqs[i].word, word_freqs[i].freq);
    }
}

int main() {
    char filename[100];
    struct word_freq word_freqs[MAX_WORDS];
    int num_words;

    // Get input filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Read input from file and store unique words in array of word_freq structs
    num_words = read_input(filename, word_freqs);

    // Sort array of word_freq structs in descending order of frequency
    sort_word_freqs(word_freqs, num_words);

    // Print array of word_freq structs
    print_word_freqs(word_freqs, num_words);

    return 0;
}