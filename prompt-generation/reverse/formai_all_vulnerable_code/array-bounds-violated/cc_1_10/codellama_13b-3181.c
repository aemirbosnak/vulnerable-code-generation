//Code Llama-13B DATASET v1.0 Category: Text processing ; Style: standalone
/*
 * Program: text_processing.c
 * Author: [Your Name]
 * Purpose: A unique C text processing example program in a standalone style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Declare variables
    char text[100];
    char word[10];
    int i, j;

    // Get input from user
    printf("Enter a sentence: ");
    fgets(text, 100, stdin);

    // Remove new line character from end of text
    text[strlen(text) - 1] = '\0';

    // Print text in reverse
    printf("Reverse of the sentence: ");
    for (i = strlen(text) - 1; i >= 0; i--) {
        printf("%c", text[i]);
    }
    printf("\n");

    // Print each word in reverse
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            // Get word
            for (j = 0; j < i; j++) {
                word[j] = text[j];
            }
            word[j] = '\0';

            // Print word in reverse
            printf("Reverse of word: ");
            for (j = strlen(word) - 1; j >= 0; j--) {
                printf("%c", word[j]);
            }
            printf("\n");

            // Move to next word
            i++;
        }
    }

    return 0;
}