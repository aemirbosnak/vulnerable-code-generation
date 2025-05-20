//Falcon-180B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word_count *word_counts, int num_words) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            word_counts[i].word[word_counts[i].count] = '\0';
            i++;
            if (i >= num_words) {
                break;
            }
        } else {
            strncat(word_counts[i].word, &ch, 1);
            word_counts[i].count++;
        }
    }

    if (i < num_words) {
        word_counts[i].word[word_counts[i].count] = '\0';
    }
}

void count_words(struct word_count *word_counts, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (num_words < MAX_WORDS && fscanf(file, "%s", word_counts[num_words].word)!= EOF) {
        num_words++;
    }

    if (num_words == 0) {
        printf("No words found in file.\n");
        return 1;
    }

    read_file(file, word_counts, num_words);
    count_words(word_counts, num_words);

    return 0;
}