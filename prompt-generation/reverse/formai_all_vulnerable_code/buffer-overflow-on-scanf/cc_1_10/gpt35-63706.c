//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

void add_node(node_t **head, int value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

void recover_data(node_t *head) {
    node_t *current = head;
    node_t *prev = NULL;
    node_t *temp;
    while (current != NULL) {
        if (current->value < 0) {
            if (prev == NULL) {
                head = head->next;
                free(current);
                current = head;
            } else {
                prev->next = current->next;
                temp = current->next;
                free(current);
                current = temp;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
    printf("\nRecovered Data: \n");
    print_list(head);
}

int main() {
    node_t *head = NULL;
    int num;
    int count = 0;
    printf("Enter the number of values to be recovered: ");
    scanf("%d", &num);
    printf("Enter the values: \n");
    while (count < num) {
        int value;
        scanf("%d", &value);
        add_node(&head, value);
        count++;
    }
    printf("Original Data: \n");
    print_list(head);
    recover_data(head);
    return 0;
}