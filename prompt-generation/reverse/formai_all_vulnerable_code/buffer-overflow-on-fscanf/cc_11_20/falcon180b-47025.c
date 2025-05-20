//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    char input_text[10000];
    char word[MAX_WORD_LENGTH];
    struct word words[MAX_WORDS];
    int num_words = 0;
    int i, j, k;
    FILE *dictionary;

    // Open the dictionary file
    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    // Read the dictionary into an array of words
    while (fscanf(dictionary, "%s", word)!= EOF) {
        strcpy(words[num_words].word, word);
        words[num_words].count = 0;
        num_words++;
    }
    fclose(dictionary);

    // Read the input text
    printf("Enter the text to be checked:\n");
    fgets(input_text, sizeof(input_text), stdin);

    // Convert the input text to lowercase
    for (i = 0; input_text[i]!= '\0'; i++) {
        input_text[i] = tolower(input_text[i]);
    }

    // Check each word in the input text against the dictionary
    for (i = 0; input_text[i]!= '\0'; i++) {
        if (isalpha(input_text[i])) {
            word[0] = input_text[i];
            j = 1;
            while (isalpha(input_text[i+j]) && j < MAX_WORD_LENGTH) {
                word[j] = input_text[i+j];
                j++;
            }
            word[j] = '\0';

            // Check if the word is in the dictionary
            for (k = 0; k < num_words; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    words[k].count++;
                    break;
                }
            }
        }
    }

    // Print the results
    printf("Spell check complete.\n");
    for (i = 0; i < num_words; i++) {
        if (words[i].count == 0) {
            printf("Unknown word: %s\n", words[i].word);
        }
    }

    return 0;
}