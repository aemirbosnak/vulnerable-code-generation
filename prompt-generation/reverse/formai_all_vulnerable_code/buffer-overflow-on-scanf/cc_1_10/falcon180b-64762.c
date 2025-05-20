//Falcon-180B DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generateRandomWord(char* word, int length) {
    const char alphanum[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        word[i] = alphanum[rand() % strlen(alphanum)];
    }
    word[length] = '\0';
}

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    int numWords = 0;

    printf("Enter number of words to generate: ");
    scanf("%d", &numWords);

    for (int i = 0; i < numWords; i++) {
        char word[MAX_WORD_LENGTH];
        int length;

        do {
            printf("Enter word length (1-20): ");
            scanf("%d", &length);
        } while (length < 1 || length > MAX_WORD_LENGTH);

        generateRandomWord(word, length);
        strcpy(words[i].word, word);
        words[i].length = length;
    }

    printf("\nGenerated words:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    return 0;
}