//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 1000
#define MAX_SENTENCE_LENGTH 5000

// Function to remove leading and trailing white spaces from a string
void trim(char* str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (isspace(str[i])) {
        i++;
    }

    while (isspace(str[j])) {
        j--;
    }

    strncpy(str, &str[i], j - i + 1);
    str[j - i + 1] = '\0';
}

// Function to check if a word is a palindrome
int is_palindrome(char* word) {
    int i = 0;
    int j = strlen(word) - 1;

    while (i < j) {
        if (tolower(word[i])!= tolower(word[j])) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

// Function to check if a sentence is a palindrome
int is_palindrome_sentence(char* sentence) {
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        if (!is_palindrome(word)) {
            return 0;
        }
        word = strtok(NULL, " ");
    }
    return 1;
}

int main() {
    char input_sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(input_sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove leading and trailing white spaces
    trim(input_sentence);

    // Check if the input is a palindrome
    if (is_palindrome_sentence(input_sentence)) {
        printf("The input is a palindrome.\n");
    } else {
        printf("The input is not a palindrome.\n");
    }

    return 0;
}