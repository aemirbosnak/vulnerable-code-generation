//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} word_t;

typedef struct {
    word_t words[MAX_WORDS];
    int num_words;
} spam_t;

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int is_spam(spam_t *spam, char *text) {
    char *word;
    char *token;
    word_t *curr_word;
    int i;
    int num_spam_words = 0;

    token = strtok(text, " ");
    while (token!= NULL) {
        word = strtok(token, ",");
        while (word!= NULL) {
            curr_word = bsearch(word, spam->words, spam->num_words, sizeof(word_t), compare_words);
            if (curr_word!= NULL) {
                curr_word->count++;
                num_spam_words++;
            }
            word = strtok(NULL, ",");
        }
        token = strtok(NULL, " ");
    }

    if (num_spam_words >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    spam_t spam;
    char filename[50];
    FILE *fp;
    char line[100];
    int i;

    printf("Enter the name of the spam words file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    spam.num_words = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        if (line[0]!= '#') {
            word_t word;
            strcpy(word.word, line);
            word.count = 0;
            spam.words[spam.num_words++] = word;
        }
    }

    fclose(fp);

    while (1) {
        printf("Enter a text to check for spam: ");
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        if (is_spam(&spam, line)) {
            printf("The text contains spam words.\n");
        } else {
            printf("The text does not contain spam words.\n");
        }
    }

    return 0;
}