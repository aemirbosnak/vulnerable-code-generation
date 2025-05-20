//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 10000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char **argv) {
    FILE *fp;
    char line[1024];
    char *token;
    WordCount *word_counts = (WordCount *) malloc(MAX_TOKENS * sizeof(WordCount));
    int num_tokens = 0;
    int i;

    // Open the input file
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    // Read the file and count the words
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: exceeded maximum number of tokens (%d)\n", MAX_TOKENS);
                exit(1);
            }
            if (strlen(token) > MAX_TOKEN_LEN) {
                printf("Error: token too long (%d characters)\n", strlen(token));
                exit(1);
            }
            for (i = 0; i < num_tokens; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_tokens) {
                word_counts[num_tokens].word = strdup(token);
                word_counts[num_tokens].count = 1;
                num_tokens++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    // Print the word counts
    printf("Word counts:\n");
    for (i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    // Free memory and close the file
    for (i = 0; i < num_tokens; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);
    fclose(fp);

    return 0;
}