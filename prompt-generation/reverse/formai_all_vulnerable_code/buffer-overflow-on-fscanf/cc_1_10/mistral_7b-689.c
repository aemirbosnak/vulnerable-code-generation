//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_LENGTH 30
#define NUM_WORDS 100
#define LINE_LENGTH 120

typedef struct Word {
    char* word;
    struct Word* next;
} Word;

Word* createWordList(char* filePath) {
    FILE* fp;
    Word* first = NULL, * current = NULL;

    fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filePath);
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", current->word) != EOF) {
        if (current == NULL) {
            first = (Word*) malloc(sizeof(Word));
            current = first;
            current->next = NULL;
        } else {
            current->next = (Word*) malloc(sizeof(Word));
            current = current->next;
            current->next->word = (char*) malloc(strlen(current->word) + 1);
            strcpy(current->next->word, current->word);
            current->next->next = NULL;
        }
    }

    fclose(fp);

    return first;
}

void printWordList(Word* wordList) {
    Word* current = wordList;

    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }

    printf("\n");
}

void freeWordList(Word* wordList) {
    Word* current = wordList, * next;

    while (current != NULL) {
        next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

void testTypingSpeed(Word* wordList) {
    clock_t start, end;
    int correct_count = 0, error_count = 0;
    char input[WORD_LENGTH];

    start = clock();

    printf("Type the following words as fast as you can:\n");
    printWordList(wordList);

    while (wordList != NULL) {
        printf("%s: ", wordList->word);
        fgets(input, WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, wordList->word) == 0) {
            correct_count++;
        } else {
            error_count++;
        }

        wordList = wordList->next;
    }

    end = clock();

    printf("\nTotal correct words: %d\nTotal errors: %d\n", correct_count, error_count);
    printf("Time taken: %.2f seconds\n", (float) (end - start) / CLOCKS_PER_SEC);
}

int main(int argc, char** argv) {
    Word* wordList = NULL;

    if (argc < 2) {
        printf("Usage: %s <words file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    wordList = createWordList(argv[1]);
    testTypingSpeed(wordList);
    freeWordList(wordList);

    return EXIT_SUCCESS;
}