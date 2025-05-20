//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NR 5

typedef struct node {
    int prio;
    struct node* next;
} node;

void schedule() {
    node* head = NULL;
    node* tail = NULL;
    node* current = NULL;

    // Insert process into priority queue
    while (1) {
        int prio;
        printf("Enter process priority (1-5): ");
        scanf("%d", &prio);

        node* newNode = malloc(sizeof(node));
        newNode->prio = prio;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Round robin scheduling
    current = head;
    while (current) {
        printf("Process %d is running...\n", current->prio);
        sleep(current->prio);
        current = current->next;
    }

    // Free memory
    free(head);
}

int main() {
    schedule();
    return 0;
}