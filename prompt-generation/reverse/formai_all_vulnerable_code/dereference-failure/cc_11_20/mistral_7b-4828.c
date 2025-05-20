//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CAT_MEOW "mrow mrow mrow"
#define CAT_MIAOW "meow meow meow"
#define CAT_FISH "fish fish fish"
#define CAT_SCRATCH "scratch scratch scratch"

int main() {
    char input[100], *token;
    int i, length;

    printf("Welcome to CAT-C, the C compiler for cats!\n");
    printf("Translating human C code to cat-speak for our feline overlords.\n");

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    length = strlen(input);
    token = strtok(input, " ");

    for (i = 0; i < length; i++) {
        if (token[i] == '=') { // assignment
            printf("%s %s %s %s\n", CAT_MIAOW, CAT_MEOW, token + i + 1, CAT_SCRATCH);
            i += 2;
        } else if (token[i] == ';') { // semicolon
            printf("%s\n", CAT_FISH);
        } else if (isdigit(token[i])) { // number
            for (int j = i; isdigit(token[j]); j++) {
                printf("%s %s %c%s\n", CAT_MEOW, CAT_MEOW, token[j], i == length - 1 ? "" : " ");
            }
            i += strlen(token) - (i - 1);
        } else if (strchr("+-*/%<>", token[i])) { // operator
            int k;
            for (k = i; k < length && strchr("+-*/%<>", token[k]); k++) {}
            printf("%s %s %.*s %s\n", CAT_MEOW, CAT_MEOW, k - i, token + i, token + k);
            i = k;
        } else { // identifier or keyword
            if (strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "void") == 0) {
                printf("%s %s %s %s\n", token, CAT_MEOW, CAT_MEOW, CAT_FISH);
            } else {
                printf("%s %s\n", token, CAT_SCRATCH);
            }
        }

        if (token) token = strtok(NULL, " ");
    }

    return 0;
}