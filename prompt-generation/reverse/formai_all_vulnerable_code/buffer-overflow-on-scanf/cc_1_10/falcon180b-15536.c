//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_SIZE 20

struct Word {
    char word[MAX_WORD_SIZE];
    int count;
};

int main() {
    char filename[MAX_WORD_SIZE];
    char line[MAX_WORD_SIZE];
    char *word;
    struct Word words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_SIZE, fp)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            int i;
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
                if (num_words >= MAX_WORDS) {
                    printf("Error: maximum number of words reached.\n");
                    exit(1);
                }
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}