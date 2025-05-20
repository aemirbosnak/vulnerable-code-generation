//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_file(char *filename, Word *words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char ch;
    Word *current_word = words;
    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            current_word->word[current_word->count] = '\0';
            current_word->count = 0;
            current_word++;
        } else {
            if (current_word->count >= MAX_WORD_LENGTH) {
                printf("Error: word too long\n");
                exit(1);
            }
            current_word->word[current_word->count++] = tolower(ch);
        }
    }

    fclose(fp);
}

void translate_words(Word *words) {
    Word *current_word = words;
    while (current_word->count > 0) {
        char *english_word = current_word->word;
        char *alien_word = malloc(MAX_WORD_LENGTH * sizeof(char));

        int i = 0;
        while (i < strlen(english_word)) {
            if (english_word[i] == 'a' || english_word[i] == 'e' || english_word[i] == 'i' || english_word[i] == 'o' || english_word[i] == 'u') {
                strcat(alien_word, "z");
            } else if (english_word[i] >= 'a' && english_word[i] <= 'z') {
                strcat(alien_word, "x");
            } else {
                strcat(alien_word, &english_word[i]);
            }
            i++;
        }

        printf("%s -> %s\n", english_word, alien_word);

        free(alien_word);
        current_word++;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    Word words[MAX_WORDS];
    read_file(argv[1], words);

    translate_words(words);

    return 0;
}