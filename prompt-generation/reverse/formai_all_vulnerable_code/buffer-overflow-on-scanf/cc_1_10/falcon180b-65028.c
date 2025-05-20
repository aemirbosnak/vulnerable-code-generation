//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int num_words) {
    char ch;
    int i;

    for (i = 0; i < num_words; i++) {
        word_counts[i].count = 0;
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            int j;
            for (j = 0; j < num_words; j++) {
                if (tolower(ch) == tolower(word_counts[j].word[0])) {
                    word_counts[j].count++;
                    break;
                }
            }
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    int num_words;
    WordCount word_counts[100];

    printf("Enter the name of the file to be read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter the number of words to be counted: ");
    scanf("%d", &num_words);

    read_file(file, word_counts, num_words);

    fclose(file);

    print_word_counts(word_counts, num_words);

    return 0;
}