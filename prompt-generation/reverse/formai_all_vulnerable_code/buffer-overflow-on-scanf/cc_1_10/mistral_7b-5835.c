//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 100003

typedef struct HashNode {
    char word[20];
    int count;
    struct HashNode *next;
} HashNode;

HashNode* hash_table[TABLE_SIZE];

int hash_func(const char *str) {
    unsigned int h = 0;
    for (const char *p = str; *p != '\0'; p++)
        h = (h * 33 + *p) & (TABLE_SIZE - 1);
    return h;
}

void add_word(const char *word) {
    int h = hash_func(word);
    HashNode *new_node = (HashNode *)calloc(1, sizeof(HashNode));
    strcpy(new_node->word, word);
    new_node->count = 1;

    if (hash_table[h] == NULL)
        hash_table[h] = new_node;
    else {
        HashNode *current = hash_table[h];
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
}

void process_line(const char *line) {
    char *token = strtok(strdup(line), " ");
    while (token != NULL) {
        for (int i = 0; token[i] != '\0'; i++)
            token[i] = tolower(token[i]);
        add_word(token);
        token = strtok(NULL, " ");
    }
}

int main() {
    char filename[100];
    FILE *fp;

    printf("Enter the input file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        process_line(line);
    }

    fclose(fp);

    printf("\nWord Frequency Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            printf("\nIndex %d:\n", i);
            HashNode *current = hash_table[i];
            while (current != NULL) {
                printf("%s: %d\n", current->word, current->count);
                current = current->next;
            }
        }
    }

    return 0;
}