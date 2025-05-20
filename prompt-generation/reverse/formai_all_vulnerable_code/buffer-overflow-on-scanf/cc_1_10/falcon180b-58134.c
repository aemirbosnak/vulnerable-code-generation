//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    int freq;
    struct node *next;
} Node;

Node *createNode(int data, int freq) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->next = NULL;
    return newNode;
}

Node *insertNode(Node *head, int data, int freq) {
    Node *newNode = createNode(data, freq);
    Node *temp = head;
    while (temp!= NULL && temp->freq <= freq) {
        temp = temp->next;
    }
    newNode->next = temp;
    return head;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int arr[MAX_SIZE];
    int n, i, j, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        head = insertNode(head, arr[i], rand() % n + 1);
    }

    printf("Sorted array is:\n");
    printList(head);

    return 0;
}