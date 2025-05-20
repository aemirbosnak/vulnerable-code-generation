//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(const char* filename, Word* dictionary, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    int word_count = 0;

    while (fscanf(file, "%s", line)!= EOF) {
        strcpy(dictionary[word_count].word, line);
        dictionary[word_count].is_correct = true;
        word_count++;
    }

    fclose(file);

    *size = word_count;
}

bool is_word_correct(const char* word, const Word* dictionary, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return true;
        }
    }
    return false;
}

void suggest_corrections(const char* word, const Word* dictionary, int size) {
    char corrected_word[MAX_WORD_LENGTH];
    int corrected_word_length;

    if (is_word_correct(word, dictionary, size)) {
        printf("%s is correct.\n", word);
        return;
    }

    printf("%s is not correct. Did you mean:\n", word);

    for (int i = 0; i < size; i++) {
        if (strlen(dictionary[i].word) > 0) {
            corrected_word_length = strlen(dictionary[i].word);
            strncpy(corrected_word, dictionary[i].word, corrected_word_length);
            corrected_word[corrected_word_length] = '\0';
            printf("%s\n", corrected_word);
        }
    }
}

int main() {
    Word dictionary[MAX_DICTIONARY_SIZE];
    int dictionary_size = 0;

    load_dictionary("dictionary.txt", dictionary, &dictionary_size);

    char sentence[100];
    printf("Enter a sentence to spell check:\n");
    fgets(sentence, sizeof(sentence), stdin);

    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        if (strlen(word) > 0) {
            suggest_corrections(word, dictionary, dictionary_size);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}