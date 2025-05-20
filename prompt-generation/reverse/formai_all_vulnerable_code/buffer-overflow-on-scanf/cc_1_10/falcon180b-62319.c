//Falcon-180B DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

void read_file(FILE* fp, struct word words[]) {
    char line[MAX_WORD_LEN];
    while (fgets(line, sizeof(line), fp)) {
        int i = 0;
        char* word = strtok(line, " ");
        while (word!= NULL) {
            strcpy(words[i].word, word);
            words[i].count++;
            i++;
            if (i >= MAX_WORDS) {
                break;
            }
            word = strtok(NULL, " ");
        }
    }
}

void print_words(struct word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE* fp;
    char filename[MAX_WORD_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct word words[MAX_WORDS];
    read_file(fp, words);

    int num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            num_words++;
        }
    }

    printf("Total words: %d\n", num_words);
    print_words(words, num_words);

    fclose(fp);
    return 0;
}