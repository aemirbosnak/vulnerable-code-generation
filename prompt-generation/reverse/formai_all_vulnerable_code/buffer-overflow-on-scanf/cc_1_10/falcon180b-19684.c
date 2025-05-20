//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word *word_a = (const struct word *)a;
    const struct word *word_b = (const struct word *)b;

    return strcasecmp(word_a->word, word_b->word);
}

int is_spam(const char *email) {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    struct word words[MAX_WORDS];
    int num_words = 0;
    int spam_count = 0;

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open spam_words.txt\n");
        return 0;
    }

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many spam words\n");
            return 0;
        }

        strcpy(words[num_words].word, line);
        words[num_words].count = 0;
        num_words++;
    }

    fclose(fp);

    fp = fopen(email, "r");
    if (fp == NULL) {
        printf("Error: could not open email\n");
        return 0;
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                spam_count++;
            }
        }
    }

    fclose(fp);

    qsort(words, num_words, sizeof(struct word), compare_words);

    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    if (spam_count > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[MAX_WORD_LEN];

    printf("Enter email: ");
    scanf("%s", email);

    if (is_spam(email)) {
        printf("Email is spam\n");
    } else {
        printf("Email is not spam\n");
    }

    return 0;
}