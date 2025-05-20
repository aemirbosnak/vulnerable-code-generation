//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50
#define THRESHOLD 0.8

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} Word;

int main() {
    char input[MAX_WORD_LEN + 1];
    char *token;
    FILE *fp;
    int i, j, n, word_count, spam_count;
    Word *words;
    double *spam_prob;
    time_t now = time(NULL);

    // Load spam words
    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error loading spam words.\n");
        return 1;
    }
    words = (Word *)malloc(MAX_WORDS * sizeof(Word));
    spam_prob = (double *)malloc(MAX_WORDS * sizeof(double));
    n = 0;
    while (fscanf(fp, "%s", input)!= EOF) {
        words[n].word[0] = tolower(input[0]);
        strcpy(&words[n].word[1], input);
        words[n].count = 0;
        n++;
    }
    fclose(fp);

    // Initialize spam probabilities
    for (i = 0; i < n; i++) {
        spam_prob[i] = (double)words[i].count / (double)n;
    }

    // Read input text
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error reading input text.\n");
        return 1;
    }
    while (fscanf(fp, "%s", input)!= EOF) {
        // Convert input to lowercase
        for (i = 0; input[i]!= '\0'; i++) {
            input[i] = tolower(input[i]);
        }

        // Check for spam words
        token = strtok(input, ",.?!;:");
        while (token!= NULL) {
            for (j = 0; j < n; j++) {
                if (strcmp(token, words[j].word) == 0) {
                    words[j].count++;
                    break;
                }
            }
            if (j == n) {
                if (n >= MAX_WORDS) {
                    printf("Too many words.\n");
                    return 1;
                }
                strcpy(words[n].word, token);
                words[n].count = 1;
                n++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
    fclose(fp);

    // Calculate spam probabilities
    for (i = 0; i < n; i++) {
        spam_prob[i] = (double)words[i].count / (double)word_count;
    }

    // Classify input as spam or not
    word_count = 0;
    spam_count = 0;
    for (i = 0; i < n; i++) {
        if (spam_prob[i] >= THRESHOLD) {
            spam_count++;
        }
        word_count++;
    }
    if (spam_count >= (int)(word_count * THRESHOLD)) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}