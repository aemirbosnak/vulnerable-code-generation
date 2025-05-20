//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINES 10000
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *token;
    int count;
} token_t;

token_t tokens[MAX_LOG_LINES];
int num_tokens = 0;

void tokenize_line(char *line) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        int len = strlen(token);
        if (len > MAX_TOKEN_LENGTH) {
            len = MAX_TOKEN_LENGTH;
        }
        tokens[num_tokens].token = malloc(len + 1);
        strncpy(tokens[num_tokens].token, token, len);
        tokens[num_tokens].token[len] = '\0';
        tokens[num_tokens].count = 1;
        num_tokens++;
        token = strtok(NULL, " ");
    }
}

void print_token_counts() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].token, tokens[i].count);
    }
}

int main() {
    FILE *log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), log_file)!= NULL) {
        tokenize_line(line);
    }

    fclose(log_file);

    print_token_counts();

    return 0;
}