//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

char *trim(char *s)
{
    char *end;
    if (s == NULL) return NULL;
    end = s + strlen(s) - 1;
    while (end > s && isspace((int) *end)) {
        *end-- = '\0';
    }
    return s;
}

void tokenize(char *line, char *tokens[])
{
    int i = 0;
    char *token;
    token = strtok(line, " \t\n\r");
    while (token!= NULL) {
        tokens[i++] = trim(token);
        token = strtok(NULL, " \t\n\r");
    }
    tokens[i] = NULL;
}

int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *tokens[10]; // Max 10 words per line

    while ((read = getline(&line, &len, stdin))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }
        tokenize(line, tokens);
        for (int i = 0; tokens[i]!= NULL; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }

    return 0;
}