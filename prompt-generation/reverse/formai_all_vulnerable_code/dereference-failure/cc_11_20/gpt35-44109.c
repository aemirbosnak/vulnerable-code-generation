//FormAI DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 10000

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s FILENAME\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    char *line = malloc(MAX_LINE_LEN * sizeof(char));
    char *word = malloc(MAX_WORD_LEN * sizeof(char));
    int total_word_count = 0;
    int unique_word_count = 0;
    int *word_counts = calloc(1, sizeof(int)); // initialize all counts to 0
    while(fgets(line, MAX_LINE_LEN, fp)) {
        int len = strlen(line);
        if(line[len - 1] == '\n') {
            line[len - 1] = '\0'; // remove newline character from end of line
        }
        char *token = strtok(line, " \n\t");
        while(token != NULL) {
            total_word_count++;
            int found = 0;
            for(int i = 0; i < unique_word_count; i++) {
                if(strcmp(token, word + i * MAX_WORD_LEN) == 0) { // check if word is already in array
                    found = 1;
                    word_counts[i]++;
                    break;
                }
            }
            if(!found) { // add new word to array
                if(unique_word_count % 100 == 0) {
                    int new_size = (unique_word_count + 100) * MAX_WORD_LEN * sizeof(char);
                    word = realloc(word, new_size);
                    word_counts = realloc(word_counts, (unique_word_count + 100) * sizeof(int));
                }
                strcpy(word + unique_word_count * MAX_WORD_LEN, token);
                word_counts[unique_word_count] = 1;
                unique_word_count++;
            }
            token = strtok(NULL, " \n\t");
        }
    }
    fclose(fp);
    printf("Total words: %d\n", total_word_count);
    printf("Unique words: %d\n", unique_word_count);
    printf("Word counts:\n");
    for(int i = 0; i < unique_word_count; i++) {
        printf("%s: %d\n", word + i * MAX_WORD_LEN, word_counts[i]);
    }
    free(line);
    free(word);
    free(word_counts);
    return 0;
}