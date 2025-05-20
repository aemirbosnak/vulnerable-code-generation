//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LEN 1000
#define MAX_SUMMARY_LEN 200

char text[MAX_TEXT_LEN + 1];
char summary[MAX_SUMMARY_LEN + 1];

void read_text(void) {
    printf("Enter the text:\n");
    fgets(text, MAX_TEXT_LEN + 1, stdin);
}

void summarize_text(void) {
    int i, j, k, l, m, n, o, p, q, r;
    int word_count = 0, sentence_count = 0, paragraph_count = 0;
    int word_len = 0, sentence_len = 0, paragraph_len = 0;
    int word_freq[1000], sentence_freq[1000], paragraph_freq[1000];
    char words[1000][100], sentences[1000][100], paragraphs[1000][100];

    for (i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) {
            word_count++;
        }
    }

    for (i = 0, j = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentence_count++;
            sentences[j][sentence_len] = '\0';
            j++;
            sentence_len = 0;
        } else {
            sentences[j][sentence_len] = text[i];
            sentence_len++;
        }
    }

    for (i = 0, j = 0; sentences[i][0] != '\0'; i++) {
        if (strcmp(sentences[i], sentences[j]) == 0) {
            sentence_freq[j]++;
        } else {
            j++;
            sentence_freq[j] = 1;
            strcpy(sentences[j], sentences[i]);
        }
    }

    for (i = 0, j = 0; sentences[i][0] != '\0'; i++) {
        if (sentence_freq[i] > sentence_freq[j]) {
            j = i;
        }
    }

    strcpy(summary, sentences[j]);

    printf("Summary:\n%s", summary);
}

int main(void) {
    read_text();
    summarize_text();
    return 0;
}