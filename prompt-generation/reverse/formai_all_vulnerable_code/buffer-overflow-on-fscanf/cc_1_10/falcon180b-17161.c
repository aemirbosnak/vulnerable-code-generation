//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 30

struct word {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
};

void load_dictionary(struct word *dictionary) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error loading dictionary\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count].word)!= EOF) {
        dictionary[count].is_correct = true;
        count++;
    }

    fclose(file);
}

bool is_correct(const char *word) {
    int i = 0;
    while (isalpha(word[i])) {
        if (tolower(word[i])!= tolower(word[0])) {
            return false;
        }
        i++;
    }

    return true;
}

void spell_check(const char *text, struct word *dictionary) {
    int index = 0;
    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    while (text[index]) {
        if (isalpha(text[index])) {
            if (word_length == 0) {
                word[word_length++] = tolower(text[index]);
            } else if (word_length == MAX_WORD_LENGTH) {
                printf("Error: word \"%s\" is too long\n", word);
                exit(1);
            } else {
                word[word_length++] = tolower(text[index]);
            }
        } else {
            if (word_length > 0) {
                word[word_length] = '\0';
                if (!is_correct(word)) {
                    printf("Possible typo: \"%s\"\n", word);
                }
            }
            word_length = 0;
        }

        index++;
    }

    if (word_length > 0) {
        word[word_length] = '\0';
        if (!is_correct(word)) {
            printf("Possible typo: \"%s\"\n", word);
        }
    }
}

int main() {
    struct word dictionary[MAX_WORDS];
    load_dictionary(dictionary);

    char text[1000000];
    printf("Enter text to spell check: ");
    fgets(text, sizeof(text), stdin);

    spell_check(text, dictionary);

    return 0;
}