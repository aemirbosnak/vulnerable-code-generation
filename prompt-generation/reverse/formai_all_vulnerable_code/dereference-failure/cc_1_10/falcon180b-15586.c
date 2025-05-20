//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_WORD_SIZE 50

// Function to tokenize the input string
void tokenize(char* input, char* tokens[], int* num_tokens) {
    int i = 0;
    char* token = strtok(input, " ");
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    *num_tokens = i;
}

// Function to count the frequency of each word
void count_words(char* tokens[], int num_tokens, int* word_counts) {
    for (int i = 0; i < num_tokens; i++) {
        char* word = tokens[i];
        if (strlen(word) > MAX_WORD_SIZE) {
            // Ignore words longer than MAX_WORD_SIZE
            continue;
        }
        word = tolower(word);
        int word_index = word[0] - 'a';
        if (isalpha(word[0])) {
            word_counts[word_index]++;
        }
    }
}

// Function to print the word count results
void print_word_counts(int word_counts[], int num_words) {
    printf("Word Count:\n");
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i] > 0) {
            printf("%c: %d\n", 'a' + i, word_counts[i]);
        }
    }
}

int main() {
    char input[1000];
    printf("Enter a string to count the words:\n");
    fgets(input, sizeof(input), stdin);
    char* tokens[1000];
    int num_tokens;
    tokenize(input, tokens, &num_tokens);
    int word_counts[26] = {0};
    count_words(tokens, num_tokens, word_counts);
    print_word_counts(word_counts, 26);
    return 0;
}