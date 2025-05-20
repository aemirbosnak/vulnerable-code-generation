//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

void deleteNode(LinkedList* list, int data) {
    Node* current = list->head;

    if (current!= NULL && current->data == data) {
        list->head = current->next;
        free(current);
        list->size--;
        return;
    }

    while (current!= NULL && current->data!= data) {
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    current->next = current->next->next;
    free(current->next);
    list->size--;
}

void printList(LinkedList* list) {
    Node* current = list->head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    LinkedList* list = createLinkedList();
    int choice, data;

    while (1) {
        printf("\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(list, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(list, data);
                break;
            case 3:
                printList(list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}