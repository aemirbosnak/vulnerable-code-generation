//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_words(struct word_count *word_counts, int count, FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (count-- > 0) {
        fscanf(file, "%s", word);
        strcpy(word_counts[count].word, word);
        word_counts[count].count = 0;
    }
}

void count_words(struct word_count *word_counts, int count, char *text) {
    char *token;
    char *context = NULL;
    int context_length = 0;
    int i = 0;
    while ((token = strtok_r(text, " \t\r\n", &context))) {
        if (context_length >= MAX_WORD_LENGTH) {
            context_length = 0;
        }
        strncat(context, token, MAX_WORD_LENGTH - context_length);
        context_length += strlen(token);
        for (int j = 0; j < count; j++) {
            if (strcmp(word_counts[j].word, context) == 0) {
                word_counts[j].count++;
            }
        }
    }
}

void print_word_counts(struct word_count *word_counts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    struct word_count word_counts[MAX_WORDS];
    int count;
    printf("Enter the number of words to count: ");
    scanf("%d", &count);
    read_words(word_counts, count, stdin);
    printf("Enter the text to count words in: ");
    char text[10000];
    fgets(text, sizeof(text), stdin);
    count_words(word_counts, count, text);
    printf("Word counts:\n");
    print_word_counts(word_counts, count);
    return 0;
}