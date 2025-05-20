//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int value;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_node(int val) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->value = val;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node_t *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list() {
    node_t *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void delete_node(int val) {
    node_t *temp = head;
    node_t *prev = NULL;
    while (temp!= NULL && temp->value!= val) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node not found\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

int main() {
    int choice, val;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Delete node\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value of the node to be added:\n");
                scanf("%d", &val);
                add_node(val);
                break;
            case 2:
                print_list();
                break;
            case 3:
                printf("Enter the value of the node to be deleted:\n");
                scanf("%d", &val);
                delete_node(val);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}