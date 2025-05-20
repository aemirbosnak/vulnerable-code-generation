//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char ch;
    bool in_word = false;
    WordCount words[MAX_WORDS] = {0};

    int num_words = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            in_word = false;
        } else if (!in_word) {
            in_word = true;
            strncpy(words[num_words].word, &ch, 1);
            words[num_words].count = 1;
            num_words++;
        } else {
            strncat(words[num_words - 1].word, &ch, 1);
            words[num_words - 1].count++;
        }
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(file, filename);

    fclose(file);

    return 0;
}