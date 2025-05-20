//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int next;
} Node;

Node *head = NULL;

void createList(int size) {
    Node *current = NULL;
    for (int i = 0; i < size; i++) {
        current = (Node*)malloc(sizeof(Node));
        if (current == NULL) {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
        current->data = i;
        current->next = NULL;
        if (head == NULL) {
            head = current;
        } else {
            Node *temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = current;
        }
    }
}

void deleteList() {
    Node *current = head;
    while (current!= NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

void printList() {
    Node *current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    createList(size);
    printList();
    deleteList();
    return 0;
}