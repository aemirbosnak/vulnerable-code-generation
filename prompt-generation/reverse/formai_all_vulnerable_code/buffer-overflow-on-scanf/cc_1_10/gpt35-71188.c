//FormAI DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024    /* maximum length of input string */
#define MAX_WORDS 100   /* maximum number of distinct words in input */
#define MAX_DEPTH 100   /* maximum recursion depth */

int count_words(char *input, char *words[], int counters[], int max_depth, int cur_depth) {
    char *delimiters = " \t\n\r,.;:-_!@#$%^&*()[]{}<>/\\|'\"`~+=";
    char *word;
    int i, j, found, duplicates;
    int total_words = 0;
    
    if (cur_depth > max_depth) {
        fprintf(stderr, "Maximum recursion depth reached. Aborting.\n");
        exit(1);
    }
    
    word = strtok(input, delimiters);
    while (word != NULL) {
        found = 0;
        duplicates = 0;
        for (i = 0; i < total_words; i++) {
            if (strcmp(word, words[i]) == 0) {
                counters[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[total_words] = strdup(word);
            counters[total_words] = 1;
            total_words++;
        }
        word = strtok(NULL, delimiters);
    }
    
    for (i = 0; i < total_words; i++) {
        printf("%s: %d\n", words[i], counters[i]);
    }
    
    return total_words;
}

int main() {
    char input[MAX_LEN];
    char *words[MAX_WORDS];
    int counters[MAX_WORDS];
    int depth;
    int total_words;
    
    printf("Enter a string to count words in:\n");
    fgets(input, MAX_LEN, stdin);
    
    printf("Enter recursion depth for word counter (default is 10):\n");
    scanf("%d", &depth);
    
    total_words = count_words(input, words, counters, depth, 0);
    
    printf("Total words: %d\n", total_words);
    
    return 0;
}