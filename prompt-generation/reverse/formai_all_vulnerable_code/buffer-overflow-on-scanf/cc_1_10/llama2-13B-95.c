//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STACK_SIZE 100

typedef struct {
    char *line;
    int len;
} stack_t;

void push(stack_t *stack, char *line) {
    if (stack->len + strlen(line) > MAX_STACK_SIZE) {
        printf("Stack overflow! :O\n");
        exit(1);
    }
    stack->line = realloc(stack->line, sizeof(char) * (stack->len + strlen(line)));
    memcpy(stack->line + stack->len, line, strlen(line));
    stack->len += strlen(line);
}

char *pop(stack_t *stack) {
    if (stack->len == 0) {
        printf("Stack underflow! :O\n");
        exit(1);
    }
    char *ret = stack->line;
    stack->line = stack->line + strlen(ret);
    stack->len -= strlen(ret);
    return ret;
}

int main() {
    stack_t stack;
    stack.line = malloc(MAX_LINE_LENGTH);
    stack.len = 0;

    char *line;
    while (scanf("%s", &line) == 1) {
        push(&stack, line);
    }

    char *ret = NULL;
    while ((ret = pop(&stack)) != NULL) {
        printf("%s\n", ret);
    }

    free(stack.line);
    return 0;
}