//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define MIN_VALUE -1000000
#define MAX_VALUE 1000000

typedef struct {
    int num;
    struct Node *next;
} Node;

Node *head = NULL;

void createList(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->num = array[i];
        newNode->next = head;
        head = newNode;
    }
}

void printList() {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}

void reverseList() {
    Node *current = head;
    Node *previous = NULL;
    Node *next;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

void addLists(Node *list1, Node *list2, Node **sum) {
    Node *carry = NULL;
    Node *sumHead = NULL;
    Node *current1 = list1;
    Node *current2 = list2;
    int addend;

    while (current1 != NULL || current2 != NULL) {
        addend = (current1 != NULL) ? current1->num : 0;
        addend += (current2 != NULL) ? current2->num : 0;

        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->num = addend % 10;
        newNode->next = sumHead;
        sumHead = newNode;

        carry = addend / 10;
        current1 = (current1 != NULL) ? current1->next : NULL;
        current2 = (current2 != NULL) ? current2->next : NULL;
    }

    if (carry != 0) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->num = carry;
        newNode->next = sumHead;
        sumHead = newNode;
    }

    *sum = sumHead;
}

void freeList(Node *list) {
    Node *current = list;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int size1 = 5;
    int size2 = 5;
    int array1[MAX_SIZE] = {0};
    int array2[MAX_SIZE] = {0};
    int i;

    printf("Enter the elements for list 1:\n");
    for (i = 0; i < size1; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Enter the elements for list 2:\n");
    for (i = 0; i < size2; i++) {
        scanf("%d", &array2[i]);
    }

    createList(array1, size1);
    createList(array2, size2);

    printf("List 1: ");
    printList();

    printf("List 2: ");
    printList();

    Node *sumList = NULL;
    addLists(head, head, &sumList);

    printf("Sum: ");
    printList();

    reverseList();

    printf("Reversed Sum: ");
    printList();

    freeList(head);
    freeList(sumList);

    return 0;
}