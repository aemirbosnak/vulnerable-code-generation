//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100
#define MAX_NUM_TESTS 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generateRandomWord(char* word, int length) {
    for (int i = 0; i < length; i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[length] = '\0';
}

void loadWords(Word* words, int numWords) {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: unable to open words.txt\n");
        exit(1);
    }
    for (int i = 0; i < numWords; i++) {
        if (fscanf(file, "%s", words[i].word)!= 1) {
            printf("Error: invalid word in words.txt\n");
            exit(1);
        }
        words[i].length = strlen(words[i].word);
    }
    fclose(file);
}

int main() {
    int numTests;
    printf("How many tests do you want to take? ");
    scanf("%d", &numTests);
    if (numTests < 1 || numTests > MAX_NUM_TESTS) {
        printf("Invalid number of tests\n");
        return 1;
    }
    Word words[MAX_NUM_WORDS];
    loadWords(words, MAX_NUM_WORDS);
    for (int i = 0; i < numTests; i++) {
        int numWords = rand() % MAX_NUM_WORDS + 1;
        printf("Test %d:\n", i + 1);
        for (int j = 0; j < numWords; j++) {
            int wordIndex = rand() % MAX_NUM_WORDS;
            printf("%s ", words[wordIndex].word);
        }
        printf("\n");
        system("clear");
    }
    return 0;
}