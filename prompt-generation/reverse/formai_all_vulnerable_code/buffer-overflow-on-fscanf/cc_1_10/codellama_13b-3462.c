//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
/*
* Word Frequency Counter Example Program in a Romantic Style
*
* This program reads a text file and counts the frequency of each word.
* The output is sorted in descending order of frequency.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store word and its frequency
struct word_freq {
    char word[100];
    int freq;
};

// Function to sort the words in descending order of frequency
int compare_word_freq(const void *a, const void *b) {
    struct word_freq *wf1 = (struct word_freq *)a;
    struct word_freq *wf2 = (struct word_freq *)b;
    return wf2->freq - wf1->freq;
}

int main() {
    // Open the text file
    FILE *fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Create an array to store the words and their frequencies
    struct word_freq words[100];

    // Read the text file and populate the array
    int i = 0;
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(words[i].word, word);
        words[i].freq = 1;
        i++;
    }

    // Sort the words in descending order of frequency
    qsort(words, i, sizeof(struct word_freq), compare_word_freq);

    // Print the sorted words and their frequencies
    for (int j = 0; j < i; j++) {
        printf("%s: %d\n", words[j].word, words[j].freq);
    }

    // Close the file
    fclose(fp);

    return 0;
}