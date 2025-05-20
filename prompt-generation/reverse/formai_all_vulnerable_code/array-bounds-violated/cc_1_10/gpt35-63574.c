//FormAI DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LEN 1000   // maximum message length
#define SPAM_SCORE 0.8     // threshold for spam detection

// function to calculate the spam score of a message
double calc_spam_score(char *msg) {
    double score = 0.0;
    char *token;
    char delimiters[] = " ,.;:-?!";

    // tokenize the message using delimiters
    token = strtok(msg, delimiters);
    while (token != NULL) {
        // check if the token is a known spam word
        if (strcmp(token, "buy") == 0 ||
            strcmp(token, "now") == 0 ||
            strcmp(token, "limited") == 0 ||
            strcmp(token, "offer") == 0) {
            score += 0.1;
        }
        // check if the token is a link
        else if (strstr(token, "http://") != NULL ||
                 strstr(token, "https://") != NULL) {
            score += 0.2;
        }

        token = strtok(NULL, delimiters);
    }

    return score;
}

int main() {
    char msg[MAX_MSG_LEN];
    double score;

    printf("Enter the message: ");
    fgets(msg, MAX_MSG_LEN, stdin);
    msg[strlen(msg) - 1] = '\0';   // remove newline character at the end

    score = calc_spam_score(msg);

    // check if the message is spam
    if (score >= SPAM_SCORE) {
        printf("The message is spam.\n");
    }
    else {
        printf("The message is not spam.\n");
    }

    return 0;
}