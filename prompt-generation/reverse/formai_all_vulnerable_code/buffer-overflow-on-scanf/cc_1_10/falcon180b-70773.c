//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

struct word word_table[MAX_WORDS];

void init_word_table() {
    for (int i = 0; i < MAX_WORDS; i++) {
        word_table[i].count = 0;
    }
}

void print_word_table() {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_table[i].count > 0) {
            printf("%s: %d\n", word_table[i].word, word_table[i].count);
        }
    }
}

void count_words(char* sentence) {
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        int len = strlen(word);
        if (len <= MAX_WORD_LEN) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word_table[i].word, word) == 0) {
                    word_table[i].count++;
                    break;
                }
            }
            if (i == MAX_WORDS) {
                strncpy(word_table[0].word, word, MAX_WORD_LEN);
                word_table[0].count++;
            }
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    char input_file[50];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    FILE* fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    init_word_table();

    char sentence[100];
    while (fgets(sentence, sizeof(sentence), fp)!= NULL) {
        count_words(sentence);
    }

    fclose(fp);

    print_word_table();

    return 0;
}