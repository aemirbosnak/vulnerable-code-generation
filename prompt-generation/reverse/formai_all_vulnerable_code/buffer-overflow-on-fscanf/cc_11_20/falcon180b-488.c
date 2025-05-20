//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000
#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3
#define THRESHOLD 5
#define SPAM_WORD_FILE "spam_words.txt"

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int count = 0;
    int word_count = 0;
    int spam_count = 0;
    char *spam_words[MAX_WORDS];
    int spam_word_count = 0;

    // Load spam words
    fp = fopen(SPAM_WORD_FILE, "r");
    if (fp == NULL) {
        printf("Error loading spam words\n");
        exit(1);
    }
    while (fscanf(fp, "%s", word)!= EOF) {
        spam_words[spam_word_count++] = strdup(word);
    }
    fclose(fp);

    // Read input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error reading input file\n");
        exit(1);
    }

    // Count words
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        word_count = 0;
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (strlen(token) >= MIN_WORD_LENGTH) {
                word_count++;
                for (int i = 0; i < spam_word_count; i++) {
                    if (strcmp(token, spam_words[i]) == 0) {
                        spam_count++;
                        break;
                    }
                }
            }
            token = strtok(NULL, " ");
        }
        if (spam_count >= THRESHOLD) {
            printf("Line %d is spam\n", count + 1);
        }
        else {
            printf("Line %d is not spam\n", count + 1);
        }
        count++;
    }

    // Free memory
    for (int i = 0; i < spam_word_count; i++) {
        free(spam_words[i]);
    }
    free(spam_words);

    fclose(fp);

    return 0;
}