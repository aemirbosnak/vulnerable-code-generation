//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 10
#define MAX_ATTRIBUTES 10
#define MAX_ATTRIBUTE_LENGTH 20

typedef struct {
    char name[MAX_ATTRIBUTE_LENGTH];
    char value[MAX_ATTRIBUTE_LENGTH];
} attribute_t;

typedef struct {
    char name[MAX_ATTRIBUTE_LENGTH];
    attribute_t attributes[MAX_ATTRIBUTES];
    int num_attributes;
    char value[MAX_ATTRIBUTE_LENGTH];
    int depth;
} element_t;

typedef struct {
    element_t stack[MAX_DEPTH];
    int top;
} stack_t;

void push(stack_t* s, element_t e) {
    if (s->top < MAX_DEPTH) {
        s->stack[s->top++] = e;
    }
    else {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

element_t pop(stack_t* s) {
    if (s->top > 0) {
        return s->stack[--s->top];
    }
    else {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    stack_t s;
    s.top = 0;
    element_t e;
    char buffer[MAX_ATTRIBUTE_LENGTH];
    char c;
    FILE* fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: cannot open file\n");
        exit(EXIT_FAILURE);
    }
    while ((c = getc(fp)) != EOF) {
        if (c == '<') {
            if (fgets(buffer, sizeof(buffer), fp)) {
                sscanf(buffer, "%s", e.name);
                e.num_attributes = 0;
                while (sscanf(buffer, "%s=\"%s\"", e.attributes[e.num_attributes].name, e.attributes[e.num_attributes].value) == 2) {
                    e.num_attributes++;
                }
                e.value[0] = '\0';
                e.depth = s.top;
                push(&s, e);
            }
        }
        else if (c == '>') {
            element_t parent = pop(&s);
            element_t child = pop(&s);
            if (strcmp(parent.name, child.name) != 0) {
                printf("Error: tag mismatch\n");
                exit(EXIT_FAILURE);
            }
            parent.value[0] = '\0';
            for (int i = 0; i < parent.num_attributes; i++) {
                if (strcmp(parent.attributes[i].name, "value") == 0) {
                    strncpy(parent.value, parent.attributes[i].value, sizeof(parent.value));
                    parent.value[sizeof(parent.value)-1] = '\0';
                    break;
                }
            }
            if (parent.depth == 0) {
                printf("Found top-level element %s with value %s\n", parent.name, parent.value);
            }
            else {
                push(&s, parent);
            }
        }
        else {
            element_t e = pop(&s);
            strncat(e.value, &c, 1);
            push(&s, e);
        }
    }
    fclose(fp);
    return 0;
}