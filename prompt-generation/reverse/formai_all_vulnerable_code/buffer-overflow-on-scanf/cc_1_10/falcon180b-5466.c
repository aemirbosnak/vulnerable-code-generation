//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int is_spam;
};

int is_spam(char *word) {
    if (strstr(word, "viagra")!= NULL ||
        strstr(word, "cialis")!= NULL ||
        strstr(word, "levitra")!= NULL) {
        return 1;
    }
    return 0;
}

int load_words(struct word *words) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    int count = 0;

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        return 0;
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        words[count].word[strcspn(line, "\n")] = '\0';
        words[count].is_spam = is_spam(line);
        count++;
    }

    fclose(fp);
    return count;
}

int is_spam_message(char *message, struct word *words, int num_words) {
    char word[MAX_WORD_LENGTH];
    int i, j;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            word[0] = tolower(message[i]);
            for (j = 1; j < strlen(message) && isalnum(message[i + j]); j++) {
                word[j] = tolower(message[i + j]);
            }
            word[j] = '\0';

            for (int k = 0; k < num_words; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    return words[k].is_spam;
                }
            }
        }
    }

    return 0;
}

int main() {
    struct word words[MAX_WORDS];
    int num_words;

    num_words = load_words(words);

    char message[MAX_WORD_LENGTH];

    printf("Enter message: ");
    scanf("%s", message);

    if (is_spam_message(message, words, num_words)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}