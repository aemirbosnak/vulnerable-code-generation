//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

int main() {
    char str[MAX_LEN];
    int len, i, j, count;

    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    len = strlen(str);

    // Remove all spaces
    for (i = 0, j = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    // Count the occurrences of each character
    int char_count[256] = {0};
    for (i = 0; str[i] != '\0'; i++) {
        char_count[str[i]]++;
    }

    // Find the most frequently occurring character
    int max_count = 0;
    char max_char;
    for (i = 0; i < 256; i++) {
        if (char_count[i] > max_count) {
            max_count = char_count[i];
            max_char = i;
        }
    }

    // Print the most frequently occurring character
    printf("The most frequently occurring character is '%c' (ASCII value %d), which occurs %d times.\n", max_char, max_char, max_count);

    // Find the least frequently occurring character
    int min_count = max_count;
    char min_char;
    for (i = 0; i < 256; i++) {
        if (char_count[i] > 0 && char_count[i] < min_count) {
            min_count = char_count[i];
            min_char = i;
        }
    }

    // Print the least frequently occurring character
    printf("The least frequently occurring character is '%c' (ASCII value %d), which occurs %d times.\n", min_char, min_char, min_count);

    // Count the number of vowels and consonants
    int vowel_count = 0, consonant_count = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vowel_count++;
        } else if (isalpha(str[i])) {
            consonant_count++;
        }
    }

    // Print the number of vowels and consonants
    printf("The number of vowels is: %d\n", vowel_count);
    printf("The number of consonants is: %d\n", consonant_count);

    return 0;
}