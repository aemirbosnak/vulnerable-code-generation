//FormAI DATASET v1.0 Category: Syntax parsing ; Style: rigorous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int skip_whitespaces(char* prog) {
    while (*prog == ' ' || *prog == '\t') {
        prog++;
    }
    return prog;
}

int parse_int(char* prog) {
    int result = 0;
    while (*prog != '\0' && *prog >= '0' && *prog <= '9') {
        result = result * 10 + (*prog - '0');
        prog++;
    }
    return result;
}

int parse_expr(char* prog) {
    int left = parse_int(prog);

    prog = skip_whitespaces(prog);

    while (*prog != '\0') {
        if (*prog == '+') {
            prog = skip_whitespaces(++prog);
            left += parse_int(prog);
        }
        else if (*prog == '-') {
            prog = skip_whitespaces(++prog);
            left -= parse_int(prog);
        }
        else {
            fprintf(stderr, "Invalid character: %c\n", *prog);
            exit(1);
        }

        prog = skip_whitespaces(prog);
    }
    return left;
}

int main() {
    char prog[1024];

    printf("Enter an expression: ");
    scanf("%[^\n]", prog);

    int result = parse_expr(prog);

    printf("Result: %d\n", result);

    return 0;
}