//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Defining the maximum length of a word */
#define MAX_WORD_LEN 100

/* Defining the alien language's alphabet */
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";

int main() {
    char input_text[1000], output_text[1000];
    int i, j;

    /* Getting the input text from the user */
    printf("Enter the text to translate: ");
    fgets(input_text, 1000, stdin);

    /* Removing leading/trailing white spaces from the input text */
    for (i = 0; input_text[i]!= '\0'; i++) {
        if (!isspace(input_text[i])) {
            input_text[i - strlen(input_text) + 1] = input_text[i];
            input_text[i] = '\0';
            break;
        }
    }

    /* Translating the input text to the alien language */
    for (i = 0; input_text[i]!= '\0'; i++) {
        if (isalpha(input_text[i])) {
            if (isupper(input_text[i])) {
                output_text[i] = alien_alphabet[toupper(input_text[i]) - 'A'];
            } else {
                output_text[i] = alien_alphabet[tolower(input_text[i]) - 'a'];
            }
        } else {
            output_text[i] = input_text[i];
        }
    }

    /* Adding leading/trailing white spaces back to the output text */
    for (i = strlen(output_text) - 1; i >= 0; i--) {
        if (!isspace(output_text[i])) {
            output_text[i + strlen(output_text) + 1] = output_text[i];
            output_text[i] = '\0';
            break;
        }
    }

    /* Displaying the translated text */
    printf("Translated text: %s\n", output_text);

    return 0;
}