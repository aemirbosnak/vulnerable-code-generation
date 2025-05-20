//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Ken Thompson
/* C Data mining example program in a Ken Thompson style */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    struct word_count *word_counts = malloc(sizeof(struct word_count) * MAX_WORDS);
    int num_words = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        char *token = strtok(line, " \t\r\n");
        while (token!= NULL) {
            strcpy(word, token);
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: too many words\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, " \t\r\n");
        }
    }

    fclose(fp);

    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);

    return 0;
}
/* End of C Data mining example program in a Ken Thompson style */