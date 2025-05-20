//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 1000

/*
 * This program translates C Cat Language (CCL) to English
 * CCL is a language spoken by cats. It consists of words that sound
 * like meows and purrs.
 * The program takes a CCL sentence as input and outputs the English
 * translation.
 * Example:
 * Input: meow purr meow meow purr
 * Output: cat is happy
 */

// Function to convert a single CCL word to English
void translate_word(char* input_word, char* output_word) {
    if (strcmp(input_word, "meow") == 0) {
        strcpy(output_word, "cat");
    }
    else if (strcmp(input_word, "purr") == 0) {
        strcpy(output_word, "is happy");
    }
    else {
        strcpy(output_word, "unknown");
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    char word[MAX_OUTPUT_SIZE];
    char separator[] = " ";

    printf("Enter C Cat Language sentence: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove newline character from input
    input[strlen(input) - 1] = '\0';

    // Split input into separate words
    char* ptr = strtok(input, separator);
    while (ptr != NULL) {
        translate_word(ptr, word);
        strcat(output, word);
        strcat(output, " ");
        ptr = strtok(NULL, separator);
    }

    printf("English Translation: %s\n", output);

    return 0;
}