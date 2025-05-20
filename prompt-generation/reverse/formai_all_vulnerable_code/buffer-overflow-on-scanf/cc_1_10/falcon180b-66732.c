//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int index;
} Word;

void readWords(Word words[], int numWords) {
    char word[MAX_WORD_LEN];
    int i = 0;

    printf("Enter words and/or phrases (up to %d):\n", numWords);

    while (i < numWords && fgets(word, MAX_WORD_LEN, stdin)) {
        word[strcspn(word, "\n")] = '\0';
        strcpy(words[i].word, word);
        i++;
    }

    if (i < numWords) {
        printf("Not enough words entered.\n");
        exit(1);
    }
}

int compareWords(const void *a, const void *b) {
    const Word *w1 = a;
    const Word *w2 = b;

    return strcmp(w1->word, w2->word);
}

void printWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s\n", words[i].word);
    }
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    int numWords;
    printf("Enter the number of words/phrases: ");
    scanf("%d", &numWords);

    Word words[MAX_WORDS];
    readWords(words, numWords);

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("Words sorted alphabetically:\n");
    printWords(words, numWords);

    return 0;
}