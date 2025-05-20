//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// define linked list structure
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to add a node at the end of the list
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    Node* temp = list->head;
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// function to print the list
void printList(LinkedList* list) {
    Node* temp = list->head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// function to add two lists
void addLists(LinkedList* list1, LinkedList* list2) {
    Node* temp1 = list1->head;
    Node* temp2 = list2->head;
    int carry = 0;
    while (temp1!= NULL || temp2!= NULL || carry!= 0) {
        int sum = (temp1!= NULL? temp1->data : 0) + (temp2!= NULL? temp2->data : 0) + carry;
        carry = sum / 10;
        addNode(list1, sum % 10);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

// main function
int main() {
    LinkedList list1, list2, result;
    list1.head = NULL;
    list2.head = NULL;
    result.head = NULL;

    addNode(&list1, 123);
    addNode(&list1, 456);
    addNode(&list2, 789);

    printf("List 1: ");
    printList(&list1);
    printf("List 2: ");
    printList(&list2);

    addLists(&list1, &list2);

    printf("Result: ");
    printList(&result);

    return 0;
}