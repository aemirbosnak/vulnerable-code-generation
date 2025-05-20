//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *word_counts;
    int num_words;
} TextAnalyzer;

void initialize_text_analyzer(TextAnalyzer *ta) {
    ta->word_counts = NULL;
    ta->num_words = 0;
}

void add_word(TextAnalyzer *ta, char *word) {
    int i;
    for (i = 0; i < ta->num_words; i++) {
        if (strcmp(word, ta->word_counts[i].word) == 0) {
            ta->word_counts[i].count++;
            return;
        }
    }
    ta->word_counts = realloc(ta->word_counts, sizeof(WordCount) * (ta->num_words + 1));
    ta->word_counts[ta->num_words].word = strdup(word);
    ta->word_counts[ta->num_words].count = 1;
    ta->num_words++;
}

void print_word_counts(TextAnalyzer *ta) {
    int i;
    for (i = 0; i < ta->num_words; i++) {
        printf("%s: %d\n", ta->word_counts[i].word, ta->word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    TextAnalyzer ta;
    initialize_text_analyzer(&ta);

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *word;
        char *token;
        int i;

        token = strtok(line, " ");
        while (token!= NULL) {
            word = strtok(token, " ");
            if (word!= NULL) {
                add_word(&ta, word);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);
    print_word_counts(&ta);

    return 0;
}