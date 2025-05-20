//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *english;
    char *alien;
} translation_pair;

int main() {

    // Load translation pairs from file
    FILE *fp = fopen("translation_pairs.txt", "r");
    int num_pairs = 0;
    translation_pair pairs[MAX_WORDS];

    if (fp == NULL) {
        printf("Error: Unable to open translation_pairs.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s", pairs[num_pairs].english, pairs[num_pairs].alien)!= EOF) {
        num_pairs++;
    }

    fclose(fp);

    // Prompt user for input
    char input_text[MAX_WORD_LENGTH];
    printf("Enter text to translate:\n");
    fgets(input_text, MAX_WORD_LENGTH, stdin);

    // Remove newline character from input
    input_text[strcspn(input_text, "\n")] = '\0';

    // Translate input text
    char output_text[MAX_WORD_LENGTH];
    int output_index = 0;

    for (int i = 0; i < strlen(input_text); i++) {
        char c = tolower(input_text[i]);

        // Check if character is a letter
        if (isalpha(c)) {
            // Find translation pair for letter
            int j;
            for (j = 0; j < num_pairs; j++) {
                if (tolower(pairs[j].english[0]) == c) {
                    strncat(output_text, pairs[j].alien, MAX_WORD_LENGTH - output_index);
                    output_index += strlen(pairs[j].alien);
                    break;
                }
            }

            // If no translation pair is found, use the original character
            if (j == num_pairs) {
                strncat(output_text, &c, MAX_WORD_LENGTH - output_index);
                output_index++;
            }
        } else {
            // Copy non-letter characters as is
            strncat(output_text, &c, MAX_WORD_LENGTH - output_index);
            output_index++;
        }
    }

    // Print translated text
    printf("Translated text: %s\n", output_text);

    return 0;
}