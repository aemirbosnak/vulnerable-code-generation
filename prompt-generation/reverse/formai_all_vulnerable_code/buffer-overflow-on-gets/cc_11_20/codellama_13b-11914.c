//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: Ada Lovelace
// Word Frequency Counter in Ada Lovelace style

#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    char text[1000], word[50];
    int i, j, count = 0;

    // Get input text
    printf("Enter text: ");
    gets(text);

    // Convert to lowercase
    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] + 32;
        }
    }

    // Tokenize text
    i = 0;
    while (text[i] != '\0') {
        // Find start of word
        while (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            i++;
        }

        // Find end of word
        j = i;
        while (text[j] != ' ' && text[j] != '\n' && text[j] != '\t' && text[j] != '\0') {
            j++;
        }

        // Copy word to buffer
        strncpy(word, text + i, j - i);
        word[j - i] = '\0';

        // Increment count for current word
        count++;

        // Move to next word
        i = j;
    }

    // Print results
    printf("Word count: %d\n", count);

    return 0;
}