//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all spaces from a string
char* remove_spaces(char* str) {
    char* new_str = (char*)malloc(strlen(str) + 1);
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
    return new_str;
}

// Function to count the number of words in a string
int count_words(char* str) {
    int count = 0;
    int in_word = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !in_word) {
            count++;
            in_word = 1;
        }
        else if (str[i] == ' ') {
            in_word = 0;
        }
    }
    return count;
}

// Function to reverse a string
char* reverse_string(char* str) {
    int len = strlen(str);
    char* new_str = (char*)malloc(len + 1);
    for (int i = 0, j = len - 1; i < len; i++, j--) {
        new_str[i] = str[j];
    }
    new_str[len] = '\0';
    return new_str;
}

// Function to find the longest word in a string
char* longest_word(char* str) {
    char* longest = NULL;
    int max_len = 0;
    char* start = str;
    while (*str != '\0') {
        if (*str == ' ') {
            if (str - start > max_len) {
                max_len = str - start;
                longest = start;
            }
            start = str + 1;
        }
        str++;
    }
    if (str - start > max_len) {
        max_len = str - start;
        longest = start;
    }
    char* new_str = (char*)malloc(max_len + 1);
    strncpy(new_str, longest, max_len);
    new_str[max_len] = '\0';
    return new_str;
}

// Function to find the most frequent word in a string
char* most_frequent_word(char* str) {
    char* words[100];
    int counts[100];
    int num_words = 0;
    char* start = str;
    while (*str != '\0') {
        if (*str == ' ') {
            *str = '\0';
            words[num_words] = start;
            counts[num_words] = 1;
            num_words++;
            start = str + 1;
        }
        str++;
    }
    *str = '\0';
    words[num_words] = start;
    counts[num_words] = 1;
    num_words++;
    int max_count = 0;
    char* most_frequent = NULL;
    for (int i = 0; i < num_words; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            most_frequent = words[i];
        }
    }
    return most_frequent;
}

int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Remove all spaces from the string
    char* new_str = remove_spaces(str);
    printf("String without spaces: %s\n", new_str);

    // Count the number of words in the string
    int num_words = count_words(str);
    printf("Number of words in the string: %d\n", num_words);

    // Reverse the string
    char* reversed_str = reverse_string(str);
    printf("Reversed string: %s\n", reversed_str);

    // Find the longest word in the string
    char* longest = longest_word(str);
    printf("Longest word in the string: %s\n", longest);

    // Find the most frequent word in the string
    char* most_frequent = most_frequent_word(str);
    printf("Most frequent word in the string: %s\n", most_frequent);

    // Free the allocated memory
    free(new_str);
    free(reversed_str);
    free(longest);
    return 0;
}