//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *wc1 = a;
    const struct word_count *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *word;
    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;

    if ((fp = fopen("logfile.txt", "r")) == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached\n");
                break;
            }
            if (strlen(word) >= MAX_WORD_LENGTH) {
                printf("Word too long: %s\n", word);
                continue;
            }
            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count++;
            num_words++;
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);
    print_word_counts(word_counts, num_words);

    return 0;
}