//FormAI DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 26

bool is_word_correct(char *word);

int main(void) {
    char word[MAX_WORD_LENGTH];
    int num_words_checked = 0;
    int num_correct_words = 0;

    while(scanf("%s", word) == 1) {
        num_words_checked++;
        if(is_word_correct(word)) {
            printf("The word \"%s\" is spelled correctly!\n", word);
            num_correct_words++;
        } else {
            printf("The word \"%s\" is misspelled!\n", word);
        }
    }

    printf("Checked %d words. %d were correct and %d were incorrect.\n", 
        num_words_checked, num_correct_words, num_words_checked - num_correct_words);
    return 0;
}

bool is_word_correct(char *word) {
    // Check if first letter is capitalized
    if(islower(word[0])) {
        return false;
    }

    // Check if word has any non-alphabetic characters
    int i = 0;
    while(word[i] != '\0') {
        if(!isalpha(word[i])) {
            return false;
        }
        i++;
    }

    // Check if word is longer than MAX_WORD_LENGTH characters
    if(i > MAX_WORD_LENGTH) {
        return false;
    }

    // If all the above checks pass, assume the word is spelled correctly
    return true;
}