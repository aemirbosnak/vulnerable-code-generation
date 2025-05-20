//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3

// Function to split input string into words
void split_string(char *input, char **words) {
    int num_words = 0;
    char *word = strtok(input, " \t\r\n\f\v\a\b\c\d\e\f\x7f");
    while (word!= NULL && num_words < MAX_WORDS) {
        if (strlen(word) >= MIN_WORD_LENGTH) {
            words[num_words] = strdup(word);
            num_words++;
        }
        word = strtok(NULL, " \t\r\n\f\v\a\b\c\d\e\f\x7f");
    }
}

// Function to calculate the frequency of each word
void calculate_frequency(char **words, int num_words, int *freq) {
    for (int i = 0; i < num_words; i++) {
        int word_length = strlen(words[i]);
        if (word_length >= MIN_WORD_LENGTH) {
            int j;
            for (j = 0; j < word_length; j++) {
                if (isalpha(words[i][j])) {
                    freq[(int)words[i][j] - (int)'a']++;
                }
            }
        }
    }
}

// Function to check if input string is spam
int is_spam(int *freq) {
    int total_spam_words = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] >= 2) {
            total_spam_words++;
        }
    }
    if (total_spam_words >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[1000];
    char *words[MAX_WORDS];
    int freq[26] = {0};

    printf("Enter input string: ");
    fgets(input, 1000, stdin);

    split_string(input, words);
    calculate_frequency(words, strlen(input), freq);

    if (is_spam(freq)) {
        printf("Input string is spam\n");
    } else {
        printf("Input string is not spam\n");
    }

    return 0;
}