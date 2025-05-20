//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[1000];
    char *word;
    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;
    int i;

    printf("Enter filename: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, 1000, file)!= NULL) {
        word = strtok(line, ",.?!;:\"'");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Too many words in file.\n");
                fclose(file);
                return 1;
            }
            strcpy(word_counts[num_words].word, word);
            num_words++;
            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(file);

    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}