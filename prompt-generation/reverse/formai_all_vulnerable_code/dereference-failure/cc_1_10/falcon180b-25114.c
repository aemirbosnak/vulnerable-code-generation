//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word_index {
    char word[MAX_WORD_LEN];
    int index;
};

struct document {
    char *text;
    int num_words;
    struct word_index *word_index;
};

int compare_word_index(const void *a, const void *b) {
    struct word_index *w1 = (struct word_index *)a;
    struct word_index *w2 = (struct word_index *)b;
    return strcmp(w1->word, w2->word);
}

int hash(const char *word) {
    int sum = 0;
    while (*word) {
        sum += tolower(*word);
        word++;
    }
    return sum % MAX_WORDS;
}

int main() {
    int i, j, k;
    char text[100000];
    struct document *doc;
    struct word_index *word_index;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    doc = (struct document *)malloc(sizeof(struct document));
    doc->text = strdup(text);
    doc->num_words = 0;
    doc->word_index = (struct word_index *)malloc(MAX_WORDS * sizeof(struct word_index));

    char *token = strtok(doc->text, " \t\n\r\f\v,.!?;:\"'");
    while (token!= NULL) {
        int index = hash(token);
        for (k = 0; k < doc->num_words; k++) {
            if (doc->word_index[k].index == index) {
                doc->word_index[k].index++;
                break;
            }
        }
        if (k == doc->num_words) {
            doc->num_words++;
            doc->word_index[k].index = 1;
            strcpy(doc->word_index[k].word, token);
        }
        token = strtok(NULL, " \t\n\r\f\v,.!?;:\"'");
    }

    qsort(doc->word_index, doc->num_words, sizeof(struct word_index), compare_word_index);

    printf("Enter the query: ");
    fgets(text, sizeof(text), stdin);

    char *query_token = strtok(text, " \t\n\r\f\v,.!?;:\"'");
    while (query_token!= NULL) {
        int index = hash(query_token);
        for (k = 0; k < doc->num_words; k++) {
            if (doc->word_index[k].index == index) {
                printf("%s ", doc->word_index[k].word);
                break;
            }
        }
        if (k == doc->num_words) {
            printf("Not found\n");
        }
        query_token = strtok(NULL, " \t\n\r\f\v,.!?;:\"'");
    }

    free(doc->text);
    free(doc->word_index);
    free(doc);

    return 0;
}