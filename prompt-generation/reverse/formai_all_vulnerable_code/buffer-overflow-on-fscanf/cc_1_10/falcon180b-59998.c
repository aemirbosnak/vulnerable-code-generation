//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(char *filename, Word *dictionary) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary file\n");
        exit(1);
    }

    int word_count = 0;
    while (fscanf(file, "%s", dictionary[word_count].word)!= EOF) {
        dictionary[word_count++].is_correct = true;
    }

    fclose(file);
}

bool is_word(char *word) {
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

int main() {
    Word dictionary[MAX_WORDS];
    load_dictionary("dictionary.txt", dictionary);

    char input_text[100000];
    printf("Enter the text to check spelling:\n");
    fgets(input_text, sizeof(input_text), stdin);

    char *word = strtok(input_text, " ");
    while (word!= NULL) {
        if (is_word(word)) {
            bool is_correct = false;
            for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word, dictionary[i].word) == 0) {
                    is_correct = true;
                    break;
                }
            }

            if (!is_correct) {
                printf("%s is not in the dictionary\n", word);
            }
        }

        word = strtok(NULL, " ");
    }

    return 0;
}