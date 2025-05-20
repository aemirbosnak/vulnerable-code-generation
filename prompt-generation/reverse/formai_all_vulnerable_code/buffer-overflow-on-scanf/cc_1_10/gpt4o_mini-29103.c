//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int count;
};

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_valid_char(char ch) {
    return isalpha(ch) || ch == '\''; // Allow apostrophes in contractions
}

int main() {
    printf("=== The Grand Word Frequency Counter ===\n");
    printf("Enter the sacred text (end with 'finish'):\n");

    struct WordFrequency wordList[MAX_WORDS] = {0};
    int totalWords = 0;

    char input[MAX_WORD_LENGTH];
    while (1) {
        scanf("%s", input);
        
        if (strcmp(input, "finish") == 0) {
            break;
        }

        // Clean the word by removing invalid characters
        char cleanWord[MAX_WORD_LENGTH] = {0};
        int j = 0;
        
        for (int i = 0; input[i]; i++) {
            if (is_valid_char(input[i])) {
                cleanWord[j++] = input[i];
            }
        }
        cleanWord[j] = '\0';
        
        if (strlen(cleanWord) > 0) {
            to_lower_case(cleanWord);

            // Check if the word already exists
            int found = 0;
            for (int k = 0; k < totalWords; k++) {
                if (strcmp(wordList[k].word, cleanWord) == 0) {
                    wordList[k].count++;
                    found = 1;
                    break;
                }
            }

            // If not found, add the new word
            if (!found) {
                strcpy(wordList[totalWords].word, cleanWord);
                wordList[totalWords].count = 1;
                totalWords++;
            }
        }
    }

    // Sorting the word frequencies
    for (int i = 0; i < totalWords - 1; i++) {
        for (int j = i + 1; j < totalWords; j++) {
            if (wordList[i].count < wordList[j].count) {
                struct WordFrequency temp = wordList[i];
                wordList[i] = wordList[j];
                wordList[j] = temp;
            }
        }
    }

    // Printing the results
    printf("\n=== Word Frequency Count ===\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    printf("=== The End of the Count ===\n");
    return 0;
}