//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: curious
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

void read_file(FILE *f, struct word words[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(f))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = toupper(ch);
            words[i].word[1] = '\0';
            words[i].count = 1;
            i++;
        }
    }
}

void count_words(struct word words[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }
}

void print_words(struct word words[], int n) {
    for (int i = 0; i < n; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *f;
    char filename[MAX_WORD_LEN];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    struct word words[MAX_WORDS];
    int n = 0;
    read_file(f, words);
    count_words(words, n);
    print_words(words, n);
    fclose(f);
    return 0;
}