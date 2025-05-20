//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 256

typedef struct {
    char *token;
    int count;
} token_t;

int main() {
    char input[1000000];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    token_t tokens[MAX_TOKENS];
    int num_tokens = 0;
    int i;

    printf("Enter some text to analyze:\n");
    while ((read = getline(&line, &len, stdin))!= -1) {
        strcat(input, line);
        free(line);
        line = NULL;
        len = 0;
    }

    printf("Input text:\n%s\n", input);

    // Tokenize input text
    char *token = strtok(input, " \n\r\t.,?!;:");
    while (token!= NULL && num_tokens < MAX_TOKENS) {
        for (i = 0; i < num_tokens; i++) {
            if (strcmp(tokens[i].token, token) == 0) {
                tokens[i].count++;
                break;
            }
        }
        if (i == num_tokens) {
            tokens[num_tokens].token = strdup(token);
            tokens[num_tokens].count = 1;
            num_tokens++;
        }
        token = strtok(NULL, " \n\r\t.,?!;:");
    }

    // Analyze spam probability
    double spam_prob = 0.0;
    for (i = 0; i < num_tokens; i++) {
        if (tokens[i].count > 1) {
            double token_prob = (double)tokens[i].count / strlen(input);
            spam_prob += token_prob;
        }
    }
    spam_prob /= num_tokens;

    if (spam_prob > 0.5) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    for (i = 0; i < num_tokens; i++) {
        free(tokens[i].token);
    }

    return 0;
}