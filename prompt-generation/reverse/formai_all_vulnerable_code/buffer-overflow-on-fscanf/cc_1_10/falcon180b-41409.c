//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_words(Word words[]);
void spell_check(const char* text, Word words[]);

int main() {
    Word words[MAX_WORDS];
    load_words(words);
    char text[10000];
    printf("Enter the text to spell check: ");
    fgets(text, sizeof(text), stdin);
    spell_check(text, words);
    return 0;
}

void load_words(Word words[]) {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].is_correct = true;
        count++;
        if (count >= MAX_WORDS) {
            break;
        }
    }
    fclose(file);
}

void spell_check(const char* text, Word words[]) {
    char word[MAX_WORD_LENGTH];
    char* token = strtok(text, " ");
    while (token!= NULL) {
        strcpy(word, token);
        bool is_correct = false;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                is_correct = true;
                break;
            }
        }
        if (!is_correct) {
            printf("Possible spelling mistake: %s\n", word);
        }
        token = strtok(NULL, " ");
    }
}