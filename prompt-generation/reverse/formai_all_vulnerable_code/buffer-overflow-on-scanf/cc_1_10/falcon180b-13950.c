//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000000
#define WORD_LEN 10
#define EMAIL_LEN 50

typedef struct {
    char word[WORD_LEN];
    int count;
} WordCount;

bool is_spam(char* email) {
    int i = 0;
    char* spam_words[] = {"viagra", "cialis", "levitra", "porn", "sex", "casino", "gambling", "loans", "mortgage", "refinance", "make money", "earn money", "work from home", "free money", "get rich quick", "cheap", "discount", "sale", "offer", "deal", "promotion", "prize", "gift", "reward"};
    WordCount words[MAX_WORDS];

    while (email[i]) {
        if (isalpha(email[i])) {
            int j = 0;
            while (isalpha(email[i+j])) {
                j++;
            }
            strncpy(words[j].word, &email[i], WORD_LEN);
            words[j].word[WORD_LEN-1] = '\0';
            words[j].count++;
        }
        i++;
    }

    for (i = 0; i < MAX_WORDS; i++) {
        for (int j = 0; j < sizeof(spam_words)/sizeof(spam_words[0]); j++) {
            if (strcmp(words[i].word, spam_words[j]) == 0) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    char email[EMAIL_LEN];

    printf("Enter an email address: ");
    scanf("%s", email);

    if (is_spam(email)) {
        printf("Email is spam.\n");
    } else {
        printf("Email is not spam.\n");
    }

    return 0;
}