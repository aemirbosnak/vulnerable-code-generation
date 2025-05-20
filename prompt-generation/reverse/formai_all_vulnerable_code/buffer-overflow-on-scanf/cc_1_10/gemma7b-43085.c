//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
    char word[20];
    int frequency;
} Word;

Word words[MAX_WORDS];

void readWords(FILE *fp) {
    char word[20];
    int i = 0;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        return;
    }

    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(words[i].word, word);
        words[i].frequency = 0;
        i++;
    }

    fclose(fp);
}

void checkSpell(char *word) {
    int i = 0;

    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }

    return;
}

int main() {
    readWords(NULL);

    char word[20];
    printf("Enter a word: ");
    scanf("%s", word);

    checkSpell(word);

    printf("Word frequency: %d\n", words[0].frequency);

    return 0;
}