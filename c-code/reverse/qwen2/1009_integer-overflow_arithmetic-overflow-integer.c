#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_LEN 500
#define MAX_SUMMARY_LEN 100

typedef struct {
    char word[20];
    int freq;
} Word;

int compare(const void *a, const void *b) {
    return ((Word *)b)->freq - ((Word *)a)->freq;
}

void summarize(char *text, char *summary) {
    char words[MAX_TEXT_LEN][20];
    int word_count = 0;
    Word word_freq[MAX_TEXT_LEN] = {0};
    int i, j, k, len;

    // Tokenize input text into words
    char *token = strtok(text, " ");
    while (token != NULL && word_count < MAX_TEXT_LEN) {
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " ");
    }

    // Count word frequencies
    for (i = 0; i < word_count; i++) {
        for (j = 0; j < word_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_freq[i].freq++;
            }
        }
    }

    // Sort words by frequency
    qsort(word_freq, word_count, sizeof(Word), compare);

    // Build summary
    summary[0] = '\0';
    for (i = 0; i < word_count && strlen(summary) + strlen(word_freq[i].word) <= MAX_SUMMARY_LEN; i++) {
        strcat(summary, word_freq[i].word);
        strcat(summary, " ");
    }

    // Remove trailing space
    len = strlen(summary);
    if (len > 0 && summary[len - 1] == ' ') {
        summary[len - 1] = '\0';
    }
}

int main() {
    char text[MAX_TEXT_LEN];
    char summary[MAX_SUMMARY_LEN];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    summarize(text, summary);

    printf("Summary: %s\n", summary);

    return 0;
}
