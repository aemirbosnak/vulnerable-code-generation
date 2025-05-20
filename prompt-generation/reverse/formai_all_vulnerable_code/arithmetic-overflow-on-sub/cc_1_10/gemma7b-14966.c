//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void Insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void PrintList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void CPU_Scheduling(Node* head) {
    time_t start_time, end_time;
    int i = 0, total_time = 0, current_process = 0;

    start_time = time(NULL);

    while (!head->next) {
        // Calculate the execution time for the process
        int execution_time = rand() % MAX;

        // Update the process's completion time
        head->data += execution_time;

        // Increment the total time
        total_time += execution_time;

        // Move to the next process
        head = head->next;
    }

    end_time = time(NULL);

    printf("Total time: %d seconds\n", end_time - start_time);
    printf("Total time spent on processes: %d seconds\n", total_time);
    printf("Average execution time: %.2f seconds\n", (double)total_time / i);

    PrintList(head);
}

int main() {
    Node* head = NULL;

    // Insert processes into the linked list
    Insert(&head, 10);
    Insert(&head, 20);
    Insert(&head, 30);
    Insert(&head, 40);
    Insert(&head, 50);

    CPU_Scheduling(head);

    return 0;
}