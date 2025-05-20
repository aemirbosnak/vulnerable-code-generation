//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    int count;
} Token;

void init_token(Token *t, char *name) {
    t->name = name;
    t->count = 0;
}

void add_token(Token *t, char *name) {
    if (t->count >= MAX_TOKENS) {
        printf("Error: Token '%s' exceeds maximum count.\n", name);
        return;
    }
    t->name[t->count] = name;
    t->count++;
}

void print_tokens(Token t) {
    int i;
    for (i = 0; i < t.count; i++) {
        printf("%s ", t.name[i]);
    }
    printf("\n");
}

void process_line(char *line, Token *tokens) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        int len = strlen(word);
        if (len > MAX_TOKEN_LEN) {
            printf("Error: Word '%s' exceeds maximum length.\n", word);
            return;
        }
        add_token(tokens, word);
        word = strtok(NULL, " ");
    }
}

int main() {
    FILE *fp;
    char line[1024];
    Token tokens;
    init_token(&tokens, "");

    if ((fp = fopen("resume.txt", "r")) == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        process_line(line, &tokens);
    }

    fclose(fp);

    print_tokens(tokens);

    return 0;
}