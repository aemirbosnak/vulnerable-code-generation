//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int size) {
    Node* head = NULL;
    Node* current = NULL;
    for (int i = 0; i < size; i++) {
        current = (Node*) malloc(sizeof(Node));
        if (current == NULL) {
            printf("Out of memory\n");
            exit(1);
        }
        current->data = rand() % 1000;
        current->next = NULL;
        if (head == NULL) {
            head = current;
        } else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = current;
        }
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    srand(time(NULL));
    Node* linkedList = createLinkedList(MAX_SIZE);
    printf("Linked List:\n");
    printLinkedList(linkedList);
    deleteLinkedList(linkedList);
    return 0;
}