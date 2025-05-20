//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 3

// Function to remove punctuations from a string
void remove_punctuations(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isalnum(str[i])) {
            continue;
        }
        str[j++] = tolower(str[i]);
    }
    str[j] = '\0';
}

// Function to check if a word is spam or not
int is_spam(char *word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (isdigit(word[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to tokenize a string into words
int tokenize(char *str, char words[][MAX_WORD_LENGTH]) {
    char *token = strtok(str, " ");
    int count = 0;
    while (token!= NULL) {
        remove_punctuations(token);
        if (strlen(token) >= MIN_WORD_LENGTH &&!is_spam(token)) {
            strcpy(words[count], token);
            count++;
        }
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to classify an email as spam or not spam
int classify_email(char words[][MAX_WORD_LENGTH], int num_words) {
    int i, spam_count = 0;
    for (i = 0; i < num_words; i++) {
        if (is_spam(words[i])) {
            spam_count++;
        }
    }
    if (spam_count >= (num_words / 2)) {
        return 1; // Spam
    } else {
        return 0; // Not spam
    }
}

int main() {
    char email[1000];
    printf("Enter an email: ");
    scanf("%s", email);

    char words[100][MAX_WORD_LENGTH];
    int num_words = tokenize(email, words);

    int is_spam = classify_email(words, num_words);

    if (is_spam) {
        printf("The email is spam.\n");
    } else {
        printf("The email is not spam.\n");
    }

    return 0;
}