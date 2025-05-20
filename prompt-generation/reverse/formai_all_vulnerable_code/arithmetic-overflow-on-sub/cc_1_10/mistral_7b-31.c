//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* addToList(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

int sumRecursive(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumRecursive(n - 1);
}

int main() {
    int n, i;
    printf("Enter the number of natural numbers to sum: ");
    scanf("%d", &n);

    Node* numberList = NULL;
    for (i = 0; i < n; i++) {
        numberList = addToList(numberList, i + 1);
    }

    Node* current = numberList;
    int sum = 0;

    printf("\nThe sum of the first %d natural numbers using recursion:\n", n);
    if (n == 0) {
        printf("0\n");
    } else if (n == 1) {
        printf("1\n");
    } else {
        sum = current->data;
        current = current->next;
        sum += sumRecursive(n - 1);
        printf("%d\n", sum);
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    while (numberList != NULL) {
        Node* temp = numberList;
        numberList = numberList->next;
        free(temp);
    }

    return 0;
}