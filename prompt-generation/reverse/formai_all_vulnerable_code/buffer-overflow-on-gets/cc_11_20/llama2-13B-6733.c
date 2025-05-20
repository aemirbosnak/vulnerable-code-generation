//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 1

int main() {
    int len;
    char *str = NULL;
    char *word = NULL;
    char *letter = NULL;
    int i, j, k;
    int freq[26];
    int max_freq = 0;
    int max_word = 0;

    srand(time(NULL));

    printf("Welcome to the Land of Logs! Here we will analyze the frequency of words in a given text...\n");

    // Ask the user for the text to be analyzed
    printf("Please enter the text to be analyzed (hit enter for a random text): ");
    gets(str);

    // Trim the text to remove any extra spaces
    len = strlen(str);
    word = (char *)calloc(len + 1, sizeof(char));
    strcpy(word, str);
    word[len] = '\0';

    // Tokenize the text into individual words
    i = 0;
    while (word[i] != '\0') {
        if (word[i] == ' ' || word[i] == '\n' || word[i] == '\t') {
            word[i] = '\0';
            i++;
            if (i != 0) {
                word[i - 1] = '\0';
            }
        }
    }

    // Count the frequency of each word
    freq[0] = 0;
    for (i = 1; i < len; i++) {
        if (word[i] != '\0') {
            for (j = 0; j < 26; j++) {
                if (word[i] == 'a' + j) {
                    freq[j]++;
                }
            }
        }
    }

    // Find the most frequent word and the longest word
    max_freq = 0;
    max_word = 0;
    for (j = 0; j < 26; j++) {
        if (freq[j] > max_freq) {
            max_freq = freq[j];
            max_word = word[j];
        }
    }

    // Print the analysis
    printf("The most frequent word in the text is: %c (%d times)\n", max_word, max_freq);
    for (j = 0; j < 26; j++) {
        if (freq[j] > 0) {
            printf("%c: %d\n", word[j], freq[j]);
        }
    }

    // Free the memory allocated for the word array
    free(word);

    return 0;
}