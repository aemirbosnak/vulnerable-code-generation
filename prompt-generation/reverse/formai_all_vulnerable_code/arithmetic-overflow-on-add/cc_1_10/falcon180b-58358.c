//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000

typedef struct {
    char *word;
    int count;
} Token;

void read_file(FILE *fp, Token *tokens) {
    char line[1024];
    int len = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        len += strlen(line);
        if (len >= MAX_TOKENS * 50) {
            break;
        }
        char *p = line;
        while (*p!= '\0') {
            if (isalpha(*p)) {
                int i;
                for (i = 0; i < MAX_TOKENS; i++) {
                    if (tokens[i].word == NULL) {
                        tokens[i].word = strdup(p);
                        tokens[i].count = 1;
                        break;
                    } else if (strcmp(tokens[i].word, p) == 0) {
                        tokens[i].count++;
                        break;
                    }
                }
            }
            p++;
        }
    }
}

void print_tokens(Token *tokens) {
    int i;
    for (i = 0; i < MAX_TOKENS; i++) {
        if (tokens[i].word!= NULL) {
            printf("%s: %d\n", tokens[i].word, tokens[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        return 2;
    }

    Token tokens[MAX_TOKENS];
    read_file(fp, tokens);

    fclose(fp);

    print_tokens(tokens);

    return 0;
}