//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

struct Word {
    char* text;
    int count;
};

void increment_word_count(struct Word* word, int n) {
    word->count += n;
}

int compare_words(const void* p1, const void* p2) {
    const struct Word* w1 = p1;
    const struct Word* w2 = p2;
    return w2->count - w1->count; // sort by count in descending order
}

void print_word_count(struct Word* words, int n) {
    printf("%-15s %s\n", "Word", "Frequency");
    printf("---------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s %d\n", words[i].text, words[i].count);
    }
}

void free_words(struct Word* words, int n) {
    for (int i = 0; i < n; i++) {
        free(words[i].text);
    }
    free(words);
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    strtok(filename, "\n"); // remove newline
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    struct Word* words = malloc(sizeof(struct Word) * MAX_WORDS);
    int num_words = 0;
    char buf[100];
    while (fscanf(fp, "%s", buf) == 1 && num_words < MAX_WORDS) {
        // convert word to lowercase
        for (char* p = buf; *p; ++p) *p = tolower(*p);
        // check if word already exists in words array
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].text, buf) == 0) {
                increment_word_count(&words[i], 1);
                break;
            }
        }
        // add new word to words array
        if (i == num_words) {
            words[num_words].text = strdup(buf);
            words[num_words].count = 1;
            num_words++;
        }
    }
    qsort(words, num_words, sizeof(struct Word), compare_words);
    print_word_count(words, num_words);
    free_words(words, num_words);
    fclose(fp);
    return 0;
}