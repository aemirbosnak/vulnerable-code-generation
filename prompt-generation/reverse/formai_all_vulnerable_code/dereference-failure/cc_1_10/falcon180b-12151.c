//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int size) {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory Error!\n");
        exit(0);
    }
    head->data = 0;
    head->next = NULL;
    Node* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = (Node*)malloc(sizeof(Node));
        if (curr->next == NULL) {
            printf("Memory Error!\n");
            exit(0);
        }
        curr = curr->next;
        curr->data = i;
        curr->next = NULL;
    }
    return head;
}

void printLinkedList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteLinkedList(Node* head) {
    while (head!= NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* list = createLinkedList(MAX_SIZE);
    printf("Linked List Created:\n");
    printLinkedList(list);

    printf("Deleting Linked List...\n");
    deleteLinkedList(list);

    printf("Linked List Deleted!\n");
    return 0;
}