//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char word[50];
    int count;
} Word;

void countWords(char *input, int depth, Word *words, int capacity) {
    if (depth >= 50) { // base case: reached end of current word
        if (words[depth - 1].count > 0 && strcmp(input, words[depth - 1].word) == 0) {
            words[depth - 1].count++;
            return;
        }
        Word newWord = {""};
        strncpy(newWord.word, input, sizeof(newWord.word));
        newWord.count = 1;
        if (capacity <= depth + 1) { // resize array if needed
            Word *newWords = (Word *)realloc(words, sizeof(Word) * (depth * 2 + 1));
            if (!newWords) {
                printf("Out of memory!\n");
                exit(EXIT_FAILURE);
            }
            words = newWords;
        }
        words[depth] = newWord;
        countWords(input + strlen(input) + 1, depth + 1, words, depth * 2 + 1);
        return;
    }

    if (isalpha(input[depth])) { // current character is a letter
        words[depth].word[depth] = tolower(input[depth]);
    } else if (words[depth].count > 0) { // reached end of current letter, word found
        countWords(input + depth + 1, depth + 1, words, capacity);
    } else { // current character is not a letter, not at the end of a word
        countWords(input + depth + 1, depth + 1, words, capacity);
    }
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0'; // remove newline character
    Word *words = (Word *)calloc(1, sizeof(Word));
    if (!words) {
        printf("Out of memory!\n");
        return EXIT_FAILURE;
    }
    countWords(input, 0, words, 1);

    printf("Word frequencies:\n");
    for (int i = 0; i < 50 && words[i].count > 0; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(words);
    return EXIT_SUCCESS;
}