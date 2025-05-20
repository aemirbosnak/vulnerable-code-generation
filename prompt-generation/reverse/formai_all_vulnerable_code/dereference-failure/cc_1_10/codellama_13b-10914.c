//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

// Define a structure to represent a word
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Define a function to count the number of words in a sentence
int count_words(char *sentence) {
    int count = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}

// Define a function to extract the words from a sentence
void extract_words(char *sentence, Word *words) {
    int count = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            words[count].count = 1;
            count++;
        } else {
            words[count].word[words[count].count] = sentence[i];
            words[count].count++;
        }
    }
}

// Define a function to sort the words by frequency
void sort_words(Word *words, int num_words) {
    int i, j;
    Word temp;
    for (i = 0; i < num_words; i++) {
        for (j = 0; j < num_words - i - 1; j++) {
            if (words[j].count > words[j + 1].count) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

// Define a function to print the top 5 most frequent words
void print_top_words(Word *words, int num_words) {
    for (int i = 0; i < 5; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    Word words[MAX_SENTENCE_LENGTH];
    int num_words;

    // Get the input sentence
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Count the number of words in the sentence
    num_words = count_words(sentence);

    // Extract the words from the sentence
    extract_words(sentence, words);

    // Sort the words by frequency
    sort_words(words, num_words);

    // Print the top 5 most frequent words
    print_top_words(words, num_words);

    return 0;
}