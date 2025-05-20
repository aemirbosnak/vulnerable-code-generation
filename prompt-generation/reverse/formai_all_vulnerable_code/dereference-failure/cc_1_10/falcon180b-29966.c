//Falcon-180B DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word_count *word_list;
int num_words;
int num_lines;

void initialize_word_list() {
    word_list = malloc(MAX_WORDS * sizeof(struct word_count));
    num_words = 0;
}

void add_word(char *str) {
    int len = strlen(str);
    if (len > MAX_WORD_LENGTH) {
        len = MAX_WORD_LENGTH;
    }
    strncpy(word_list[num_words].word, str, len);
    word_list[num_words].count = 1;
    num_words++;
}

void print_word_list() {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].count);
    }
}

int main() {
    initialize_word_list();
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    char *word;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        num_lines++;
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            word = strtok(token, ",.?!;:");
            while (word!= NULL) {
                if (isalpha(word[0])) {
                    add_word(word);
                }
                word = strtok(NULL, ",.?!;:");
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
    print_word_list();
    return 0;
}