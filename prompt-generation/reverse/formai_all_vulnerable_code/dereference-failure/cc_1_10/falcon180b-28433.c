//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct token {
    char *value;
    int length;
} token_t;

typedef struct resume {
    token_t name;
    token_t email;
    token_t phone;
    token_t address;
    token_t education;
    token_t experience;
} resume_t;

void tokenize(char *line, token_t *tokens, int max_tokens) {
    int i = 0;
    char *token_start = line;
    char *token_end = line;

    while (i < max_tokens && *token_end!= '\0') {
        while (*token_end!= '\0' && isspace(*token_end)) {
            token_end++;
        }

        if (*token_end == '\0') {
            break;
        }

        token_t token = {0};
        token_start = token_end;

        while (*token_end!= '\0' &&!isspace(*token_end)) {
            token_end++;
        }

        token.value = strndup(token_start, token_end - token_start);
        token.length = strlen(token.value);

        if (i < max_tokens) {
            tokens[i++] = token;
        }
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    resume_t resume = {0};

    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open resume file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        tokenize(line, resume.name.value, MAX_TOKENS);
        tokenize(line, resume.email.value, MAX_TOKENS);
        tokenize(line, resume.phone.value, MAX_TOKENS);
        tokenize(line, resume.address.value, MAX_TOKENS);
        tokenize(line, resume.education.value, MAX_TOKENS);
        tokenize(line, resume.experience.value, MAX_TOKENS);
    }

    fclose(fp);

    printf("Name: %s\n", resume.name.value);
    printf("Email: %s\n", resume.email.value);
    printf("Phone: %s\n", resume.phone.value);
    printf("Address: %s\n", resume.address.value);
    printf("Education: %s\n", resume.education.value);
    printf("Experience: %s\n", resume.experience.value);

    return 0;
}