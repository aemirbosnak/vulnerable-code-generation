//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void add_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words!\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

void print_word_counts() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ungetc(ch, file);
            fscanf(file, "%s", word);
            add_word(word);
        }
    }

    fclose(file);
    print_word_counts();

    return 0;
}