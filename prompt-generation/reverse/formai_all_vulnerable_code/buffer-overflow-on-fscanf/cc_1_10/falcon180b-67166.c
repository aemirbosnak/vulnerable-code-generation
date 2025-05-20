//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word dictionary[MAX_WORDS]) {
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Could not open dictionary file.\n");
        exit(1);
    }

    int word_count = 0;
    while (fscanf(dictionary_file, "%s", dictionary[word_count].word)!= EOF) {
        dictionary[word_count].is_correct = true;
        word_count++;
    }

    fclose(dictionary_file);
}

bool is_word(const char *word) {
    int length = strlen(word);
    if (length > MAX_WORD_LENGTH) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }

    return true;
}

void spell_check(const char *text, Word dictionary[MAX_WORDS]) {
    int word_count = 0;
    char word[MAX_WORD_LENGTH];

    while (*text!= '\0') {
        if (is_word(text)) {
            strncpy(word, text, MAX_WORD_LENGTH);
            word[MAX_WORD_LENGTH - 1] = '\0';

            bool is_correct = false;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(word, dictionary[i].word) == 0) {
                    is_correct = true;
                    break;
                }
            }

            if (!is_correct) {
                printf("Possible spelling mistake: %s\n", word);
            }
        }

        text += strlen(word) + 1;
        word_count++;
    }
}

int main() {
    Word dictionary[MAX_WORDS];
    load_dictionary(dictionary);

    char text[1000];
    printf("Enter text to spell check: ");
    fgets(text, sizeof(text), stdin);

    spell_check(text, dictionary);

    return 0;
}