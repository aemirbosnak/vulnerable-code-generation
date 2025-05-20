//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100
#define STRING_LENGTH 50

typedef struct {
    char str[STRING_LENGTH];
    int len;
    struct node *next;
} node_t;

node_t *string_stack = NULL;
int top = -1;

void push_string(char *str) {
    if (top >= MAX_STRINGS) {
        printf("Error: Stack overflow!\n");
        exit(EXIT_FAILURE);
    }

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Out of memory!\n");
        exit(EXIT_FAILURE);
    }

    strncpy(new_node->str, str, STRING_LENGTH);
    new_node->len = strlen(str);
    new_node->next = string_stack;
    string_stack = new_node;
    top++;
}

char *pop_string() {
    if (top < 0) {
        printf("Error: Stack underflow!\n");
        exit(EXIT_FAILURE);
    }

    node_t *old_node = string_stack;
    string_stack = old_node->next;
    top--;

    return old_node->str;
}

int main() {
    char input[STRING_LENGTH];
    int command;

    while (1) {
        printf("\nMemory Stack Program\n");
        printf("1. Push a string onto the stack\n");
        printf("2. Pop a string from the stack\n");
        printf("3. Exit\n");
        printf("Enter your command: ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                printf("Enter a string to push onto the stack: ");
                scanf("%s", input);
                push_string(input);
                break;

            case 2:
                if (top >= 0) {
                    char popped_str[STRING_LENGTH];
                    strcpy(popped_str, pop_string());
                    printf("String popped from stack: %s\n", popped_str);
                } else {
                    printf("Error: Stack is empty!\n");
                }
                break;

            case 3:
                while (top >= 0) {
                    char popped_str[STRING_LENGTH];
                    strcpy(popped_str, pop_string());
                    free(string_stack);
                    string_stack = NULL;
                    top = -1;
                }
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid command!\n");
                break;
        }
    }

    return 0;
}