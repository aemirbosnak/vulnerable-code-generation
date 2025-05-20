//FormAI DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define DICTIONARY_SIZE 100

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_SIZE];
    char word[MAX_WORD_SIZE];
    int i, num_words;
    int found = 0;
    
    // Load the dictionary
    FILE *file = fopen("dictionary.txt", "r");
    if (file) {
        i = 0;
        while (fgets(dictionary[i], MAX_WORD_SIZE, file)) {
            dictionary[i][strlen(dictionary[i])-1] = '\0';
            i++;
        }
        num_words = i;
        fclose(file);
    } else {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }

    // Get input word from user
    printf("Enter word to check: ");
    fgets(word, MAX_WORD_SIZE, stdin);
    word[strlen(word)-1] = '\0';

    // Check if the word is in the dictionary
    for (i=0; i<num_words; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            found = 1;
            break;
        }
    }

    // Output results
    if (found) {
        printf("%s is spelled correctly\n", word);
    } else {
        printf("%s is spelled incorrectly\n", word);
        printf("Did you mean:\n");
        for (i=0; i<num_words; i++) {
            if (strlen(dictionary[i]) == strlen(word)+1 ||
                strlen(dictionary[i]) == strlen(word)-1 ||
                strlen(dictionary[i]) == strlen(word)) {
                int j=0;
                while (dictionary[i][j] && word[j]) {
                    if (dictionary[i][j] != word[j]) {
                        break;
                    }
                    j++;
                }
                if (strlen(&dictionary[i][j]) == strlen(&word[j]+1)) {
                    printf("%s\n", dictionary[i]);
                }
            }
        }
    }

    return 0;
}