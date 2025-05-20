//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compare_strings(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void load_words(char** words, int* num_words) {
    FILE* fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open spam_words.txt\n");
        exit(1);
    }

    *num_words = 0;
    while (fscanf(fp, "%s", words[*num_words])!= EOF) {
        (*num_words)++;
    }

    fclose(fp);
}

int is_spam(char* message, WordCount* word_counts, int num_words) {
    int spam_score = 0;
    char* words[MAX_WORDS];
    int num_message_words = 0;

    char* token = strtok(message, " ");
    while (token!= NULL) {
        if (num_message_words >= MAX_WORDS) {
            break;
        }

        words[num_message_words] = token;
        num_message_words++;

        token = strtok(NULL, " ");
    }

    qsort(words, num_message_words, sizeof(char*), compare_strings);

    for (int i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < num_message_words; j++) {
            if (strcmp(words[j], word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }

        if (j == num_message_words) {
            spam_score += word_counts[i].count;
        }
    }

    return spam_score;
}

int main() {
    char* message = "Make money fast! Buy now! Limited time offer!";
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    load_words(word_counts, &num_words);

    int spam_score = is_spam(message, word_counts, num_words);

    if (spam_score > 0) {
        printf("Spam detected\n");
    } else {
        printf("Not spam\n");
    }

    return 0;
}