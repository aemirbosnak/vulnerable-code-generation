//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct word_count {
    char word[MAX_WORD_LEN];
    int count;
} word_count;

word_count* count_words(const char* file_path, int* num_words) {
    FILE* fp = fopen(file_path, "r");

    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char word_buffer[MAX_WORD_LEN];
    int count = 0;
    word_count* word_count_array = (word_count*) malloc(sizeof(word_count) * count);

    while (fscanf(fp, "%s", word_buffer) != EOF) {
        // convert word to lowercase
        int i = 0;
        while (word_buffer[i]) {
            word_buffer[i] = tolower(word_buffer[i]);
            i++;
        }

        int word_found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(word_count_array[j].word, word_buffer) == 0) {
                word_count_array[j].count++;
                word_found = 1;
                break;
            }
        }

        if (!word_found) {
            count++;
            word_count_array = (word_count*) realloc(word_count_array, sizeof(word_count) * count);
            strcpy(word_count_array[count - 1].word, word_buffer);
            word_count_array[count - 1].count = 1;
        }
    }

    fclose(fp);
    *num_words = count;
    return word_count_array;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s [file_path]\n", argv[0]);
        exit(1);
    }

    int num_words;
    word_count* word_count_array = count_words(argv[1], &num_words);

    if (word_count_array == NULL) {
        exit(1);
    }

    printf("WORD\t\tFREQUENCY\n");
    printf("========================\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-15s\t%d\n", word_count_array[i].word, word_count_array[i].count);
    }

    free(word_count_array);
    return 0;
}