//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct node {
    int data;
    struct node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void scheduler(Node** head) {
    time_t start = time(NULL);
    int i = 0;
    while (*head) {
        Node* current = *head;
        int executionTime = current->data;
        sleep(executionTime);
        printf("Process %d finished execution.\n", current->data);
        free(current);
        *head = (*head)->next;
        i++;
    }

    time_t end = time(NULL);
    printf("Total time taken: %ld seconds.\n", end - start);
    printf("Number of processes completed: %d\n", i);
}

int main() {
    Node* head = NULL;
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 6);

    scheduler(&head);

    return 0;
}