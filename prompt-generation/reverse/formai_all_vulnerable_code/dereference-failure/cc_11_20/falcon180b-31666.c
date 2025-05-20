//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    char *word = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    WordCount words[MAX_NUM_WORDS];
    int num_words = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", argv[1]);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            // Start of a new word
            num_words++;
            if (num_words >= MAX_NUM_WORDS) {
                printf("Error: Too many words in file.\n");
                exit(1);
            }
            strcpy(word, "");
        } else if (isalnum(ch)) {
            // Part of a word
            strcat(word, &ch);
        } else if (isspace(ch)) {
            // End of a word
            word[strcspn(word, " ")] = '\0';
            if (strlen(word) == 0)
                continue;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }
        }
    }

    fclose(fp);

    printf("Total number of words: %d\n", num_words);

    for (i = 0; i < num_words; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }

    free(word);
    return 0;
}