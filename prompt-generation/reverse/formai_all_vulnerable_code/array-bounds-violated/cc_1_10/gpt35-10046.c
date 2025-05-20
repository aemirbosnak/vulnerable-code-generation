//FormAI DATASET v1.0 Category: Spam Detection System ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_LENGTH 20
#define MAX_MSG_LENGTH 100

// function to check if a word is a spam word
int check_spam(char word[], char spam_words[][MAX_SPAM_LENGTH], int num_spam_words) {
    int i, flag = 0;
    for (i = 0; i < num_spam_words; i++) {
        if (strcmp(word, spam_words[i]) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

// function to check if a message is spam or not
int is_spam(char msg[], char spam_words[][MAX_SPAM_LENGTH], int num_spam_words) {
    int i, spam_count = 0;
    char word[MAX_SPAM_LENGTH];
    // tokenize the message
    char *token = strtok(msg, " ");
    while (token != NULL) {
        strcpy(word, token);
        // check if the word is a spam word
        if (check_spam(word, spam_words, num_spam_words)) {
            spam_count++;
            // if 3 or more spam words are found, mark the message as spam
            if (spam_count >= 3) {
                return 1;
            }
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    // array of spam words
    char spam_words[MAX_SPAM_WORDS][MAX_SPAM_LENGTH] = {"sale", "discount", "offer", "free", "money"};

    char msg[MAX_MSG_LENGTH];
    printf("Enter a message: ");
    fgets(msg, MAX_MSG_LENGTH, stdin);

    // remove the newline character from the end of the message
    if (msg[strlen(msg) - 1] == '\n') {
        msg[strlen(msg) - 1] = '\0';
    }

    // check if the message is spam or not
    if (is_spam(msg, spam_words, MAX_SPAM_WORDS)) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}