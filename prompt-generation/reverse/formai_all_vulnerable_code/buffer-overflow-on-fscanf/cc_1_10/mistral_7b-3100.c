//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct Node {
    char ch;
    struct Node *next[27];
    int isEnd;
} Node;

Node* newNode(char ch) {
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->ch = ch;
    return node;
}

unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void addWord(Node **root, const char *word) {
    Node *current = *root;

    for (int level = 0; word[level] != '\0'; level++) {
        int index = tolower(word[level]) - 'a';
        if (!current->next[index])
            current->next[index] = newNode(word[level]);

        current = current->next[index];
    }

    current->isEnd = 1;
}

int checkWord(Node **root, const char *word) {
    Node *current = *root;

    for (int level = 0; word[level] != '\0'; level++) {
        int index = tolower(word[level]) - 'a';

        if (!current->next[index])
            return 0;

        current = current->next[index];
    }

    return current->isEnd;
}

int main() {
    FILE *file;
    char filename[100];
    Node *root = NULL;

    printf("Enter the dictionary file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[50];

    while (fscanf(file, "%s", word) == 1) {
        addWord(&root, word);
    }

    fclose(file);

    printf("Enter a word to check: ");
    scanf("%s", word);

    int result = checkWord(&root, word);

    if (result)
        printf("The word '%s' is in the dictionary.\n", word);
    else
        printf("The word '%s' is not in the dictionary.\n", word);

    return 0;
}