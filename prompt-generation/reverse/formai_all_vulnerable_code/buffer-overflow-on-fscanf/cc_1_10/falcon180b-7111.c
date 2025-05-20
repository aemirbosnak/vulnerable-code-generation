//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define THRESHOLD 0.8

struct spam_info {
    char *word;
    double frequency;
};

int spam_detection(FILE *fp, struct spam_info *spam_words, int num_spam_words) {
    char word[MAX_WORD_LEN];
    int i, j, is_spam = 0;
    double total_frequency = 0.0;

    while (fscanf(fp, "%s", word)!= EOF) {
        for (i = 0; i < num_spam_words; i++) {
            if (strcmp(word, spam_words[i].word) == 0) {
                total_frequency += spam_words[i].frequency;
                is_spam = 1;
                break;
            }
        }
    }

    if (is_spam) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is likely not spam.\n");
    }

    return 0;
}

int main() {
    FILE *fp;
    char filename[100];
    int num_spam_words = 0;
    struct spam_info spam_words[MAX_WORDS];

    printf("Enter the name of the spam words file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %lf", spam_words[num_spam_words].word, &spam_words[num_spam_words].frequency)!= EOF) {
        num_spam_words++;
    }

    fclose(fp);

    printf("Enter the name of the file to check for spam: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    spam_detection(fp, spam_words, num_spam_words);

    fclose(fp);

    return 0;
}