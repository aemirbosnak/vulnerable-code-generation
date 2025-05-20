//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

struct token {
    char *str;
    int len;
    int line_num;
};

struct token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *str, int len, int line_num) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].str = str;
    tokens[num_tokens].len = len;
    tokens[num_tokens].line_num = line_num;
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%d: %.*s\n", tokens[i].line_num, tokens[i].len, tokens[i].str);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    int line_num = 1;
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }
        char *ptr = line;
        while (*ptr) {
            if (isspace(*ptr)) {
                add_token(ptr, 0, line_num);
                ptr++;
            } else if (*ptr == '<') {
                char *end_ptr = strchr(ptr, '>');
                if (!end_ptr) {
                    printf("Error: Invalid tag on line %d\n", line_num);
                    exit(1);
                }
                int tag_len = end_ptr - ptr + 1;
                add_token(ptr, tag_len, line_num);
                ptr = end_ptr + 1;
            } else {
                add_token(ptr, 1, line_num);
                ptr++;
            }
        }
        line_num++;
    }
    print_tokens();
    return 0;
}