//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int is_spam(char* input) {
    FILE* fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    struct word words[MAX_WORDS];
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fclose(fp);

    int total_words = 0;
    int spam_words = 0;

    char* token = strtok(input, " ");
    while (token!= NULL) {
        total_words++;

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].word) == 0) {
                spam_words++;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    if (spam_words >= total_words / 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[1000];
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    if (is_spam(input)) {
        printf("Input string is spam\n");
    } else {
        printf("Input string is not spam\n");
    }

    return 0;
}