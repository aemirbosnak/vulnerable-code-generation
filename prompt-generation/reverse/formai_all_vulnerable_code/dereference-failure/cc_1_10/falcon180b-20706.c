//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} token_t;

typedef struct {
    int count;
    token_t tokens[MAX_TOKENS];
} section_t;

section_t *create_section(void) {
    section_t *s = (section_t *) malloc(sizeof(section_t));
    s->count = 0;
    return s;
}

void add_token(section_t *s, char *name, char *value) {
    if (s->count >= MAX_TOKENS) {
        printf("Error: section '%s' exceeds maximum number of tokens (%d)\n", s->tokens[0].name, MAX_TOKENS);
        exit(1);
    }
    s->tokens[s->count++] = (token_t) {
       .name = strdup(name),
       .value = strdup(value)
    };
}

void print_section(section_t *s) {
    for (int i = 0; i < s->count; i++) {
        printf("%s: %s\n", s->tokens[i].name, s->tokens[i].value);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char line[MAX_TOKEN_LEN];
    section_t *current_section = NULL;
    while (fgets(line, MAX_TOKEN_LEN, fp)) {
        char *token = strtok(line, ":");
        if (!token) continue;

        if (token[0] == '[') {
            if (current_section) {
                print_section(current_section);
            }
            token++;
            char *end = strchr(token, ']');
            if (!end) {
                printf("Error: malformed section header '%s'\n", token);
                exit(1);
            }
            *end = '\0';
            current_section = create_section();
            add_token(current_section, token, "");
        } else {
            char *value = strtok(NULL, ":");
            if (!value) {
                printf("Error: malformed line '%s'\n", line);
                exit(1);
            }
            add_token(current_section, token, value);
        }
    }

    if (current_section) {
        print_section(current_section);
    }

    fclose(fp);
    return 0;
}