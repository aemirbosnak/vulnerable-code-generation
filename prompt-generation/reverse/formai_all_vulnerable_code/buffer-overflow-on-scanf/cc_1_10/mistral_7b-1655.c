//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_URL_LENGTH 256
#define MAX_CHAR 128
typedef struct Stack {
    int top;
    char data[MAX_CHAR];
} Stack;
Stack url_stack;
int is_valid_char(char c) {
    if (isalnum(c) || (c == '.' || c == '/' || c == ':' || c == '~' || c == '?' || c == '&')) {
        return 1;
    }
    return 0;
}
void push(Stack *stack, char c) {
    if (stack->top >= MAX_CHAR - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack->data[stack->top++] = c;
}
char pop(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack->data[--stack->top];
}
void sanitize_url(char *url) {
    int i = 0;
    Stack sanitized_url;
    sanitized_url.top = -1;
    while (url[i] != '\0') {
        if (is_valid_char(url[i])) {
            push(&sanitized_url, url[i]);
        }
        i++;
    }
    int j = 0;
    printf("Sanitized URL: ");
    while (sanitized_url.top >= 0) {
        printf("%c", sanitized_url.data[sanitized_url.top--]);
        j++;
        if (j >= MAX_URL_LENGTH) {
            printf("URL too long!\n");
            exit(1);
        }
    }
    printf("\n");
}
int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitize_url(url);
    return 0;
}