//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: excited
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 20
#define DICTIONARY_SIZE 2000

struct word_entry {
    char word[WORD_LENGTH];
    int count;
};

char dictionary[DICTIONARY_SIZE][WORD_LENGTH];
int num_words = 0;

void load_dictionary() {
    FILE* fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open dictionary file\n");
        exit(1);
    }

    char word[WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(dictionary[num_words], word);
        num_words++;
    }

    fclose(fp);
}

int is_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void count_words(char* text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char word[WORD_LENGTH];
            j = 0;
            while (isalpha(text[i + j]) && j < WORD_LENGTH - 1) {
                word[j] = tolower(text[i + j]);
                j++;
            }
            word[j] = '\0';

            if (is_word(word)) {
                strcpy(dictionary[num_words], word);
                num_words++;
            }
        }
    }
}

void spell_check(char* text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char word[WORD_LENGTH];
            j = 0;
            while (isalpha(text[i + j]) && j < WORD_LENGTH - 1) {
                word[j] = tolower(text[i + j]);
                j++;
            }
            word[j] = '\0';

            if (!is_word(word)) {
                printf("Misspelled word: %s\n", word);
            }
        }
    }
}

int main() {
    load_dictionary();
    char text[10000];
    printf("Enter text to spell check: ");
    fgets(text, 10000, stdin);
    count_words(text);
    spell_check(text);
    return 0;
}