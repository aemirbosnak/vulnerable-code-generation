//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 100000

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

bool is_word(const char *word) {
    int length = strlen(word);
    if (length >= 1 && isalpha(word[0])) {
        for (int i = 1; i < length; i++) {
            if (!isalnum(word[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

void read_words(struct word *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }
    int count = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (is_word(word)) {
            strcpy(words[count].word, word);
            words[count].count = 1;
            count++;
        }
    }
    fclose(file);
}

void read_text(char *text) {
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error: could not open text.txt\n");
        exit(1);
    }
    fscanf(file, "%s", text);
    fclose(file);
}

void spell_check(const char *text, struct word *words) {
    int length = strlen(text);
    int index = 0;
    while (index < length) {
        char word[MAX_WORD_LENGTH];
        int word_length = 0;
        while (isalnum(text[index]) && word_length < MAX_WORD_LENGTH - 1) {
            word[word_length++] = tolower(text[index++]);
        }
        word[word_length] = '\0';
        struct word *found = NULL;
        for (int i = 0; i < MAX_WORD_COUNT; i++) {
            if (strcmp(words[i].word, word) == 0) {
                found = &words[i];
                break;
            }
        }
        if (found == NULL || strcmp(found->word, word)!= 0) {
            printf("Unknown word: %s\n", word);
        }
        index += word_length - 1;
    }
}

int main() {
    struct word words[MAX_WORD_COUNT];
    read_words(words);
    char text[100000];
    read_text(text);
    spell_check(text, words);
    return 0;
}