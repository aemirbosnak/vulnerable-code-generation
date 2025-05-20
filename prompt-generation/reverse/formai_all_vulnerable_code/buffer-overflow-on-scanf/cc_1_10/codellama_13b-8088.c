//Code Llama-13B DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

// Function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p == ' ') {
            count++;
        }
        p++;
    }
    return count;
}

// Function to count the number of characters in a string
int count_characters(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        count++;
        p++;
    }
    return count;
}

// Function to count the number of unique words in a string
int count_unique_words(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p == ' ') {
            count++;
        }
        p++;
    }
    return count;
}

// Function to count the number of vowels in a string
int count_vowels(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
            count++;
        }
        p++;
    }
    return count;
}

// Function to count the number of consonants in a string
int count_consonants(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u') {
            count++;
        }
        p++;
    }
    return count;
}

// Function to count the number of digits in a string
int count_digits(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p >= '0' && *p <= '9') {
            count++;
        }
        p++;
    }
    return count;
}

// Function to count the number of punctuations in a string
int count_punctuations(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p == ',' || *p == '.' || *p == '!' || *p == '?' || *p == '-' || *p == ';') {
            count++;
        }
        p++;
    }
    return count;
}

// Function to count the number of uppercase letters in a string
int count_uppercase(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p >= 'A' && *p <= 'Z') {
            count++;
        }
        p++;
    }
    return count;
}

// Function to count the number of lowercase letters in a string
int count_lowercase(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            count++;
        }
        p++;
    }
    return count;
}

// Function to count the number of special characters in a string
int count_special_chars(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u' && *p != 'A' && *p != 'E' && *p != 'I' && *p != 'O' && *p != 'U' && *p != ' ') {
            count++;
        }
        p++;
    }
    return count;
}

// Function to count the number of spaces in a string
int count_spaces(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p == ' ') {
            count++;
        }
        p++;
    }
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Word Count: %d\n", count_words(str));
    printf("Character Count: %d\n", count_characters(str));
    printf("Unique Word Count: %d\n", count_unique_words(str));
    printf("Vowel Count: %d\n", count_vowels(str));
    printf("Consonant Count: %d\n", count_consonants(str));
    printf("Digit Count: %d\n", count_digits(str));
    printf("Punctuation Count: %d\n", count_punctuations(str));
    printf("Uppercase Count: %d\n", count_uppercase(str));
    printf("Lowercase Count: %d\n", count_lowercase(str));
    printf("Special Character Count: %d\n", count_special_chars(str));
    printf("Space Count: %d\n", count_spaces(str));

    return 0;
}