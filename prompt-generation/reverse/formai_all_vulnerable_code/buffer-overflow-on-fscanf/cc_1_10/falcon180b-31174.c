//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORD_COUNT 1000

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *fp, struct word_count *word_counts, int num_words) {
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *p = line;
        while ((p = strtok(p, " \t\n\r\f\v\""))!= NULL) {
            if (i >= num_words) {
                break;
            }
            strcpy(word, p);
            for (int j = 0; j < strlen(word); j++) {
                if (!isalpha(word[j])) {
                    word[j] = '\0';
                }
            }
            if (strlen(word) > 0) {
                for (int k = 0; k < num_words; k++) {
                    if (strcmp(word_counts[k].word, word) == 0) {
                        word_counts[k].count++;
                        break;
                    }
                }
            }
            i++;
        }
    }
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    struct word_count word_counts[MAX_WORD_COUNT];
    int num_words = 0;
    while (num_words < MAX_WORD_COUNT && fscanf(fp, "%s", word_counts[num_words].word)!= EOF) {
        num_words++;
    }
    read_file(fp, word_counts, num_words);
    fclose(fp);
    print_word_counts(word_counts, num_words);
    return 0;
}