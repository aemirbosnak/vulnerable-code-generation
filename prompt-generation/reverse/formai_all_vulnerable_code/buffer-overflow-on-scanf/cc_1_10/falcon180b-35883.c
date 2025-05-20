//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 256

typedef struct {
    char *word;
    int count;
} WordCount;

void init_word_count(WordCount *word_count, char *word) {
    word_count->word = word;
    word_count->count = 0;
}

void count_word(WordCount *word_count, char *line) {
    char *pos = strstr(line, word_count->word);
    while (pos!= NULL) {
        word_count->count++;
        pos = strstr(pos + 1, word_count->word);
    }
}

void print_word_count(WordCount *word_count) {
    printf("%s: %d\n", word_count->word, word_count->count);
}

bool read_line(FILE *fp, char *line) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (i >= MAX_LINE_SIZE - 1) {
            printf("Error: Line too long\n");
            return false;
        }
        if (ch == '\n') {
            line[i] = '\0';
            break;
        }
        line[i++] = ch;
    }
    return true;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    WordCount word_count;

    printf("Enter the word to count: ");
    scanf("%s", word);

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input file\n");
        return 1;
    }

    while (read_line(fp, line)) {
        init_word_count(&word_count, word);
        count_word(&word_count, line);
        print_word_count(&word_count);
    }

    fclose(fp);
    return 0;
}