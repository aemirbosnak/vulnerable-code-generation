//FormAI DATASET v1.0 Category: Text processing ; Style: modular
#include <stdio.h>

// Function to count the number of vowels
int count_vowels(char *str) {
    int count = 0;
    while (*str) {
        switch (*str) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count++;
                break;
        }
        str++;
    }
    return count;
}

// Function to count the number of words
int count_words(char *str) {
    int count = 0;
    while (*str) {
        while (*str == ' ') {
            str++;
        }
        if (*str != '\0') {
            count++;
        }
        while (*str != ' ' && *str != '\0') {
            str++;
        }
    }
    return count;
}

int main() {
    // Read the input string from the user
    printf("Enter a string: ");
    char str[100];
    gets(str);

    // Count the number of vowels in the string
    int num_vowels = count_vowels(str);

    // Count the number of words in the string
    int num_words = count_words(str);

    // Print the results
    printf("Number of vowels: %d\n", num_vowels);
    printf("Number of words: %d\n", num_words);

    return 0;
}