//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_t {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    struct word_t *word1 = (struct word_t *)a;
    struct word_t *word2 = (struct word_t *)b;

    return strcmp(word1->word, word2->word);
}

int is_spam(char *email) {
    FILE *fp;
    char ch;
    int spam = 0;

    fp = fopen("spam_words.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open spam_words.txt\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            continue;
        }

        int i;
        for (i = 0; i < strlen(email); i++) {
            if (tolower(ch) == tolower(email[i])) {
                spam = 1;
                break;
            }
        }

        if (spam) {
            break;
        }
    }

    fclose(fp);

    return spam;
}

int main() {
    char email[MAX_WORD_LENGTH];

    printf("Enter email address: ");
    scanf("%s", email);

    if (is_spam(email)) {
        printf("Email is spam\n");
    } else {
        printf("Email is not spam\n");
    }

    return 0;
}