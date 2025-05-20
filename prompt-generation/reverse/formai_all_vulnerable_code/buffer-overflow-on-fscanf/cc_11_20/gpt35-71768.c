//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word
#define MAX_NUM_WORDS 10000 // Maximum number of unique words in file

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    
    if (!file) {
        fprintf(stderr, "Can't open file %s\n", filename);
        exit(1);
    }
    
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH]; // Array to store unique words
    int frequencies[MAX_NUM_WORDS]; // Array to store corresponding word frequencies
    int num_words = 0; // Number of unique words in file
    
    char current_word[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", current_word) == 1) {
        // Remove any non-alphabetic characters
        int length = strlen(current_word);
        int j = 0;
        for (int i = 0; i < length; i++) {
            if (isalpha(current_word[i])) {
                current_word[j++] = tolower(current_word[i]);
            }
        }
        current_word[j] = '\0';
        
        if (strlen(current_word) > 0) {
            // Check if current word is already in words array
            int index = -1;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(words[i], current_word) == 0) {
                    index = i;
                    break;
                }
            }
            
            if (index == -1) {
                // Add new word to array
                strcpy(words[num_words], current_word);
                frequencies[num_words] = 1;
                num_words++;
            } else {
                // Increment frequency of existing word
                frequencies[index]++;
            }
        }
    }
    
    // Print results
    printf("Word frequencies in %s:\n", filename);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }
    
    // Close file
    fclose(file);
    
    return 0;
}