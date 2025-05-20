//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Surprisingly Small, Simple, and Swift CSV Reader

typedef struct {
    size_t len;
    char *str;
} str_t;

str_t read_token(FILE *fp) {
    str_t token = {0};
    char c;

    while (isspace(c = fgetc(fp))) {}
    if (c == EOF) { token.len = 0; return token; }

    token.str = malloc(sizeof(char) * (token.len = 1));
    token.str[0] = c;

    while (fscanf(fp, "%c%n", &c, &token.len) != EOF) {
        token.str = realloc(token.str, token.len + 1);
        token.str[token.len++] = c;

        if (c == ',') {
            token.str[token.len - 1] = '\0';
            break;
        }
    }

    return token;
}

int main() {
    FILE *fp;
    str_t token;
    size_t row = 0, col = 0;

    fp = fopen("example.csv", "r");
    if (fp == NULL) { fprintf(stderr, "Could not open file\n"); return 1; }

    printf("CSV Data:\n");

    while (fgetc(fp) != EOF) {
        if (++row > 1) printf("\n");

        while ((token = read_token(fp)).len) {
            if (++col > 1) printf("\t");
            printf("%s", token.str);
            free(token.str);
        }
    }

    fclose(fp);
    return 0;
}