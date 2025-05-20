//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_LENGTH 100
#define MAX_CAT_LENGTH 20
#define MAX_CAT_COUNT 5
int main() {
    // Get input string from user
    char input[MAX_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
    
    // Convert input string to lowercase
    char* input_lower = strdup(input);
    for (int i = 0; input_lower[i]; i++) {
        input_lower[i] = tolower(input_lower[i]);
    }
    
    // Split input string into words
    char* words[MAX_CAT_COUNT];
    int word_count = 0;
    char* word = strtok(input_lower, " \t\n");
    while (word) {
        if (word_count >= MAX_CAT_COUNT) {
            break;
        }
        words[word_count] = strdup(word);
        word_count++;
        word = strtok(NULL, " \t\n");
    }
    
    // Translate each word to Cat Language
    char* translated_words[MAX_CAT_COUNT];
    for (int i = 0; i < word_count; i++) {
        char* translated_word = (char*)malloc(MAX_CAT_LENGTH * sizeof(char));
        int length = strlen(words[i]);
        for (int j = 0; j < length; j++) {
            if (isalpha(words[i][j])) {
                int index = words[i][j] - 'a';
                if (index < 0 || index > 26) {
                    index = words[i][j] - 'A';
                }
                translated_word[j] = index + 'A';
            }
            else {
                translated_word[j] = words[i][j];
            }
        }
        translated_words[i] = translated_word;
    }
    
    // Print translated words
    printf("Translated words:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", translated_words[i]);
    }
    
    // Free memory
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(input_lower);
    for (int i = 0; i < word_count; i++) {
        free(translated_words[i]);
    }
    
    return 0;
}