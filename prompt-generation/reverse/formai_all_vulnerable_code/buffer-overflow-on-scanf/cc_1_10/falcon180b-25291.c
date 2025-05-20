//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char words[MAX_WORDS][MAX_WORD_LENGTH];
int numWords = 0;

void readWords() {
    char word[MAX_WORD_LENGTH];
    printf("Enter words (type 'done' when finished):\n");
    while (fgets(word, MAX_WORD_LENGTH, stdin)!= NULL) {
        if (strcmp(word, "done") == 0) {
            break;
        }
        strcpy(words[numWords], word);
        numWords++;
    }
    printf("You entered %d words.\n", numWords);
}

void printWords() {
    for (int i = 0; i < numWords; i++) {
        printf("%s\n", words[i]);
    }
}

void printWordsInReverseOrder() {
    for (int i = numWords - 1; i >= 0; i--) {
        printf("%s\n", words[i]);
    }
}

void deleteWords(int index) {
    if (index >= 0 && index < numWords) {
        for (int i = index; i < numWords - 1; i++) {
            strcpy(words[i], words[i + 1]);
        }
        numWords--;
    } else {
        printf("Invalid index.\n");
    }
}

void replaceWord(int index, char* newWord) {
    if (index >= 0 && index < numWords) {
        strcpy(words[index], newWord);
    } else {
        printf("Invalid index.\n");
    }
}

void findWords(char* searchWord) {
    printf("Searching for '%s'...\n", searchWord);
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i], searchWord) == 0) {
            printf("Found '%s' at index %d.\n", searchWord, i);
        }
    }
}

int main() {
    readWords();
    printWords();
    printWordsInReverseOrder();
    printf("Enter index of word to delete: ");
    int index;
    scanf("%d", &index);
    deleteWords(index);
    printWords();
    printf("Enter index of word to replace: ");
    scanf("%d", &index);
    printf("Enter new word: ");
    char newWord[MAX_WORD_LENGTH];
    fgets(newWord, MAX_WORD_LENGTH, stdin);
    replaceWord(index, newWord);
    printWords();
    printf("Enter word to search for: ");
    char searchWord[MAX_WORD_LENGTH];
    fgets(searchWord, MAX_WORD_LENGTH, stdin);
    findWords(searchWord);
    return 0;
}