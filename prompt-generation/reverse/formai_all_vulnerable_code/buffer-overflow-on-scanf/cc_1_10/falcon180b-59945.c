//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 20

// Function to tokenize a string
void tokenize(char* str, char* tokens[]) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL && count < MAX_TOKENS) {
        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, " ");
    }
}

// Function to calculate the spam score of an email
int calculate_spam_score(char* email) {
    int score = 0;
    char* tokens[MAX_TOKENS];
    tokenize(email, tokens);
    for (int i = 0; i < MAX_TOKENS; i++) {
        if (strlen(tokens[i]) > MAX_WORD_LENGTH) {
            score += 2;
        }
        if (isupper(tokens[i][0])) {
            score += 1;
        }
        if (strstr(tokens[i], "free")!= NULL) {
            score += 2;
        }
        if (strstr(tokens[i], "win")!= NULL) {
            score += 1;
        }
        if (strstr(tokens[i], "earn")!= NULL) {
            score += 2;
        }
        if (strstr(tokens[i], "money")!= NULL) {
            score += 2;
        }
        if (strstr(tokens[i], "discount")!= NULL) {
            score += 1;
        }
        if (strstr(tokens[i], "cheap")!= NULL) {
            score += 1;
        }
        if (strstr(tokens[i], "affordable")!= NULL) {
            score += 1;
        }
        if (strstr(tokens[i], "low cost")!= NULL) {
            score += 2;
        }
    }
    return score;
}

int main() {
    char email[MAX_WORD_LENGTH * 10];
    printf("Enter an email: ");
    scanf("%s", email);
    int spam_score = calculate_spam_score(email);
    if (spam_score >= 5) {
        printf("The email is spam.\n");
    } else {
        printf("The email is not spam.\n");
    }
    return 0;
}