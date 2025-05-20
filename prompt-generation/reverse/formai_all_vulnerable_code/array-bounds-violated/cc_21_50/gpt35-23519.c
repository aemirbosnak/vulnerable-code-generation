//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char string[MAX_LEN], reversed_string[MAX_LEN], temp;
    int i, j, len;

    printf("Enter a string: ");
    fgets(string, MAX_LEN, stdin);

    len = strlen(string);
    
    // Remove new line character at the end of string from fgets
    if (string[len - 1] == '\n') {
        string[len - 1] = '\0';
        len--;
    }
    
    // Reverse the string
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = string[i];
        reversed_string[i] = string[j];
        reversed_string[j] = temp;
    }
    reversed_string[len] = '\0';
    
    printf("Original string: %s\n", string);
    printf("Reversed string: %s\n", reversed_string);
    
    // Count number of vowels in the string
    int vowel_count = 0;
    for (i = 0; i < len; i++) {
        switch(tolower(string[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel_count++;
                break;
            default:
                break;
        }
    }
    printf("Number of vowels in the string: %d\n", vowel_count);
    
    // Construct a new string by removing non-vowel characters from the original string
    char new_string[MAX_LEN];
    int new_len = 0;
    for (i = 0; i < len; i++) {
        switch(tolower(string[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                new_string[new_len++] = string[i];
                break;
            default:
                break;
        }
    }
    new_string[new_len] = '\0';
    
    printf("New string with only vowels: %s\n", new_string);
    
    // Find the longest word in the string
    int word_start = 0, max_word_len = 0, curr_word_len = 0;
    for (i = 0; i < len; i++) {
        if (string[i] == ' ' || string[i] == '\t') {
            curr_word_len = i - word_start;
            if (curr_word_len > max_word_len) {
                max_word_len = curr_word_len;
            }
            word_start = i + 1;
        }
    }
    // Check the last word in the string
    curr_word_len = len - word_start;
    if (curr_word_len > max_word_len) {
        max_word_len = curr_word_len;
    }
    
    char longest_word[MAX_LEN];
    word_start = 0;
    for (i = 0; i < len; i++) {
        if (string[i] == ' ' || string[i] == '\t') {
            curr_word_len = i - word_start;
            if (curr_word_len == max_word_len) {
                memcpy(longest_word, &string[word_start], curr_word_len);
                longest_word[curr_word_len] = '\0';
                break;
            }
            word_start = i + 1;
        }
    }
    // Check the last word in the string
    curr_word_len = len - word_start;
    if (curr_word_len == max_word_len) {
        memcpy(longest_word, &string[word_start], curr_word_len);
        longest_word[curr_word_len] = '\0';
    }
    
    printf("Longest word in the string: %s\n", longest_word);
    
    return 0;
}