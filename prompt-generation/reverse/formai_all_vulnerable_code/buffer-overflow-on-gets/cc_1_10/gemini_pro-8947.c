//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

int main() {
    // Initialize variables
    char input[1024];
    char words[MAX_WORDS][100];
    int word_count = 0;
    int i, j;

    // Get input from user
    printf("Enter a string: ");
    gets(input);

    // Convert the input string to lowercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Split the input string into words
    char *token = strtok(input, " ");
    while (token != NULL) {
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " ");
    }

    // Sort the words in alphabetical order
    for (i = 0; i < word_count - 1; i++) {
        for (j = i + 1; j < word_count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char temp[100];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    // Print the sorted words and their frequencies
    for (i = 0; i < word_count; i++) {
        int frequency = 1;
        for (j = i + 1; j < word_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency++;
            }
        }
        printf("%s: %d\n", words[i], frequency);
    }

    return 0;
}