//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

bool is_palindrome_helper(Node *left, Node *right) {
    if (left == NULL)
        return right == NULL;

    if (left->data != right->data)
        return false;

    return is_palindrome_helper(left->next, right->next);
}

bool is_palindrome(const char *input) {
    size_t length = strlen(input);
    Node *left = NULL, *right = NULL;

    // Create two linked lists for the input string, one for checking left side and another for checking right side.
    for (size_t i = 0; i < length / 2; i++) {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = input[i];
        new_node->next = left;
        left = new_node;

        new_node = malloc(sizeof(Node));
        new_node->data = input[length - i - 1];
        new_node->next = right;
        right = new_node;
    }

    // Check if the input string is a palindrome.
    bool result = is_palindrome_helper(left, right);

    // Free the memory allocated for the linked lists.
    while (left != NULL) {
        Node *temp = left;
        left = left->next;
        free(temp);
    }

    while (right != NULL) {
        Node *temp = right;
        right = right->next;
        free(temp);
    }

    return result;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (is_palindrome(input))
        printf("The given string is a palindrome.\n");
    else
        printf("The given string is not a palindrome.\n");

    return 0;
}