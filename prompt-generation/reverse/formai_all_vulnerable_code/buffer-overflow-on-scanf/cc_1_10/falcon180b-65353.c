//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void createIndex(char *filename, WordCount *index) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    char line[1000];
    int count = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *p = strtok(line, ",.?!;:");
        while (p!= NULL) {
            if (count >= MAX_NUM_WORDS) {
                printf("Error: too many words in file %s\n", filename);
                exit(1);
            }
            strcpy(index[count].word, p);
            index[count].count = 0;
            count++;
            p = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
}

void searchIndex(char *filename, WordCount *index) {
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to search for: ");
    scanf("%s", word);
    int i = 0;
    while (index[i].word[0]!= '\0') {
        if (strcmp(index[i].word, word) == 0) {
            printf("Found word '%s' in file %s\n", word, filename);
            printf("Number of occurrences: %d\n", index[i].count);
            return;
        }
        i++;
    }
    printf("Word '%s' not found in file %s\n", word, filename);
}

int main() {
    char filename[100];
    printf("Enter the name of the file to index: ");
    scanf("%s", filename);
    WordCount index[MAX_NUM_WORDS];
    createIndex(filename, index);
    int choice;
    do {
        printf("\n1. Search for a word\n0. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            searchIndex(filename, index);
        }
    } while (choice!= 0);
    return 0;
}