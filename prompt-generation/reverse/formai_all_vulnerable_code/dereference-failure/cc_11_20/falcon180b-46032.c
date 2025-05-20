//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS 100

struct Word {
    char *word;
    int sentiment;
};

int main(int argc, char *argv[]) {
    FILE *fp;
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_SENTENCE_LENGTH];
    char *token;
    int i, j, k, num_words = 0;
    struct Word words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, fp)!= NULL) {
        num_words = 0;
        token = strtok(sentence, " ");
        while (token!= NULL) {
            if (num_words >= MAX_WORDS) {
                break;
            }
            strcpy(words[num_words].word, token);
            words[num_words].sentiment = 0;
            num_words++;
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    for (i = 0; i < num_words; i++) {
        for (j = 0; j < num_words; j++) {
            if (i == j) {
                continue;
            }
            k = 0;
            while (k < strlen(words[i].word) && k < strlen(words[j].word)) {
                if (tolower(words[i].word[k])!= tolower(words[j].word[k])) {
                    break;
                }
                k++;
            }
            if (k == strlen(words[i].word) || k == strlen(words[j].word)) {
                words[i].sentiment++;
            }
        }
    }

    printf("Sentiment analysis:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].sentiment);
    }

    return 0;
}