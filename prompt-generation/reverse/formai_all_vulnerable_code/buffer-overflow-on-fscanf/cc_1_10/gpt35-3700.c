//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 10000

int main() {

    char *word_list[MAX_WORDS];
    int freq_list[MAX_WORDS];
    int word_count = 0;
    char buffer[MAX_WORD_LEN];
    int i, j;

    FILE *fp = fopen("pride_and_prejudice.txt", "r");
    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // count frequency of each word
    while(fscanf(fp, "%s", buffer) != EOF) {

        // clean up word
        for(i = 0; buffer[i]; i++){
            buffer[i] = tolower(buffer[i]);
        }

        for(j = 0; j < word_count; j++) {
            if(strcmp(word_list[j], buffer) == 0) {
                freq_list[j]++;
                break;
            }
        }

        if(j == word_count) {
            word_list[word_count] = strdup(buffer);
            freq_list[word_count] = 1;
            word_count++;
        }
    }

    // print word frequency list
    for(i = 0; i < word_count; i++) {
        printf("%s appears %d times.\n", word_list[i], freq_list[i]);
    }

    // cleanup
    for(i = 0; i < word_count; i++) {
        free(word_list[i]);
    }

    fclose(fp);
    return 0;
}