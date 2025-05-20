//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3

// Function to tokenize the input string
void tokenize(char *input, char **tokens) {
    char *token = strtok(input, " ");
    int i = 0;

    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
}

// Function to calculate the frequency of each word in the input string
void calculate_frequencies(char **tokens, int num_tokens, int *frequencies) {
    for (int i = 0; i < num_tokens; i++) {
        int word_length = strlen(tokens[i]);

        if (word_length >= MIN_WORD_LENGTH) {
            char *lowercase_token = malloc(word_length + 1);
            strcpy(lowercase_token, tokens[i]);

            for (int j = 0; j < word_length; j++) {
                lowercase_token[j] = tolower(lowercase_token[j]);
            }

            int index = hash(lowercase_token);
            frequencies[index]++;
        }
    }
}

// Hash function to map words to indices in the frequency table
int hash(char *word) {
    int hash_value = 0;

    for (int i = 0; i < strlen(word); i++) {
        hash_value += tolower(word[i]);
    }

    return hash_value % MAX_WORDS;
}

// Function to check if the input string is spam
int is_spam(int *frequencies) {
    int spam_count = 0;

    for (int i = 0; i < MAX_WORDS; i++) {
        if (frequencies[i] > 1) {
            spam_count++;
        }
    }

    return spam_count >= 3;
}

int main() {
    char input[1000];
    char *tokens[MAX_WORDS];
    int frequencies[MAX_WORDS] = {0};

    printf("Enter the input string to check for spam: ");
    scanf("%[^\n]", input);

    tokenize(input, tokens);
    calculate_frequencies(tokens, strlen(input), frequencies);

    if (is_spam(frequencies)) {
        printf("The input string is spam.\n");
    } else {
        printf("The input string is not spam.\n");
    }

    return 0;
}