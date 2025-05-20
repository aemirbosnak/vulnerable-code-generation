//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Function to tokenize a string
void tokenize(char *str, char **tokens) {
    int i = 0;
    char *token;
    token = strtok(str, " ");
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
}

// Function to compute the frequency of each word
void compute_word_frequency(char **tokens, int num_tokens, int *word_freq) {
    int i;
    for (i = 0; i < num_tokens; i++) {
        int word_len = strlen(tokens[i]);
        if (word_len > 0) {
            word_freq[i] = 1;
        }
    }
}

// Function to compute the probability of a word being spam
double compute_spam_probability(int *word_freq, int num_tokens) {
    double sum = 0.0;
    int i;
    for (i = 0; i < num_tokens; i++) {
        sum += word_freq[i];
    }
    return sum / num_tokens;
}

// Function to classify an email as spam or not
int classify_email(double spam_probability) {
    if (spam_probability >= 0.5) {
        return 1; // spam
    } else {
        return 0; // not spam
    }
}

int main() {
    char input_str[MAX_WORD_LENGTH];
    char *tokens[MAX_WORDS];
    int num_tokens = 0;
    int word_freq[MAX_WORDS];

    // Read input string
    printf("Enter input string: ");
    scanf("%s", input_str);

    // Tokenize input string
    tokenize(input_str, tokens);
    num_tokens = strlen(tokens[0]);

    // Compute word frequency
    compute_word_frequency(tokens, num_tokens, word_freq);

    // Compute spam probability
    double spam_probability = compute_spam_probability(word_freq, num_tokens);

    // Classify email as spam or not
    int is_spam = classify_email(spam_probability);

    // Print result
    if (is_spam == 1) {
        printf("Input string is likely spam.\n");
    } else {
        printf("Input string is likely not spam.\n");
    }

    return 0;
}