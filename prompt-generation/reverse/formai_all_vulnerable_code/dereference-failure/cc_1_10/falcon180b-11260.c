//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} token_t;

int num_tokens = 0;
token_t tokens[MAX_TOKENS];

int add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached.\n");
        return 0;
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
    return 1;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    char *delim = " \n\t\r\f\v";
    int i = 0;

    if ((fp = fopen("resume.txt", "r")) == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (i == 0) {
            token = strtok(line, delim);
            add_token("Name", token);
            i++;
        } else if (i == 1) {
            token = strtok(line, delim);
            add_token("Email", token);
            i++;
        } else if (i == 2) {
            token = strtok(line, delim);
            add_token("Phone", token);
            i++;
        } else if (i == 3) {
            token = strtok(line, delim);
            add_token("Address", token);
            i++;
        }
    }

    fclose(fp);

    for (i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }

    return 0;
}