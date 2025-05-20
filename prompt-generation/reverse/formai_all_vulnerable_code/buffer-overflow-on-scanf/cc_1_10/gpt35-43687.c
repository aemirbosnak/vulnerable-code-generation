//FormAI DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

void check_spelling(char (*words)[MAX_WORD_LENGTH], int word_count, char (*dictionary)[MAX_WORD_LENGTH], int dict_count) {
    int found;
    for (int i = 0; i < word_count; i++) {
        found = 0;
        // convert word to lowercase
        for (int j = 0; j < strlen(words[i]); j++) {
            words[i][j] = tolower(words[i][j]);
        }
        // check if word is in dictionary
        for (int j = 0; j < dict_count; j++) {
            if (strcmp(words[i], dictionary[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s is misspelled.\n", words[i]);
        }
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH], dictionary[MAX_WORDS][MAX_WORD_LENGTH], input_word[MAX_WORD_LENGTH];
    int word_count = 0, dict_count = 0;
    
    // get input words
    printf("Enter text: ");
    while (scanf("%s", input_word) != EOF) {
        if (word_count == MAX_WORDS) {
            printf("Maximum word count exceeded.\n");
            return 1;
        }
        strcpy(words[word_count], input_word);
        word_count++;
    }
    
    // get dictionary words
    printf("Enter dictionary: ");
    while (scanf("%s", input_word) != EOF) {
        if (dict_count == MAX_WORDS) {
            printf("Maximum dictionary count exceeded.\n");
            return 1;
        }
        strcpy(dictionary[dict_count], input_word);
        dict_count++;
    }
    
    check_spelling(words, word_count, dictionary, dict_count);
    
    return 0;
}