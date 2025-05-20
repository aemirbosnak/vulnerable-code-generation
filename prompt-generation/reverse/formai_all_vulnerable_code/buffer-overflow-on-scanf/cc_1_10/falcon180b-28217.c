//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 50

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *fp;
    char filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    WordCount word_counts[100];
    int num_words = 0;
    int i;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *p = strtok(line, ",.?!;:");
        while (p!= NULL) {
            strcpy(word, p);
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                num_words++;
                strcpy(word_counts[i].word, word);
                word_counts[i].count = 1;
            }
            p = strtok(NULL, ",.?!;:");
        }
    }

    printf("Word Counts:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    fclose(fp);
    return 0;
}