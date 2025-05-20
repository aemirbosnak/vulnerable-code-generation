//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} node_t;

int main() {
    char str[101];
    node_t *head = NULL, *tail = NULL;
    int i, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    for (i = 0; i < len; i++) {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = str[i];
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    node_t *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node_t *prev = NULL, *next;
    while (slow != NULL) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    tail = prev;
    head = tail;

    int is_palindrome = 1;
    node_t *current = head;
    for (i = 0; i < len; i++) {
        if (current->data != str[i]) {
            is_palindrome = 0;
            break;
        }
        current = current->next;
    }

    if (is_palindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}