//FormAI DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_WORDS 50000

int main(int argc, char *argv[]) {
    char dictionary[MAX_DICT_WORDS][MAX_WORD_LENGTH];
    int dict_size = 0; // number of words currently in dictionary
    char word[MAX_WORD_LENGTH];

    // Open dictionary file and read words into array of strings
    FILE *fp_dict = fopen("dictionary.txt", "r");
    if (fp_dict == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }
    while (fscanf(fp_dict, "%s", word) != EOF) {
        strcpy(dictionary[dict_size], word);
        dict_size++;
    }
    fclose(fp_dict);

    // Open input file and check each word against dictionary
    FILE *fp_input = fopen("input.txt", "r");
    if (fp_input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    while (fscanf(fp_input, "%s", word) != EOF) {
        int word_len = strlen(word);
        // Remove trailing punctuation from word
        if (ispunct(word[word_len - 1])) {
            word[word_len - 1] = '\0';
            word_len--;
        }
        // Convert word to lowercase
        for (int i = 0; i < word_len; i++) {
            word[i] = tolower(word[i]);
        }
        // Check if word is in dictionary
        int found = 0;
        for (int i = 0; i < dict_size; i++) {
            if (strcmp(word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }
        // Print word with correction if it is not in dictionary
        if (!found) {
            printf("%s -> ", word);
            // Check for one-letter-off errors
            for (int i = 0; i < dict_size; i++) {
                int word_diff = 0;
                int dict_word_len = strlen(dictionary[i]);
                if (dict_word_len == word_len) {
                    for (int j = 0; j < dict_word_len; j++) {
                        if (word[j] != dictionary[i][j]) {
                            word_diff++;
                        }
                    }
                    if (word_diff == 1) {
                        printf("%s ", dictionary[i]);
                    }
                }
            }
            printf("\n");
        }
    }
    fclose(fp_input);

    return 0;
}