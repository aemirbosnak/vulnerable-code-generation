//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int len;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} Resume;

Resume *parse_resume(char *resume_text) {
    Resume *r = malloc(sizeof(Resume));
    r->tokens = malloc(MAX_TOKENS * sizeof(Token));
    r->num_tokens = 0;

    char *token_start = resume_text;
    char *token_end = resume_text;

    while (*token_end!= '\0') {
        if (isspace(*token_end)) {
            *token_end = '\0';
            token_end++;
        } else {
            char *token_ptr = token_end;
            while (!isspace(*token_ptr)) {
                if (r->num_tokens >= MAX_TOKENS) {
                    printf("Error: Maximum number of tokens exceeded.\n");
                    exit(1);
                }
                r->tokens[r->num_tokens].token = malloc(MAX_TOKEN_LEN * sizeof(char));
                r->tokens[r->num_tokens].len = 0;

                int i = 0;
                while (!isspace(*token_ptr) && i < MAX_TOKEN_LEN - 1) {
                    r->tokens[r->num_tokens].token[i++] = *token_ptr;
                    token_ptr++;
                }
                r->tokens[r->num_tokens].len = i;
                r->num_tokens++;

                if (isspace(*token_ptr)) {
                    *token_ptr = '\0';
                }
            }
        }

        token_start = token_end;
    }

    return r;
}

void print_resume(Resume *r) {
    for (int i = 0; i < r->num_tokens; i++) {
        printf("%s\n", r->tokens[i].token);
    }
}

int main() {
    char *resume_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                         "Nulla accumsan, lectus vel pharetra eleifend, velit elit "
                         "ullamcorper nunc, vel bibendum elit elit eu elit. "
                         "Mauris euismod tellus id magna bibendum, vel efficitur "
                         "lectus rutrum. Sed euismod, nibh sit amet efficitur "
                         "vestibulum, nisi dui bibendum nunc, vel bibendum elit "
                         "mi vel elit. Curabitur euismod tellus id magna "
                         "bibendum efficitur. ";

    Resume *r = parse_resume(resume_text);
    print_resume(r);

    free(r->tokens);
    free(r);

    return 0;
}