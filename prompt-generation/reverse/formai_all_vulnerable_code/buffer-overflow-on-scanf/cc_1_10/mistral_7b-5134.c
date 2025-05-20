//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

enum State {
    STATE_LOWER,
    STATE_UPPER,
    STATE_DIGIT,
    STATE_SPECIAL,
    STATE_REPEAT,
    STATE_END
};

int score_password(const char *password) {
    int length = strlen(password);
    int score = 0;

    if (length < MIN_LENGTH) {
        score += 10 * (MIN_LENGTH - length);
    }

    int state = STATE_LOWER;
    for (size_t i = 0; i < length; ++i) {
        char c = tolower(password[i]);

        switch (state) {
            case STATE_LOWER:
                if (isalpha(c)) {
                    score += 1;
                } else if (isdigit(c)) {
                    state = STATE_DIGIT;
                } else if (isalnum(c) && i > 0 && password[i - 1] == c) {
                    state = STATE_REPEAT;
                } else {
                    state = STATE_SPECIAL;
                }
                break;

            case STATE_UPPER:
                if (isupper(c)) {
                    score += 1;
                } else {
                    state = STATE_LOWER;
                }
                break;

            case STATE_DIGIT:
                if (isdigit(c)) {
                    score += 1;
                } else {
                    state = STATE_LOWER;
                }
                break;

            case STATE_SPECIAL:
                if (strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?`~", c)) {
                    score += 1;
                } else {
                    state = STATE_LOWER;
                }
                break;

            case STATE_REPEAT:
                if (c == password[i - 1]) {
                    score += 1;
                }
                state = STATE_LOWER;
                break;

            case STATE_END:
                // We shouldn't reach this state
                break;
        }
    }

    if (length > MAX_LENGTH) {
        score += 10 * (length - MAX_LENGTH);
    }

    return score;
}

int main() {
    char password[MAX_LENGTH + 1];
    int score;

    printf("Enter your password: ");
    scanf("%s", password);

    score = score_password(password);

    printf("Password score: %d\n", score);

    return 0;
}