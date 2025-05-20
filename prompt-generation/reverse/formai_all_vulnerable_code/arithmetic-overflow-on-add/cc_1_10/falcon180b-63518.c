//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 3

// Function to calculate the frequency of each word in the input text
void calculate_word_frequency(char* input_text, int* word_frequency) {
    char word[MAX_WORD_LENGTH];
    char delimiter[] = " \t\n\r\f\v";
    int word_count = 0;

    for (int i = 0; i < strlen(input_text); i++) {
        if (strchr(delimiter, input_text[i])!= NULL) {
            if (strlen(word) >= MIN_WORD_LENGTH) {
                word_count++;
            }
            strcpy(word, "");
        } else {
            strncat(word, &input_text[i], 1);
        }
    }

    if (strlen(word) >= MIN_WORD_LENGTH) {
        word_count++;
    }

    for (int i = 0; i < strlen(input_text); i++) {
        if (strchr(delimiter, input_text[i])!= NULL) {
            strcpy(word, "");
        } else {
            strncat(word, &input_text[i], 1);
        }

        if (strlen(word) >= MIN_WORD_LENGTH) {
            int word_index = hash(word);
            word_frequency[word_index]++;
        }
    }
}

// Function to hash a word to a unique index in the word frequency array
int hash(char* word) {
    int hash_value = 0;
    int power = 1;

    for (int i = 0; i < strlen(word); i++) {
        hash_value += tolower(word[i]) * power;
        power *= 31;
    }

    return hash_value % 100000;
}

// Function to check if an email is spam based on its word frequency
int is_spam(int* word_frequency) {
    int spam_count = 0;

    for (int i = 0; i < 100000; i++) {
        if (word_frequency[i] > 0) {
            spam_count++;
        }
    }

    if (spam_count >= 5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input_text[100000];
    int word_frequency[100000];

    printf("Enter the input text: ");
    fgets(input_text, sizeof(input_text), stdin);

    calculate_word_frequency(input_text, word_frequency);

    if (is_spam(word_frequency)) {
        printf("The input text is spam.\n");
    } else {
        printf("The input text is not spam.\n");
    }

    return 0;
}