//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
// Title: Galactic Codex: Alien Language Translator
//
// Description: A C program that translates human language into Alien language.
//              This program uses a dictionary of human words and their
//              corresponding Alien language equivalents.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50
#define ALIEN_ALPHABET "XQWVZDGCBFMPRTLNE&"

typedef struct {
    char word[WORD_LENGTH];
    char alien[WORD_LENGTH];
} word_t;

void translate_word(const char *word) {
    int i, j;
    char alien_char;

    for (i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            j = toupper(word[i]) - 'A';
            alien_char = ALIEN_ALPHABET[j % strlen(ALIEN_ALPHABET)];
            printf("%c", alien_char);
        } else {
            printf("%c", word[i]);
        }
    }
    printf(" ");
}

int main() {
    word_t words[MAX_WORDS];
    int num_words = 0;
    char input[1024];

    // Load dictionary
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        return 1;
    }

    while (fscanf(dictionary_file, "%s %s", words[num_words].word, words[num_words].alien) != EOF) {
        num_words++;
    }

    fclose(dictionary_file);

    // Translation loop
    printf("Enter a word to translate (type 'quit' to exit):\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "quit") == 0) {
            break;
        }

        printf("Human: %s\n", input);
        translate_word(input);
        printf("Alien: ");

        for (int i = 0; words[num_words - 1].word[i] != '\0'; i++) {
            if (strcmp(input, words[num_words - 1].word) == 0) {
                for (int j = 0; words[num_words - 1].alien[j] != '\0'; j++) {
                    printf("%c", words[num_words - 1].alien[j]);
                }
                break;
            }
            num_words--;
        }

        printf("\n");
    }

    return 0;
}