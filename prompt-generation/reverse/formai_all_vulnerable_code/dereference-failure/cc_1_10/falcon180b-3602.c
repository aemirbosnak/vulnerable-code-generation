//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define SPAM_THRESHOLD 3

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int is_spam(struct word_count *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(struct word_count), compare_strings);
    int spam_count = 0;
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count >= SPAM_THRESHOLD) {
            spam_count++;
        }
    }
    return spam_count >= 3;
}

void process_email(char *email, struct word_count *word_counts, int *num_words) {
    char *token = strtok(email, " ");
    while (token!= NULL) {
        int word_length = strlen(token);
        if (word_length <= MAX_WORD_LENGTH) {
            struct word_count *word = bsearch(token, word_counts, *num_words, sizeof(struct word_count), compare_strings);
            if (word == NULL) {
                word = &word_counts[*num_words];
                (*num_words)++;
            }
            word->count++;
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    FILE *fp;
    char ch;
    char email[1000];
    int num_words = 0;
    struct word_count word_counts[MAX_WORDS];

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcat(email, ch);
        } else {
            process_email(email, word_counts, &num_words);
            memset(email, 0, sizeof(email));
        }
    }

    if (strlen(email) > 0) {
        process_email(email, word_counts, &num_words);
    }

    fclose(fp);

    if (is_spam(word_counts, num_words)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}