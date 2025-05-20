//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_WORD_LEN 64
#define MAX_WORD_NUM 1000

char *line = NULL;
char *word = NULL;
char *word_list[MAX_WORD_NUM];
int word_count = 0;

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_special(char c) {
    return!is_alpha(c) &&!is_digit(c);
}

void add_word(char *str) {
    if (word_count >= MAX_WORD_NUM) {
        printf("Maximum number of words reached.\n");
        return;
    }
    word_list[word_count++] = str;
}

int main() {
    FILE *fp;
    char ch;
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    line = (char *) malloc(MAX_LINE * sizeof(char));
    word = (char *) malloc(MAX_WORD_LEN * sizeof(char));

    while ((ch = fgetc(fp))!= EOF) {
        if (is_alpha(ch)) {
            if (i == 0) {
                strcpy(word, "");
            }
            strncat(word, &ch, 1);
            i++;
        } else if (is_digit(ch)) {
            if (i == 0) {
                strcpy(word, "");
            }
            strncat(word, &ch, 1);
            i++;
        } else if (is_special(ch)) {
            if (i > 0) {
                add_word(word);
                i = 0;
            }
        }
    }

    if (i > 0) {
        add_word(word);
    }

    fclose(fp);

    printf("Total number of words: %d\n", word_count);

    for (i = 0; i < word_count; i++) {
        printf("%s\n", word_list[i]);
    }

    exit(0);
}