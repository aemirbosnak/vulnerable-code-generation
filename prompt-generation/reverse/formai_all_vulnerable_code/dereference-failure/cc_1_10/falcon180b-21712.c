//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list structure definition
typedef struct {
    Node* head;
    int size;
} LinkedList;

// Function prototypes
LinkedList* createLinkedList();
void destroyLinkedList(LinkedList* list);
void addNode(LinkedList* list, int data);
bool removeNode(LinkedList* list, int data);
void printList(LinkedList* list);

int main() {
    LinkedList* myList = createLinkedList();

    addNode(myList, 10);
    addNode(myList, 20);
    addNode(myList, 30);

    printList(myList);

    removeNode(myList, 20);

    printList(myList);

    destroyLinkedList(myList);

    return 0;
}

// Function definitions
LinkedList* createLinkedList() {
    LinkedList* newList = (LinkedList*) malloc(sizeof(LinkedList));
    if (newList == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

void destroyLinkedList(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        list->head = list->head->next;
        free(temp);
        temp = list->head;
    }
    free(list);
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    list->size++;
}

bool removeNode(LinkedList* list, int data) {
    Node* prev = NULL;
    Node* curr = list->head;

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return false;
    }

    if (prev == NULL) {
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
    list->size--;

    return true;
}

void printList(LinkedList* list) {
    Node* curr = list->head;
    printf("List: ");
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}