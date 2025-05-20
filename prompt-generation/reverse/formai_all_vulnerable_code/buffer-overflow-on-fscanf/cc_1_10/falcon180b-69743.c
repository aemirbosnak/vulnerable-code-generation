//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define DICTIONARY_FILE "dictionary.txt"
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word dictionary[]);
bool is_word_correct(const char* word, Word dictionary[]);

int main() {
    Word dictionary[10000];
    load_dictionary(dictionary);

    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    char* word = strtok(sentence, " \t\n\r\f\v");
    while (word!= NULL) {
        if (is_word_correct(word, dictionary)) {
            printf("%s\n", word);
        } else {
            printf("*%s*\n", word);
        }
        word = strtok(NULL, " \t\n\r\f\v");
    }

    return 0;
}

void load_dictionary(Word dictionary[]) {
    FILE* file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s", dictionary[num_words].word)!= EOF) {
        dictionary[num_words].is_correct = true;
        num_words++;
    }

    fclose(file);
}

bool is_word_correct(const char* word, Word dictionary[]) {
    int length = strlen(word);
    if (length > MAX_WORD_LENGTH) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]);
        if (!isalpha(c)) {
            return false;
        }
    }

    for (int i = 0; i < 10000; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return true;
        }
    }

    return false;
}