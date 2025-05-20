//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 1000

struct token {
    char *text;
    int length;
};

struct resume {
    int num_tokens;
    struct token *tokens;
};

void parse_resume(char *filename, struct resume *resume) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int num_tokens = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int i = 0;
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (num_tokens == MAX_TOKENS) {
                printf("Maximum number of tokens reached\n");
                exit(1);
            }
            struct token *t = &resume->tokens[num_tokens++];
            t->text = malloc(strlen(token) + 1);
            strcpy(t->text, token);
            t->length = strlen(token);
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);
    resume->num_tokens = num_tokens;
}

void print_resume(struct resume *resume) {
    for (int i = 0; i < resume->num_tokens; i++) {
        printf("%s\n", resume->tokens[i].text);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    struct resume resume;
    parse_resume(argv[1], &resume);
    print_resume(&resume);

    return 0;
}