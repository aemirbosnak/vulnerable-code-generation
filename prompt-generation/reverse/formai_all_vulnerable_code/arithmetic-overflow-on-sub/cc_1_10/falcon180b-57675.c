//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

char *tokens[MAX_TOKENS];
int num_tokens;

void tokenize(char *str) {
    char *token;
    int i = 0;
    while (*str) {
        if (isspace(*str)) {
            *str = '\0';
            token = strdup(str);
            str++;
            tokens[i++] = token;
        } else {
            str++;
        }
    }
    num_tokens = i;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: cannot open file.\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }
        tokenize(line);
        for (int i = 0; i < num_tokens; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }

    fclose(fp);
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    return 0;
}