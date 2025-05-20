//FormAI DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 100

// Function to check if a word is spelled correctly
int check_word(char* word, char* dict_words[], int num_dict_words) {
    int i;
    for (i = 0; i < num_dict_words; i++) {
        if (strcmp(word, dict_words[i]) == 0) {
            return 1; // word is spelled correctly
        }
    }
    return 0; // word is spelled incorrectly
}

int main() {
    // Dictionary of words to check against
    char* dict_words[MAX_DICT_WORDS] = {"apple", "banana", "cherry", "orange", "pear", "grape", "mango", "pineapple", "kiwi", "watermelon", "strawberry"};

    // User input word
    char user_word[MAX_WORD_LEN];

    printf("Enter a word to spell check: ");
    scanf("%s", user_word);

    // Convert word to lowercase for case-insensitivity
    int i;
    for (i = 0; user_word[i]; i++) {
        user_word[i] = tolower(user_word[i]);
    }

    if (check_word(user_word, dict_words, MAX_DICT_WORDS)) {
        printf("The word '%s' is spelled correctly.\n", user_word);
    } else {
        printf("The word '%s' is spelled incorrectly.\n", user_word);
        printf("Suggestions:\n");

        // Iterate through each letter in the word and replace it with every letter of the alphabet
        for (i = 0; user_word[i]; i++) {
            char old_char = user_word[i];
            int j;
            for (j = 0; j < 26; j++) {
                user_word[i] = 'a' + j;
                if (check_word(user_word, dict_words, MAX_DICT_WORDS)) {
                    printf("%s\n", user_word);
                }
            }
            user_word[i] = old_char;
        }
    }

    return 0;
}