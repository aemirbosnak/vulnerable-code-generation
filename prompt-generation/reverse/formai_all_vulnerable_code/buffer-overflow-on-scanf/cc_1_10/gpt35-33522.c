//FormAI DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 30
#define DICT_SIZE 7

char dictionary[DICT_SIZE][MAX_WORD_LEN] = {"program", "language", "computer", 
                                            "algorithm", "variable", "syntax", "loop"};

int main() {
    char input[MAX_WORD_LEN];
    printf("Enter a word to check its spelling: ");
    scanf("%s", input);

    // Convert the word to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Check if the word is in the dictionary
    int found_match = 0;
    for (int i = 0; i < DICT_SIZE; i++) {
        if (strcmp(input, dictionary[i]) == 0) {
            found_match = 1;
            break;
        }
    }

    if (found_match) {
        printf("The word '%s' is spelled correctly.\n", input);
    } else {
        printf("The word '%s' is misspelled. Possible suggestions:\n", input);
        // Generate suggestions by changing one letter at a time
        for (int i = 0; i < strlen(input); i++) {
            char original_char = input[i];
            for (char letter = 'a'; letter <= 'z'; letter++) {
                if (letter == original_char) {
                    continue;
                }
                input[i] = letter;
                for (int j = 0; j < DICT_SIZE; j++) {
                    if (strcmp(input, dictionary[j]) == 0) {
                        printf("- %s\n", input);
                    }        
                }
            }
            input[i] = original_char;
        }
    }
    
    return 0;
}