//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

// function to remove punctuations from a string
void remove_punctuations(char* string) {
    int index = 0;
    while (string[index] != '\0') {
        if (ispunct(string[index])) {
            int i = index;
            while (string[i] != '\0') {
                string[i] = string[i + 1];
                i++;
            }
            continue;
        }
        index++;
    }
}

// function to format a string to lower case
void format_string(char* string) {
    int i = 0;
    while (string[i] != '\0') {
        string[i] = tolower(string[i]);
        i++;
    }
}

int main() {
    char sentence[1000];
    char word[MAX_WORD_LENGTH];
    int word_count = 0, sentence_length = 0, i = 0, j = 0;
    int letter_count[MAX_WORD_LENGTH] = { 0 }; // initialize all elements to 0
    bool is_new_word = true;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // remove new line character from the input sentence
    sentence_length = strlen(sentence);
    sentence[sentence_length - 1] = '\0';

    // remove punctuations from the sentence
    remove_punctuations(sentence);

    while (sentence[i] != '\0') {
        if (sentence[i] == ' ') {
            is_new_word = true;
            word[word_count] = '\0';
            format_string(word);
            for (j = 0; j < MAX_WORD_LENGTH && word[j] != '\0'; j++) {
                letter_count[word[j] - 'a']++;
            }
            word_count = 0;
        }
        else {
            if (is_new_word) {
                is_new_word = false;
            }
            word[word_count] = sentence[i];
            word_count++;
        }
        i++;
    }

    // process the last word in the sentence
    word[word_count] = '\0';
    format_string(word);
    for (j = 0; j < MAX_WORD_LENGTH && word[j] != '\0'; j++) {
        letter_count[word[j] - 'a']++;
    }

    // display the frequency count of each letter in the sentence
    printf("\nFrequency count of letters in the sentence:\n");
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (letter_count[i] > 0) {
            printf("%c: %d\n", i + 'a', letter_count[i]);
        }
    }

    return 0;
}