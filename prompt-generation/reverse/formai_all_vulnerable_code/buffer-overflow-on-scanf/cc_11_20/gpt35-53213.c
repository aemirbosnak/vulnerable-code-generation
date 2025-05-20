//FormAI DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20 // maximum length of a word
#define MAX_WORDS 100 // maximum number of words in a sentence

int main() {
    char sentence[MAX_WORDS][MAX_WORD_LENGTH] = {0}; // array to hold words in sentence
    char word[MAX_WORD_LENGTH] = {0}; // variable to hold current word
    int num_words = 0; // number of words in sentence
    int i, j;
    int misspellings = 0; // number of misspelled words

    printf("Enter a sentence:\n");

    // read input and separate into words
    while (scanf("%s", word) == 1) {
        // normalize word to lowercase
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        // remove punctuation from end of word if present
        while (ispunct(word[strlen(word) - 1])) {
            word[strlen(word) - 1] = 0;
        }
        // add word to sentence array
        strcpy(sentence[num_words], word);
        num_words++;
    }

    // check each word for spelling errors
    for (i = 0; i < num_words; i++) {
        // assume word is spelled correctly
        int spelled_correctly = 1;

        // check if word is in dictionary
        FILE *dict = fopen("dictionary.txt", "r");
        while (!feof(dict) && spelled_correctly) {
            char dict_word[MAX_WORD_LENGTH] = {0};
            fscanf(dict, "%s", dict_word);
            if (strcmp(sentence[i], dict_word) == 0) {
                spelled_correctly = 1;
                break;
            }
            spelled_correctly = 0;
        }
        fclose(dict);

        // count misspellings and offer suggestions
        if (!spelled_correctly) {
            printf("'%s' is misspelled\n", sentence[i]);
            misspellings++;
            printf("Suggestions:\n");
            for (j = 0; j < strlen(sentence[i]); j++) {
                char original_char = sentence[i][j];
                for (char c = 'a'; c <= 'z'; c++) {
                    sentence[i][j] = c;
                    dict = fopen("dictionary.txt", "r");
                    while (!feof(dict)) {
                        char dict_word[MAX_WORD_LENGTH] = {0};
                        fscanf(dict, "%s", dict_word);
                        if (strcmp(sentence[i], dict_word) == 0) {
                            printf("%s\n", sentence[i]);
                        }
                    }
                    fclose(dict);
                }
                sentence[i][j] = original_char;
            }
        }
    }

    // print summary of spell checking results
    if (misspellings == 0) {
        printf("No spelling errors found\n");
    } else if (misspellings == 1) {
        printf("1 spelling error found\n");
    } else {
        printf("%d spelling errors found\n", misspellings);
    }

    return 0;
}