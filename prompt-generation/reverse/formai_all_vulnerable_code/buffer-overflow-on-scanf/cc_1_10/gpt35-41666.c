//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_keyword(char *word) {
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for",
                             "goto", "if", "int", "long", "register", "return", "short",
                             "signed", "sizeof", "static", "struct", "switch", "typedef",
                             "union", "unsigned", "void", "volatile", "while"};
    int i;
    for (i = 0; i < 32; i++) {
        if (strcmp(keywords[i], word) == 0) {
            return true;
        }
    }
    return false;
}

bool is_operator(char c) {
    char operators[] = "+-*/%=";
    int i;
    for (i = 0; i < strlen(operators); i++) {
        if (c == operators[i]) {
            return true;
        }
    }
    return false;
}

bool is_separator(char c) {
    char separators[] = ",;(){}[]";
    int i;
    for (i = 0; i < strlen(separators); i++) {
        if (c == separators[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter the name of the file to parse: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[1000];
    int index = 0, line_number = 1;
    char c = fgetc(file);
    while (c != EOF) {
        if (c == '\n') {
            line_number++;
        }
        if (is_operator(c) || is_separator(c)) {
            printf("(%c, %d, operator)\n", c, line_number);
        } else if (c == '#') {
            printf("(%c, %d, preprocessor directive)\n", c, line_number);
            while (c != '\n') {
                c = fgetc(file);
            }
            line_number++;
            continue;
        } else if (c == '\"') {
            printf("(%c, %d, string literal)\n", c, line_number);
            do {
                c = fgetc(file);
            } while (c != '\"');
        } else if (isdigit(c)) {
            printf("(%c, %d, integer literal)\n", c, line_number);
            while (isdigit(c)) {
                c = fgetc(file);
            }
            continue;
        } else if (isalpha(c)) {
            buffer[index++] = c;
            while (isalpha(c = fgetc(file))) {
                buffer[index++] = c;
            }
            buffer[index] = '\0';
            index = 0;
            if (is_keyword(buffer)) {
                printf("(%s, %d, keyword)\n", buffer, line_number);
            } else {
                printf("(%s, %d, identifier)\n", buffer, line_number);
            }
            continue;
        }
        c = fgetc(file);
    }

    fclose(file);
    return 0;
}