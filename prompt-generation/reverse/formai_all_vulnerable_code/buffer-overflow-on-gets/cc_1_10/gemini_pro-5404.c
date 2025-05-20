//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STRING_LENGTH 100

// Define a function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Define a function to remove all spaces from a string
void remove_spaces(char *str) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Define a function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ') {
            count++;
        }
    }
    if (str[len - 1] != ' ') {
        count++;
    }
    return count;
}

// Define a function to find the longest word in a string
char *find_longest_word(char *str) {
    int len = strlen(str);
    int max_len = 0;
    char *longest_word = NULL;
    char *current_word = NULL;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            if (current_word == NULL) {
                current_word = str + i;
            }
        } else {
            if (current_word != NULL) {
                int current_len = strlen(current_word);
                if (current_len > max_len) {
                    max_len = current_len;
                    longest_word = current_word;
                }
                current_word = NULL;
            }
        }
    }
    if (current_word != NULL) {
        int current_len = strlen(current_word);
        if (current_len > max_len) {
            max_len = current_len;
            longest_word = current_word;
        }
    }
    return longest_word;
}

// Define a function to find the most common character in a string
char find_most_common_character(char *str) {
    int len = strlen(str);
    int counts[256] = {0};
    for (int i = 0; i < len; i++) {
        counts[str[i]]++;
    }
    int max_count = 0;
    char most_common_character = '\0';
    for (int i = 0; i < 256; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            most_common_character = i;
        }
    }
    return most_common_character;
}

int main() {
    // Get a string from the user
    char str[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    gets(str);

    // Reverse the string
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    // Remove all spaces from the string
    remove_spaces(str);
    printf("String with no spaces: %s\n", str);

    // Count the number of words in the string
    int word_count = count_words(str);
    printf("Word count: %d\n", word_count);

    // Find the longest word in the string
    char *longest_word = find_longest_word(str);
    printf("Longest word: %s\n", longest_word);

    // Find the most common character in the string
    char most_common_character = find_most_common_character(str);
    printf("Most common character: %c\n", most_common_character);

    return 0;
}