//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

char words[MAX_WORDS][WORD_LENGTH];
int num_words = 0;

// Add a word to the words array
void add_word(char* word) {
    // Convert all characters to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    // Add word to words array
    strcpy(words[num_words], word);
    num_words++;
}

// Check if a word is in the words array
int check_word(char* word) {
    // Convert all characters to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    // Check if word is in words array
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE* file = fopen("document.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read words from file and add to words array
    char word[WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        if (isalpha(word[0])) {
            if (!check_word(word)) {
                add_word(word);
            }
        }
    }

    // Close file
    fclose(file);

    // Check spelling of input
    char input[WORD_LENGTH];
    printf("Enter a word to check its spelling: ");
    scanf("%s", input);
    if (check_word(input)) {
        printf("Correct spelling\n");
    } else {
        printf("Incorrect spelling\n");
    }

    return 0;
}