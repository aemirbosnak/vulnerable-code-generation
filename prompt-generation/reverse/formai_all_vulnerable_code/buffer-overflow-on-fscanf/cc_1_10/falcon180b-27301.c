//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordIndex;

void read_file(FILE *fp, WordIndex *index) {
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        int j;
        for (j = 0; j < index->count; j++) {
            if (strcmp(index[j].word, word) == 0) {
                index[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (index->count >= MAX_NUM_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            strcpy(index[index->count].word, word);
            index[index->count].count = 1;
            index->count++;
        }
    }
}

void write_index(FILE *fp, WordIndex *index) {
    int i;
    for (i = 0; i < index->count; i++) {
        fprintf(fp, "%s %d\n", index[i].word, index[i].count);
    }
}

int main() {
    WordIndex index;
    index.count = 0;
    FILE *fp;
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    read_file(fp, &index);
    fclose(fp);
    fp = fopen("index.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create index file.\n");
        exit(1);
    }
    write_index(fp, &index);
    fclose(fp);
    return 0;
}