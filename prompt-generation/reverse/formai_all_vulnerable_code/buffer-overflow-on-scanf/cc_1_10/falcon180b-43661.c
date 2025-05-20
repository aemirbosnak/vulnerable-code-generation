//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 64
#define MAX_LINES 100000

typedef struct {
    char *token;
    int count;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void parse_line(char *line) {
    char *token = strtok(line, " \t\n\r");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_tokens; i++) {
            if (strcmp(tokens[i].token, token) == 0) {
                tokens[i].count++;
                break;
            }
        }
        if (i == num_tokens) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: too many tokens\n");
                exit(1);
            }
            tokens[num_tokens].token = strdup(token);
            tokens[num_tokens].count = 1;
            num_tokens++;
        }
        token = strtok(NULL, " \t\n\r");
    }
}

void print_results() {
    printf("Token\tCount\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s\t%d\n", tokens[i].token, tokens[i].count);
    }
}

int main() {
    char line[MAX_TOKEN_LEN];
    char filename[MAX_TOKEN_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }
    int line_num = 0;
    while (fgets(line, MAX_TOKEN_LEN, file)!= NULL) {
        line_num++;
        if (line_num > MAX_LINES) {
            printf("Error: too many lines\n");
            exit(1);
        }
        parse_line(line);
    }
    fclose(file);
    print_results();
    return 0;
}