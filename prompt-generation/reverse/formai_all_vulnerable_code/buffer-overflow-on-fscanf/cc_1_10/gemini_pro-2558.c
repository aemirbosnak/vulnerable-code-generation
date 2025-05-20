//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            dictionary[i].count++;
            return;
        }
    }
    strcpy(dictionary[num_words].word, word);
    dictionary[num_words].count = 1;
    num_words++;
}

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        add_word(word);
    }
    fclose(fp);
}

int check_spelling(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

void print_suggestions(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            printf("%s (%d)\n", dictionary[i].word, dictionary[i].count);
        }
    }
}

int main() {
    // Load the dictionary
    load_dictionary("dictionary.txt");

    // Get the word to check
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling
    int correct = check_spelling(word);

    // Print the results
    if (correct) {
        printf("The word '%s' is spelled correctly.\n", word);
    } else {
        printf("The word '%s' is not spelled correctly.\n", word);
        printf("Suggestions:\n");
        print_suggestions(word);
    }

    return 0;
}