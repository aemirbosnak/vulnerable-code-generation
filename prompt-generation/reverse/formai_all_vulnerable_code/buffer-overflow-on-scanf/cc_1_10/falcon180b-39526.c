//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3

// Function prototypes
int is_spam(char *email);
void tokenize(char *email, char **tokens);
int is_word_spam(char *word);

int main() {
    char email[1000];
    printf("Enter an email: ");
    scanf("%s", email);

    if (is_spam(email)) {
        printf("SPAM!\n");
    } else {
        printf("Not SPAM.\n");
    }

    return 0;
}

int is_spam(char *email) {
    char *tokens[MAX_WORDS];
    int num_tokens = 0;
    int spam_count = 0;

    tokenize(email, tokens);

    for (int i = 0; i < num_tokens; i++) {
        if (is_word_spam(tokens[i])) {
            spam_count++;
        }
    }

    if (spam_count >= 3) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void tokenize(char *email, char **tokens) {
    char *token = strtok(email, " ");
    int num_tokens = 0;

    while (token!= NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }
}

int is_word_spam(char *word) {
    if (strlen(word) < MIN_WORD_LENGTH) {
        return FALSE;
    }

    if (strcmp(word, "viagra") == 0 ||
        strcmp(word, "cialis") == 0 ||
        strcmp(word, "free") == 0 ||
        strcmp(word, "earn") == 0 ||
        strcmp(word, "money") == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}