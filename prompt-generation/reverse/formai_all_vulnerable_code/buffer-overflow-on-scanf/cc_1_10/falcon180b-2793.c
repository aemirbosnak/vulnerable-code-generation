//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *fp, struct word_count words[MAX_WORDS]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(fp))!= EOF && isalnum(ch)) {
                if (j < MAX_WORD_LENGTH - 1) {
                    words[i].word[j] = tolower(ch);
                    j++;
                }
            }
            words[i].word[j] = '\0';
            words[i].count = 1;
            i++;
        }
    }
}

void write_file(FILE *fp, struct word_count words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            fprintf(fp, "%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct word_count words[MAX_WORDS];
    read_file(fp, words);

    fclose(fp);

    fp = fopen("word_count.txt", "w");
    if (fp == NULL) {
        printf("Error creating output file.\n");
        return 1;
    }

    write_file(fp, words);

    fclose(fp);

    printf("Word count saved to word_count.txt.\n");

    return 0;
}