//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
int main() {
    char email[1000];
    printf("Enter email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    bool is_spam = false;
    int score = 0;
    for (int i = 0; email[i]!= '\0'; i++) {
        if (isupper(email[i])) {
            score++;
        }
        if (islower(email[i])) {
            score--;
        }
        if (isdigit(email[i])) {
            score--;
        }
        if (isspace(email[i])) {
            score++;
        }
        if (isalnum(email[i])) {
            score--;
        }
        if (email[i] == '.') {
            score++;
        }
        if (email[i] == '@') {
            score++;
        }
        if (email[i] == '_') {
            score++;
        }
    }
    score = (score + 10) * (rand() / (RAND_MAX + 1));
    if (score > 50) {
        is_spam = true;
    }
    if (is_spam) {
        printf("This is a spam email.\n");
    } else {
        printf("This is not a spam email.\n");
    }
    return 0;
}