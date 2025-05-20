//FormAI DATASET v1.0 Category: Word Count Tool ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct WordNode {
    char word[MAX_WORD_LENGTH+1];
    int count;
    struct WordNode* next;
} WordNode;

WordNode* createWordNode(char* word) {
    WordNode* node = (WordNode*)malloc(sizeof(WordNode));
    strncpy(node->word, word, MAX_WORD_LENGTH);
    node->count = 1;
    node->next = NULL;
    return node;
}


void appendWordNode(WordNode** head, char* word) {
    WordNode* node = createWordNode(word);
    if (*head == NULL) {
        *head = node;
        return;
    }
    WordNode* curr = *head;
    while (curr->next != NULL && strcmp(word, curr->word) != 0) {
        curr = curr->next;
    }
    if (strcmp(word, curr->word) == 0) {
        curr->count++;
        free(node);
        return;
    }
    curr->next = node;
}

int getWordCount(FILE* fp) {
    int count = 0;
    char buffer[MAX_WORD_LENGTH+1];
    WordNode* wordList = NULL;

    while(fscanf(fp, "%s", buffer) != EOF) {
        int len = strlen(buffer);
        int i;
        for (i = 0; i < len; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        buffer[len] = '\0';
        appendWordNode(&wordList, buffer);
        count++;
    }

    // print words frequency
    WordNode* curr = wordList;
    while (curr != NULL) {
        printf("%s : %d\n", curr->word, curr->count);
        curr = curr->next;
    }

    // free allocated memory
    curr = wordList;
    while (curr != NULL) {
        WordNode* temp = curr;
        curr = curr->next;
        free(temp);
    }
    return count;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file '%s'\n", filename);
        return 1;
    }

    int wordCount = getWordCount(fp);

    printf("Word count: %d\n", wordCount);
    fclose(fp);
    return 0;
}