//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node *next;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(node** head, int data) {
    node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int dequeue(node** head) {
    if (*head == NULL) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    node* temp = *head;
    *head = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

void print_queue(node* head) {
    if (head == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        while (head!= NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

void destroy_queue(node** head) {
    node* temp = *head;
    while (temp!= NULL) {
        temp = temp->next;
        *head = temp;
        free(temp);
    }
}

int main() {
    node* queue = NULL;
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    print_queue(queue);
    int dequeued_data = dequeue(&queue);
    printf("Dequeued data: %d\n", dequeued_data);
    print_queue(queue);
    destroy_queue(&queue);
    return 0;
}