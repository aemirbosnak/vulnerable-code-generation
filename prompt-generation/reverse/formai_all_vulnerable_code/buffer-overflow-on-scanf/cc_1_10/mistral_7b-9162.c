//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TABLE_SIZE 10000

typedef struct {
    char word[50];
    int count;
} Word;

Word hash_table[TABLE_SIZE];

int hash(const char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % TABLE_SIZE;
    }
    return hash;
}

void add_word(const char *word) {
    int index = hash(word);
    bool found = false;
    for (int i = 0; i < TABLE_SIZE && !found; i++) {
        if (strcmp(hash_table[i].word, word) == 0) {
            found = true;
            hash_table[i].count++;
        }
    }
    if (!found) {
        strcpy(hash_table[index].word, word);
        hash_table[index].count = 1;
    }
}

int main() {
    FILE *file;
    char filename[50];
    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[1000], word[50];
    bool first_line = true;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (first_line) {
            first_line = false;
            continue; // Skip the first line (header)
        }
        char *token = strtok(line, " ");
        while (token != NULL) {
            for (int i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }
            add_word(token);
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("\nWord frequencies:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i].count > 0) {
            printf("%s: %d\n", hash_table[i].word, hash_table[i].count);
        }
    }

    return 0;
}