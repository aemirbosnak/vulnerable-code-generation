//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAX_WORD_LENGTH 256

int main(void) {
    char *text = "The quick brown fox jumps over the lazy dog";
    char *word_list[10];
    int word_count = 0;
    int i, j;

    // Tokenize the text into individual words
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            word_count++;
            word_list[word_count - 1] = text + i;
        }
    }

    // Generate a random word from the list
    int random_word_index = rand() % word_count;
    char *random_word = word_list[random_word_index];

    // Calculate the average length of the words in the list
    int sum = 0;
    for (i = 0; i < word_count; i++) {
        sum += strlen(word_list[i]);
    }
    int average_length = sum / word_count;

    // Print the random word and its length
    printf("Random word: %s\n", random_word);
    printf("Length of random word: %d\n", strlen(random_word));

    // Calculate the similarity between the random word and each word in the list
    for (i = 0; i < word_count; i++) {
        int similarity = 0;
        for (j = 0; j < strlen(word_list[i]); j++) {
            if (random_word[j] == word_list[i][j]) {
                similarity++;
            }
        }
        printf("Similarity between %s and %s: %d%%\n", random_word, word_list[i], similarity * 100 / strlen(word_list[i]));
    }

    return 0;
}