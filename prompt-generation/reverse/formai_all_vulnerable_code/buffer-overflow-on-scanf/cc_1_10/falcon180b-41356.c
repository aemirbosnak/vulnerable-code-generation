//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

int is_spam(char* email);

int main() {
    char email[MAX_WORD_LENGTH];
    printf("Enter email: ");
    scanf("%s", email);

    int is_spam_result = is_spam(email);

    if (is_spam_result == 1) {
        printf("Email is spam.\n");
    } else {
        printf("Email is not spam.\n");
    }

    return 0;
}

int is_spam(char* email) {
    char* words[MAX_WORDS];
    int num_words = 0;
    char* word;
    int i;

    // Split email into words
    word = strtok(email, " ");
    while (word!= NULL) {
        if (num_words >= MAX_WORDS) {
            break;
        }
        words[num_words] = word;
        num_words++;
        word = strtok(NULL, " ");
    }

    // Check for spam words
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i], "spam") == 0) {
            return 1;
        }
    }

    return 0;
}