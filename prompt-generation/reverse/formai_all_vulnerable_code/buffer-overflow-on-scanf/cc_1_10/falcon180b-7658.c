//Falcon-180B DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100
#define MIN_SIZE 2

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void add_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error! ");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list() {
    if (head == NULL) {
        printf("List is empty! ");
        return;
    }
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int size, i;
    printf("Enter the size of the list (between %d and %d): ", MIN_SIZE, MAX_SIZE);
    scanf("%d", &size);
    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Invalid size! ");
        return 0;
    }
    for (i = 1; i <= size; i++) {
        add_node(i);
    }
    printf("List: ");
    print_list();
    return 0;
}