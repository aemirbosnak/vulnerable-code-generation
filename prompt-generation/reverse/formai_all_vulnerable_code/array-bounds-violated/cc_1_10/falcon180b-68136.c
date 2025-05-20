//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the frequency of words
void count_words(char *filename) {
    FILE *fp;
    char ch;
    int i = 0;
    char word[100];
    int freq[26] = {0}; // Initialize an array to store the frequency of each letter

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Loop through each character in the file
    while ((ch = fgetc(fp))!= EOF) {
        // Convert character to lowercase
        ch = tolower(ch);

        // Check if the character is a letter
        if (isalpha(ch)) {
            // Append the character to the word
            strncat(word, &ch, 1);
        } else {
            // If the character is not a letter, the word is complete
            word[i] = '\0';

            // Increment the frequency of the word
            freq[word[0] - 'a']++;

            // Reset the word
            i = 0;
        }
    }

    // Close the file
    fclose(fp);

    // Print the frequency of each letter
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', freq[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    count_words(argv[1]);

    return 0;
}