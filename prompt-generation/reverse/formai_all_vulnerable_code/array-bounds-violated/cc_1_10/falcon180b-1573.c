//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to tokenize the input string
void tokenize(char *str, char **tokens) {
    int i = 0, j = 0, k;
    char *token;

    while (str[i]) {
        if (isspace(str[i])) {
            str[i] = '\0';
            tokens[j++] = &str[k];
        } else {
            k = i;
        }
        i++;
    }

    tokens[j] = NULL;
}

// Function to calculate the spam score
int calculate_spam_score(char **tokens) {
    int i, score = 0;

    for (i = 0; tokens[i]; i++) {
        if (strcasecmp(tokens[i], "viagra") == 0 ||
            strcasecmp(tokens[i], "cialis") == 0 ||
            strcasecmp(tokens[i], "levitra") == 0 ||
            strcasecmp(tokens[i], "spam") == 0) {
            score += 5;
        } else if (strcasecmp(tokens[i], "free") == 0 ||
                   strcasecmp(tokens[i], "win") == 0 ||
                   strcasecmp(tokens[i], "discount") == 0) {
            score += 3;
        } else if (strcasecmp(tokens[i], "earn") == 0 ||
                   strcasecmp(tokens[i], "money") == 0 ||
                   strcasecmp(tokens[i], "cash") == 0) {
            score += 2;
        } else if (strcasecmp(tokens[i], "loan") == 0 ||
                   strcasecmp(tokens[i], "refinance") == 0 ||
                   strcasecmp(tokens[i], "mortgage") == 0) {
            score += 1;
        }
    }

    return score;
}

// Function to classify the input as spam or not spam
char classify_spam(int score) {
    if (score >= 10) {
        return 'S';
    } else {
        return 'N';
    }
}

int main() {
    char input[1000], *token;
    int i, score, len;
    char spam_class;

    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    // Remove newline character
    input[len - 1] = '\0';

    // Tokenize the input string
    char *tokens[100];
    tokenize(input, tokens);

    // Calculate the spam score
    score = calculate_spam_score(tokens);

    // Classify the input as spam or not spam
    spam_class = classify_spam(score);

    if (spam_class == 'S') {
        printf("The input string is classified as spam.\n");
    } else {
        printf("The input string is not classified as spam.\n");
    }

    return 0;
}