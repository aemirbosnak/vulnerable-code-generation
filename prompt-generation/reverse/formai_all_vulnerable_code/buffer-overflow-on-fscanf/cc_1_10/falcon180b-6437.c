//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *english;
    char *french;
} Word;

void loadWords(Word words[]);
char *translate(const char *sentence, Word words[]);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    Word words[MAX_WORDS];
    loadWords(words);

    char *translated = translate(argv[1], words);
    printf("%s\n", translated);

    free(translated);
    return 0;
}

void loadWords(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_WORDS && fscanf(file, "%s %s", words[count].english, words[count].french)!= EOF) {
        count++;
    }

    fclose(file);
}

char *translate(const char *sentence, Word words[]) {
    char *translated = malloc(strlen(sentence) + 1);
    strcpy(translated, sentence);

    char *token = strtok(translated, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                strcpy(token, words[i].french);
                break;
            }
        }
        if (i == MAX_WORDS) {
            // Word not found, leave as is
        }
        token = strtok(NULL, " ");
    }

    return translated;
}