//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_NUM_WORDS 1000

struct word_index {
    char word[MAX_WORD_LEN];
    int count;
    int index;
};

void create_index(char* filename, struct word_index* index) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    int count = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        int i = 0;
        while (isalpha(word[i])) {
            word[i] = tolower(word[i]);
            i++;
        }

        int j;
        for (j = 0; j < count; j++) {
            if (strcmp(word, index[j].word) == 0) {
                index[j].count++;
                break;
            }
        }

        if (j == count) {
            strcpy(index[count].word, word);
            index[count].count = 1;
            index[count].index = count;
            count++;
        }
    }

    fclose(file);
}

void search_index(struct word_index* index, char* query) {
    int i;
    for (i = 0; i < index[0].index; i++) {
        if (strcmp(query, index[i].word) == 0) {
            printf("Word found at index %d with count %d\n", index[i].index, index[i].count);
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    struct word_index index[MAX_NUM_WORDS];

    create_index(filename, index);
    char query[MAX_WORD_LEN];
    printf("Enter a word to search for: ");
    scanf("%s", query);
    search_index(index, query);

    return 0;
}