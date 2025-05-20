//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to tokenize the input string
void tokenize(char *str, char **tokens) {
    int i = 0;
    char *token = strtok(str, " ");

    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    tokens[i] = NULL;
}

// Function to calculate the frequency of each word in the input string
void calculate_frequency(char **tokens, int num_tokens, int *frequency) {
    for (int i = 0; i < num_tokens; i++) {
        int j = 0;
        while (j < num_tokens) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                frequency[i]++;
                j = num_tokens;
            } else {
                j++;
            }
        }
    }
}

// Function to classify the input string as spam or not spam
int classify(int *frequency, int num_tokens) {
    int spam_count = 0;
    for (int i = 0; i < num_tokens; i++) {
        if (frequency[i] >= 2) {
            spam_count++;
        }
    }

    if (spam_count >= 3) {
        return 1; // Spam
    } else {
        return 0; // Not spam
    }
}

int main() {
    char input_string[1000];
    char *tokens[100];
    int frequency[100];

    printf("Enter input string: ");
    fgets(input_string, sizeof(input_string), stdin);

    tokenize(input_string, tokens);
    calculate_frequency(tokens, sizeof(tokens)/sizeof(tokens[0]), frequency);

    int result = classify(frequency, sizeof(tokens)/sizeof(tokens[0]));

    if (result == 1) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }

    return 0;
}