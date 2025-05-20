//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 20
#define MAX_DICTIONARY_WORDS 1000
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LEN];
    int length;
    int is_correct;
} Word;

void load_dictionary(Word *dictionary) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s", dictionary[num_words].word)!= EOF) {
        dictionary[num_words].length = strlen(dictionary[num_words].word);
        dictionary[num_words].is_correct = 1;
        num_words++;
        if (num_words >= MAX_DICTIONARY_WORDS) {
            printf("Error: Dictionary file is too large.\n");
            exit(1);
        }
    }

    fclose(file);
}

void spell_check(char *sentence, Word *dictionary) {
    int num_words = 0;
    char word[MAX_WORD_LEN];
    int i, j;

    for (i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            word[num_words] = tolower(sentence[i]);
            num_words++;
        }
    }

    word[num_words] = '\0';

    for (i = 0; i < num_words; i++) {
        for (j = 0; j < MAX_DICTIONARY_WORDS; j++) {
            if (strcmp(word, dictionary[j].word) == 0) {
                printf("%s is correct.\n", word);
                break;
            }
        }

        if (j == MAX_DICTIONARY_WORDS) {
            printf("%s is not in dictionary.\n", word);
        }
    }
}

int main() {
    Word dictionary[MAX_DICTIONARY_WORDS];
    load_dictionary(dictionary);

    char sentence[1000];
    printf("Enter a sentence to spell check: ");
    fgets(sentence, 1000, stdin);

    spell_check(sentence, dictionary);

    return 0;
}