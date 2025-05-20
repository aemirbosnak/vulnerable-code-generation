//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TABLE_SIZE 10000

typedef struct HashNode {
    char *word;
    int count;
    struct HashNode *next;
} HashNode;

unsigned long hash(char *str, int size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % size;
}

void insert_word(HashNode **table, char *word) {
    unsigned long index = hash(word, TABLE_SIZE);
    HashNode *node = malloc(sizeof(HashNode));

    node->word = strdup(word);
    node->count = 1;
    node->next = table[index];

    table[index] = node;
}

int main() {
    FILE *file;
    char filename[100], line[1024], *token, *save_ptr;
    HashNode *table[TABLE_SIZE] = {NULL};

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (getline(&line, sizeof(line), file) > 0) {
        token = strtok_r(line, " \t\n\r.,;:!?(){}[]", &save_ptr);
        while (token != NULL) {
            for (int i = 0; token[i]; i++)
                if (isalnum(token[i]))
                    token[i] = tolower(token[i]);

            insert_word(table, token);
            token = strtok_r(NULL, " \t\n\r.,;:!?(){}[]", &save_ptr);
        }
    }

    fclose(file);

    printf("\nWord frequencies:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i]) {
            printf("%s: %d\n", table[i]->word, table[i]->count);
            free(table[i]->word);
            free(table[i]);
        }
    }

    return 0;
}