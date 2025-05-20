//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to convert all characters to lowercase
char toLowercase(char c) {
    return c >= 'A' && c <= 'Z' ? c + ('a' - 'A') : c;
}

int main() {
    char text[1000], word[100];
    int i, j, len, freq, count = 0;
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    
    // Removing newline character from text
    len = strlen(text);
    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
    
    // Converting all characters to lowercase
    for (i = 0; text[i]; i++) {
        text[i] = toLowercase(text[i]);
    }
    
    printf("Word Frequency in Text:\n");
    printf("-----------------------\n");
    
    // Loop through each letter in text
    for (i = 0; text[i]; i++) {
        // If character is not a letter, move on to next character
        if (!isLetter(text[i])) {
            continue;
        }
        // If character is a letter, start building word and move to next character
        j = 0;
        while (isLetter(text[i+j])) {
            word[j] = text[i+j];
            j++;
        }
        word[j] = '\0';
        // Move to next letter after word
        i += j;
        // Count frequency of word in text
        freq = 1;
        for (j = i; text[j]; j++) {
            if (!isLetter(text[j])) {
                continue;
            }
            int k = 0;
            char temp[100];
            while (isLetter(text[j+k])) {
                temp[k] = text[j+k];
                k++;
            }
            temp[k] = '\0';
            if (strcmp(word, temp) == 0) {
                freq++;
            }
            j += k;
        }
        // Print word frequency
        if (freq > 1) {
            printf("%s: %d\n", word, freq);
        } else {
            printf("%s: %d\n", word, freq);
        }
        count++;
    }
    
    printf("-----------------------\n");
    printf("Total Words: %d", count);
    
    return 0;
}