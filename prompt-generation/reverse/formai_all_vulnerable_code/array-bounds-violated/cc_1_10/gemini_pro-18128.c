//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

struct expr {
    int type;
    union {
        int value;
        struct expr *left;
        struct expr *right;
    };
};

enum expr_type {
    EXPR_VALUE,
    EXPR_PLUS,
    EXPR_MINUS,
    EXPR_MUL,
    EXPR_DIV
};

struct expr *parse_expr(char *line);
int eval_expr(struct expr *expr);
void print_expr(struct expr *expr);
void free_expr(struct expr *expr);

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    struct expr *expr;
    int result;

    while (1) {
        printf("$ ");
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        line[strlen(line) - 1] = '\0'; // Remove newline character

        expr = parse_expr(line);
        if (expr == NULL) {
            printf("Error parsing expression\n");
            continue;
        }

        result = eval_expr(expr);
        printf("%d\n", result);

        free_expr(expr);
    }

    return 0;
}

struct expr *parse_expr(char *line) {
    struct expr *expr;
    char *token;

    expr = malloc(sizeof(struct expr));
    if (expr == NULL) {
        return NULL;
    }

    token = strtok(line, " ");
    if (token == NULL) {
        free(expr);
        return NULL;
    }

    if (strcmp(token, "+") == 0) {
        expr->type = EXPR_PLUS;
        expr->left = parse_expr(NULL);
        expr->right = parse_expr(NULL);
    } else if (strcmp(token, "-") == 0) {
        expr->type = EXPR_MINUS;
        expr->left = parse_expr(NULL);
        expr->right = parse_expr(NULL);
    } else if (strcmp(token, "*") == 0) {
        expr->type = EXPR_MUL;
        expr->left = parse_expr(NULL);
        expr->right = parse_expr(NULL);
    } else if (strcmp(token, "/") == 0) {
        expr->type = EXPR_DIV;
        expr->left = parse_expr(NULL);
        expr->right = parse_expr(NULL);
    } else {
        expr->type = EXPR_VALUE;
        expr->value = atoi(token);
    }

    return expr;
}

int eval_expr(struct expr *expr) {
    int result;

    switch (expr->type) {
    case EXPR_VALUE:
        result = expr->value;
        break;
    case EXPR_PLUS:
        result = eval_expr(expr->left) + eval_expr(expr->right);
        break;
    case EXPR_MINUS:
        result = eval_expr(expr->left) - eval_expr(expr->right);
        break;
    case EXPR_MUL:
        result = eval_expr(expr->left) * eval_expr(expr->right);
        break;
    case EXPR_DIV:
        result = eval_expr(expr->left) / eval_expr(expr->right);
        break;
    }

    return result;
}

void print_expr(struct expr *expr) {
    switch (expr->type) {
    case EXPR_VALUE:
        printf("%d", expr->value);
        break;
    case EXPR_PLUS:
        printf("(");
        print_expr(expr->left);
        printf(" + ");
        print_expr(expr->right);
        printf(")");
        break;
    case EXPR_MINUS:
        printf("(");
        print_expr(expr->left);
        printf(" - ");
        print_expr(expr->right);
        printf(")");
        break;
    case EXPR_MUL:
        printf("(");
        print_expr(expr->left);
        printf(" * ");
        print_expr(expr->right);
        printf(")");
        break;
    case EXPR_DIV:
        printf("(");
        print_expr(expr->left);
        printf(" / ");
        print_expr(expr->right);
        printf(")");
        break;
    }
}

void free_expr(struct expr *expr) {
    switch (expr->type) {
    case EXPR_PLUS:
    case EXPR_MINUS:
    case EXPR_MUL:
    case EXPR_DIV:
        free_expr(expr->left);
        free_expr(expr->right);
        break;
    }

    free(expr);
}