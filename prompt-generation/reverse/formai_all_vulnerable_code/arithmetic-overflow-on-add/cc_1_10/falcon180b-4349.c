//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 30

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

void add_word(Word *word_list, char *word) {
    int i, j;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word_list[i].word, word) == 0) {
            word_list[i].count++;
            return;
        }
    }
    for (j = 0; j < MAX_WORDS; j++) {
        if (word_list[j].count == 0) {
            strcpy(word_list[j].word, word);
            word_list[j].count = 1;
            return;
        }
    }
}

int is_spam(char *email, Word *word_list) {
    char *p;
    int i, spam_count = 0;
    for (p = email; *p!= '\0'; p++) {
        if (isalpha(*p)) {
            for (i = 0; i < MAX_WORDS; i++) {
                if (strstr(p, word_list[i].word)) {
                    spam_count++;
                }
            }
        }
    }
    return spam_count;
}

int main() {
    FILE *fp;
    char email[1000];
    Word word_list[MAX_WORDS];
    int i, j, k, num_spam = 0;
    float spam_ratio;

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word_list[i].word)!= EOF) {
        i++;
        if (i == MAX_WORDS) {
            break;
        }
    }

    fclose(fp);

    fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Error opening emails.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s", email)!= EOF) {
        num_spam += is_spam(email, word_list);
    }

    fclose(fp);

    spam_ratio = (float) num_spam / (float) (i * strlen(email));
    printf("Spam ratio: %.2f%%\n", spam_ratio * 100);

    return 0;
}