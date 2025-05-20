//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertNode(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void traverseList(Node* head) {
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    time_t start, end;
    start = time(NULL);

    Node* head = NULL;
    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'c');
    insertNode(&head, 'd');
    insertNode(&head, 'e');

    traverseList(head);

    end = time(NULL);
    printf("Time taken: %ld seconds\n", end - start);

    return 0;
}