//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

void initList(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

void addNode(LinkedList *list, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    list->size++;
}

void printList(LinkedList *list) {
    Node *temp = list->head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(LinkedList *list) {
    Node *temp = list->head;
    while (temp!= NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
    list->size = 0;
}

int main() {
    int i, choice, data;
    char ch;
    LinkedList list;

    initList(&list);

    while (1) {
        printf("1. Add node\n2. Print list\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&list, data);
                break;
            case 2:
                printList(&list);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}