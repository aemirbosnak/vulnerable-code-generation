//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LEN 100

// Node structure for linked list of words
typedef struct {
    char word[MAX_WORD_LEN];
    int count;
    struct node* next;
} Node;

// Linked list of words
Node* wordList = NULL;

// Function to add a new word to the linked list
void addWord(char* word) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = NULL;
    if (wordList == NULL) {
        wordList = newNode;
    }
    else {
        Node* currNode = wordList;
        while (currNode->next!= NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
}

// Function to print the word frequency list
void printWordList() {
    if (wordList == NULL) {
        printf("No words found.\n");
        return;
    }
    printf("Word Frequency:\n");
    printf("-----------------\n");
    for (Node* currNode = wordList; currNode!= NULL; currNode = currNode->next) {
        printf("%s: %d\n", currNode->word, currNode->count);
    }
}

// Function to read a file and count the frequency of each word
void countWords(FILE* file) {
    char word[MAX_WORD_LEN];
    char ch;
    int inWord = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (!inWord) {
                inWord = 1;
                strcpy(word, "");
                strcat(word, ch);
            }
            else {
                strcat(word, ch);
            }
        }
        else {
            inWord = 0;
            if (strlen(word) > 0) {
                addWord(word);
            }
            strcpy(word, "");
        }
    }
    if (inWord) {
        addWord(word);
    }
}

// Main function
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    countWords(file);
    fclose(file);
    printWordList();
    return 0;
}