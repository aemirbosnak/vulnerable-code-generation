//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *text;
    int count;
} token_t;

int main(int argc, char **argv) {
    FILE *file = fopen("logfile.txt", "r");
    if (file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *tokens[MAX_TOKENS];
    int num_tokens = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: Too many tokens.\n");
                fclose(file);
                return 1;
            }

            token_t *current_token = (token_t *)malloc(sizeof(token_t));
            current_token->text = strdup(token);
            current_token->count = 1;

            int i;
            for (i = 0; i < num_tokens; i++) {
                if (strcmp(tokens[i], token) == 0) {
                    tokens[i] = strdup(token);
                    current_token->count += 1;
                    break;
                }
            }

            if (i == num_tokens) {
                tokens[num_tokens++] = strdup(token);
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i], ((token_t *)tokens[i])->count);
    }

    return 0;
}