//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *token;
    int count;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens;

void add_token(char *token) {
    int i;
    for (i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i].token, token) == 0) {
            tokens[i].count++;
            return;
        }
    }
    if (num_tokens >= MAX_TOKENS) {
        printf("Too many tokens!\n");
        exit(1);
    }
    strcpy(tokens[num_tokens].token, token);
    tokens[num_tokens].count = 1;
    num_tokens++;
}

int is_spam(char *message) {
    int i, j;
    char *token;
    int spam_count = 0;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            token = (char *)malloc(MAX_TOKEN_LENGTH);
            strcpy(token, "");
            j = i;
            while (isalpha(message[j])) {
                strcat(token, message[j]);
                j++;
            }
            add_token(token);
            free(token);
        }
    }
    for (i = 0; i < num_tokens; i++) {
        if (tokens[i].count > 1) {
            spam_count++;
        }
    }
    return spam_count;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024];
    int spam_count = 0;
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), file)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        spam_count += is_spam(line);
    }
    fclose(file);
    printf("Spam count: %d\n", spam_count);
    return 0;
}