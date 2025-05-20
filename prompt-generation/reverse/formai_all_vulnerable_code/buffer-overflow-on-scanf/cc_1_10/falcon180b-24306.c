//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define MAX_EMAIL_LEN 100

int is_spam(char* email);

int main() {
    char email[MAX_EMAIL_LEN];
    printf("Enter an email address: ");
    scanf("%s", email);

    if (is_spam(email)) {
        printf("Email is spam.\n");
    } else {
        printf("Email is not spam.\n");
    }

    return 0;
}

int is_spam(char* email) {
    char* words[MAX_WORDS];
    int num_words = 0;
    char* token = strtok(email, " \t\r\n");
    while (token!= NULL && num_words < MAX_WORDS) {
        if (strlen(token) > MAX_WORD_LEN) {
            return 1; // email contains a very long word
        }
        words[num_words++] = token;
        token = strtok(NULL, " \t\r\n");
    }
    if (num_words == 0) {
        return 1; // email is empty
    }
    if (num_words == 1) {
        return 1; // email contains only one word
    }
    if (num_words > 5) {
        return 1; // email contains too many words
    }
    for (int i = 0; i < num_words; i++) {
        char* word = words[i];
        if (strlen(word) < 4) {
            return 1; // email contains a short word
        }
        if (isalpha(word[0]) && isalpha(word[1]) && isalpha(word[2])) {
            return 1; // email contains a word starting with 3 letters
        }
        if (strstr(word, "free")!= NULL) {
            return 1; // email contains the word "free"
        }
        if (strstr(word, "win")!= NULL) {
            return 1; // email contains the word "win"
        }
        if (strstr(word, "earn")!= NULL) {
            return 1; // email contains the word "earn"
        }
    }
    return 0;
}