#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEYWORD_LEN 6
#define NUM_KEYWORDS 5

const char *keywords[NUM_KEYWORDS][KEYWORD_LEN] = {
    {"int", "float", "char", "for", "while", "switch"}
};

void find_keywords(char *code) {
    int i, j, found;
    char word[KEYWORD_LEN];

    for (i = 0; i < NUM_KEYWORDS; ++i) {
        found = 1;
        for (j = 0; j < KEYWORD_LEN; ++j) {
            if (code[j] != keywords[i][j] && !isalpha(code[j])) {
                found = 0;
                break;
            }
        }
        if (found) {
            strncpy(word, keywords[i], KEYWORD_LEN);
            printf("Keyword found: %s\n", word);
        }
    }

    // Handle remaining characters
    for (; *code; ++code) {
        if (isalnum(*code) || *code == '_')
            putchar(*code);
        else if (*code == '\'' || *code == '\"') {
            char quote = *code;
            char c;
            while ((c = getchar()) != EOF && c != quote)
                putchar(c);
        }
        else
            putchar('\\');
        putchar(*code);
    }
    putchar('\n');
}

int main() {
    char code[1024];
    printf("Enter C code: ");
    fgets(code, sizeof(code), stdin);
    find_keywords(code);
    return 0;
}
