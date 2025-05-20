//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void init_word_count_table(WordCount *table) {
    int i;
    for (i = 0; i < 26; i++) {
        table[i].count = 0;
    }
}

void update_word_count_table(WordCount *table, char c) {
    if (isalpha(c)) {
        table[(int) toupper(c) - 65].count++;
    }
}

void print_word_count_table(WordCount *table) {
    int i;
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", (char) (i + 65), table[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_LINE_LEN];
    char line[MAX_LINE_LEN];
    WordCount table[26];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    init_word_count_table(table);

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        int i;
        for (i = 0; i < strlen(line); i++) {
            update_word_count_table(table, line[i]);
        }
    }

    fclose(fp);

    printf("\nWord count:\n");
    print_word_count_table(table);

    return 0;
}