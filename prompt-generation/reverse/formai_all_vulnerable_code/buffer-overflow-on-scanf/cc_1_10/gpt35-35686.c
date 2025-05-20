//FormAI DATASET v1.0 Category: Database Indexing System ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

typedef struct node {
    char *word;
    struct node *next;
} NODE;

int isKeyword(char *word);
int hash(char *word);
NODE **initHashTable();
NODE *createNode(char *word);
void addWord(char *word, NODE **table);
void printTable(NODE **table);
void freeTable(NODE **table);


int main() {
    char input[SIZE];
    NODE **hashTable = initHashTable();
    printf("Enter words to add to hashed database (enter 'q' to quit):\n");
    while (strcmp(input, "q")) {
        printf("> ");
        scanf("%s", input);
        if (isKeyword(input)) {
            continue;
        }
        addWord(input, hashTable);
    }
    printTable(hashTable);
    freeTable(hashTable);
    return 0;
}


int isKeyword(char *word) {
    char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
                        "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
                        "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
                        "void", "volatile", "while"};
    int i, len = sizeof(keywords)/sizeof(char*);
    for (i = 0; i < len; ++i) {
        if (!strcmp(word, keywords[i])) {
            return 1;
        }
    }
    return 0;
}


int hash(char *word) {
    int i, hashVal = 0, len = strlen(word);
    for (i = 0; i < len; ++i) {
        hashVal += tolower(word[i]) * (i + 1);
    }
    return hashVal % SIZE;
}


NODE **initHashTable() {
    NODE **table = calloc(SIZE, sizeof(NODE*));
    return table;
}


NODE *createNode(char *word) {
    NODE *newNode = malloc(sizeof(NODE));
    if (!newNode) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->word = malloc(strlen(word) + 1);
    if (!newNode->word) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}


void addWord(char *word, NODE **table) {
    if (!word) {
        return;
    }
    int index = hash(word);
    NODE *current = table[index];
    if (!current) {
        table[index] = createNode(word);
    } else {
        while (current->next) {
            current = current->next;
        }
        current->next = createNode(word);
    }
}


void printTable(NODE **table) {
    int i;
    NODE *current;
    for (i = 0; i < SIZE; ++i) {
        current = table[i];
        if (current) {
            printf("Index %d: ", i);
            while (current) {
                printf("%s -> ", current->word);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}


void freeTable(NODE **table) {
    int i;
    NODE *current, *temp;
    for (i = 0; i < SIZE; ++i) {
        current = table[i];
        while (current) {
            temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
    }
    free(table);
}