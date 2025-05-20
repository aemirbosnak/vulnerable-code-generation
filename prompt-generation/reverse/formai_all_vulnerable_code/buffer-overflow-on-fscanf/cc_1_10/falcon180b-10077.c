//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int isPalindrome(char* word);
void readWordsFromFile(char* filename, char** words, int* numWords);

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter the name of the file containing words to check for palindromes: ");
    scanf("%s", filename);

    char** words = malloc(100 * sizeof(char*));
    int numWords = 0;

    readWordsFromFile(filename, words, &numWords);

    for (int i = 0; i < numWords; i++) {
        if (isPalindrome(words[i])) {
            printf("%s is a palindrome\n", words[i]);
        } else {
            printf("%s is not a palindrome\n", words[i]);
        }
    }

    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
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

void readWordsFromFile(char* filename, char** words, int* numWords) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        words[*numWords] = malloc(strlen(word) + 1);
        strcpy(words[*numWords], word);
        (*numWords)++;
    }

    fclose(file);
}