//Falcon-180B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node *next;
};

struct node *create_list(int size) {
    struct node *head = NULL;
    int i;

    for (i = 0; i < size; i++) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory error\n");
            exit(1);
        }
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }

    return head;
}

void print_list(struct node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void free_list(struct node *head) {
    struct node *temp;

    while (head!= NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    struct node *head = create_list(size);
    printf("Created list:\n");
    print_list(head);

    free_list(head);
    printf("\nList freed\n");

    return 0;
}