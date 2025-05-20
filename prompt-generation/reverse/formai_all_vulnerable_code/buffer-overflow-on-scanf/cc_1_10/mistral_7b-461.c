//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_WORDS 10
#define MIN_SPAM_SCORE 5

typedef struct {
    char word[MAX_WORDS][20];
    int score;
} word_t;

word_t words[] = {
    {"viagra", 3},
    {"cialis", 3},
    {"levitra", 3},
    {"viagrasales", 2},
    {"buyviagra", 2},
    {"cialissales", 2},
    {"levitrasales", 2},
    {"freeviagra", 1},
    {"freepills", 1},
    {"priapusshrine", 0}
};

int spam_check(char email[]) {
    int i, j, email_length, score = 0;
    char token[MAX_WORDS][20];
    int num_tokens = 0;

    email_length = strlen(email);
    for (i = 0; i < email_length; i++) {
        if (isalnum(email[i])) {
            token[num_tokens][i] = tolower(email[i]);
            num_tokens++;
            if (num_tokens >= MAX_WORDS) {
                num_tokens--;
                break;
            }
            email[i] = '\0'; // null terminate the token
            i++;
            while (isalnum(email[i])) {
                token[num_tokens][i] = tolower(email[i]);
                i++;
            }
            email[i] = '\0'; // null terminate the email

            for (j = 0; j < 10; j++) {
                if (strcmp(token[num_tokens - 1], words[j].word) == 0) {
                    score += words[j].score;
                    break;
                }
            }
        }
    }

    if (score >= MIN_SPAM_SCORE) {
        printf("Spam detected!\n");
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char email[MAX_EMAIL_SIZE];

    printf("Enter an email to check for spam: ");
    scanf("%s", email);

    if (spam_check(email)) {
        printf("Do not open this email!\n");
    } else {
        printf("This email is safe to open.\n");
    }

    return 0;
}