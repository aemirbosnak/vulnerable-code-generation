//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 1000
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int isPalindrome;
} Word;

void readWords(Word* words, int numWords, FILE* file) {
    for (int i = 0; i < numWords; i++) {
        fscanf(file, "%s", words[i].word);
        words[i].length = strlen(words[i].word);
        words[i].isPalindrome = 0;
    }
}

int isPalindrome(char* word) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(word[i])!= tolower(word[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}

void markPalindromes(Word* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (isPalindrome(words[i].word)) {
            words[i].isPalindrome = 1;
        }
    }
}

void printResults(Word* words, int numWords) {
    printf("Palindromes:\n");
    for (int i = 0; i < numWords; i++) {
        if (words[i].isPalindrome) {
            printf("%s\n", words[i].word);
        }
    }
    printf("\nTotal palindromes found: %d\n", numWords);
}

int main() {
    Word words[MAX_NUM_WORDS];
    int numWords = 0;
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    while (fscanf(file, "%s", words[numWords].word)!= EOF) {
        numWords++;
        if (numWords >= MAX_NUM_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            return 1;
        }
    }
    fclose(file);

    readWords(words, numWords, file);
    markPalindromes(words, numWords);
    printResults(words, numWords);

    return 0;
}