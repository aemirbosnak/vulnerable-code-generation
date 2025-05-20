//FormAI DATASET v1.0 Category: Syntax parsing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// function prototypes
void parse_expression(void);
void parse_term(void);
void parse_factor(void);

int main(void)
{
    // get a C expression from the user
    printf("Enter a C expression: ");
    parse_expression();

    return 0;
}

void parse_expression(void)
{
    parse_term();

    while (1) {
        // get the next character in the input
        int c = getchar();

        if (c == '+') {
            parse_term();
            printf("add\n");
        }
        else if (c == '-') {
            parse_term();
            printf("subtract\n");
        }
        else {
            ungetc(c, stdin);
            break;
        }
    }
}

void parse_term(void)
{
    parse_factor();

    while (1) {
        int c = getchar();

        if (c == '*') {
            parse_factor();
            printf("multiply\n");
        }
        else if (c == '/') {
            parse_factor();
            printf("divide\n");
        }
        else {
            ungetc(c, stdin);
            break;
        }
    }
}

void parse_factor(void)
{
    int c = getchar();

    if (isdigit(c)) {
        ungetc(c, stdin);
        int num;
        scanf("%d", &num);
        printf("push %d\n", num);
    }
    else if (c == '(') {
        parse_expression();
        c = getchar();

        if (c != ')') {
            printf("Error: expected ')'");
            exit(EXIT_FAILURE);
        }
    }
    else {
        printf("Error: expected number or '('");
        exit(EXIT_FAILURE);
    }
}