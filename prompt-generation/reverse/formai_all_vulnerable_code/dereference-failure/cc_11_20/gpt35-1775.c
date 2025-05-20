//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *word = "I am grateful for everything in my life.";
    int length = strlen(word);

    // Print original word
    printf("Original word: %s\n", word);

    // Reversing the word
    char *reversed_word = malloc(length + 1);
    int i, j;
    for(i = length - 1, j = 0; i >= 0; i--, j++){
        reversed_word[j] = word[i];
    }
    reversed_word[length] = '\0';

    // Print reversed word
    printf("Reversed word: %s\n", reversed_word);

    // Uppercase every other letter
    char *upper_word = malloc(length + 1);
    for(i = 0; i < length; i++) {
        if(i % 2 == 0) {
            upper_word[i] = toupper(word[i]);
        } else {
            upper_word[i] = word[i];
        }
    }
    upper_word[length] = '\0';

    // Print uppercase every other letter
    printf("Uppercase every other letter: %s\n", upper_word);

    // Replace vowels with asterisks
    char *asterisk_word = malloc(length + 1);
    for(i = 0; i < length; i++) {
        if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            asterisk_word[i] = '*';
        } else {
            asterisk_word[i] = word[i];
        }
    }
    asterisk_word[length] = '\0';

    // Print replaced vowels with asterisks
    printf("Vowels replaced with asterisks: %s\n", asterisk_word);

    // Combine reversed word and uppercase every other letter word
    char *combined_word = malloc(length*2 + 1);
    for(i = 0; i < length; i++) {
        combined_word[i] = reversed_word[i];
    }
    for(j = 0; j < length; j++, i++) {
        combined_word[i] = upper_word[j];
    }
    combined_word[length*2] = '\0';

    // Print combined word
    printf("Combined word: %s\n", combined_word);

    // Free malloc'd memory
    free(reversed_word);
    free(upper_word);
    free(asterisk_word);
    free(combined_word);

    return 0;
}