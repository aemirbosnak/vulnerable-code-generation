//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define WORD_LEN 20

typedef struct {
    char word[WORD_LEN];
    char translation[WORD_LEN];
} Word;

void load_words(Word words[]);
void save_words(Word words[]);
void translate_text(char* text, Word words[]);

int main() {
    Word words[MAX_WORDS];
    load_words(words);

    char text[1000];
    printf("Enter the text to translate:\n");
    scanf("%s", text);

    translate_text(text, words);

    return 0;
}

void load_words(Word words[]) {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].word, words[count].translation) == 2 && count < MAX_WORDS) {
        count++;
    }

    fclose(file);
}

void save_words(Word words[]) {
    FILE* file = fopen("words.txt", "w");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            fprintf(file, "%s %s\n", words[i].word, words[i].translation);
        }
    }

    fclose(file);
}

void translate_text(char* text, Word words[]) {
    char* word = strtok(text, " ");
    while (word!= NULL) {
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                printf("%s ", words[i].translation);
                break;
            }
        }

        word = strtok(NULL, " ");
    }
}