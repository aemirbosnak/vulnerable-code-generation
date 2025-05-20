//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

void loadWords(WordTranslation words[]);
void saveWords(WordTranslation words[]);
void translate(char *text, WordTranslation words[]);

int main() {
    WordTranslation words[MAX_WORDS];
    loadWords(words);

    char text[1000];
    printf("Enter some text to translate:\n");
    fgets(text, sizeof(text), stdin);

    translate(text, words);

    printf("\nTranslated text:\n%s\n", text);

    saveWords(words);

    return 0;
}

void loadWords(WordTranslation words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].word, words[count].translation) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words in file\n");
            exit(1);
        }
    }

    fclose(file);
}

void saveWords(WordTranslation words[]) {
    FILE *file = fopen("words.txt", "w");
    if (file == NULL) {
        printf("Error saving words file\n");
        exit(1);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            fprintf(file, "%s %s\n", words[i].word, words[i].translation);
        }
    }

    fclose(file);
}

void translate(char *text, WordTranslation words[]) {
    int index = 0;
    while (*text!= '\0') {
        int wordLen = strlen(text);
        if (wordLen > MAX_WORD_LENGTH) {
            wordLen = MAX_WORD_LENGTH;
        }

        strncpy(words[index].word, text, wordLen);
        words[index].word[wordLen] = '\0';

        char *translation = strstr(text, words[index].word);
        if (translation!= NULL) {
            strcpy(words[index].translation, "*");
        } else {
            strcpy(words[index].translation, "");
        }

        text += wordLen;
        index++;
    }
}