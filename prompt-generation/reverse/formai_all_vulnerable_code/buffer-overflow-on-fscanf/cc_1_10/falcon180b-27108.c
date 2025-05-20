//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DOCUMENTS 1000
#define MAX_INDEX_ENTRIES 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    char document[MAX_DOCUMENTS][MAX_WORD_LENGTH];
    int num_words;
} Document;

typedef struct {
    char word[MAX_WORD_LENGTH];
    int document_id;
} IndexEntry;

int main() {
    FILE *fp;
    char filename[MAX_DOCUMENTS][MAX_WORD_LENGTH];
    int num_documents = 0;
    int i;

    fp = fopen("documents.txt", "r");
    if(fp == NULL) {
        printf("Error: could not open documents.txt\n");
        exit(1);
    }

    while(fscanf(fp, "%s", filename[num_documents])!= EOF) {
        num_documents++;
    }

    fclose(fp);

    fp = fopen("index.txt", "w");
    if(fp == NULL) {
        printf("Error: could not open index.txt\n");
        exit(1);
    }

    for(i = 0; i < num_documents; i++) {
        fp = fopen(filename[i], "r");
        if(fp == NULL) {
            printf("Error: could not open %s\n", filename[i]);
            exit(1);
        }

        char word[MAX_WORD_LENGTH];
        int num_words = 0;

        while(fscanf(fp, "%s", word)!= EOF) {
            num_words++;

            if(num_words > MAX_DOCUMENTS) {
                printf("Error: document %s has too many words\n", filename[i]);
                exit(1);
            }

            fprintf(fp, "%s %d\n", word, i);
        }

        fclose(fp);
    }

    fclose(fp);

    return 0;
}