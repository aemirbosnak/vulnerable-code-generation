//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 30

struct word {
    char word[MAX_WORD_LENGTH+1];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void loadWords(char *filename, struct word *words) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LENGTH+1];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Error: word '%s' is too long\n", word);
            exit(1);
        }
        strcpy(words->word, word);
        words->frequency = 0;
        words++;
    }
    fclose(file);
}

int checkSpelling(char *word, struct word *words) {
    int i = 0;
    while (i < strlen(word)) {
        if (!isalpha(word[i])) {
            word[i] = tolower(word[i]);
        }
        i++;
    }
    qsort(words, MAX_WORDS, sizeof(struct word), compareWords);
    struct word *foundWord = bsearch(word, words, MAX_WORDS, sizeof(struct word), compareWords);
    if (foundWord) {
        foundWord->frequency++;
        return 0;
    } else {
        printf("Possible spelling mistake: %s\n", word);
        return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    struct word words[MAX_WORDS];
    loadWords(filename, words);
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        char *word = strtok(buffer, ",.?!;:");
        while (word) {
            checkSpelling(word, words);
            word = strtok(NULL, ",.?!;:");
        }
    }
    return 0;
}