//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

void init(struct LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

void push(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

int pop(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        exit(1);
    }
    struct Node* temp = list->head;
    int data = temp->data;
    list->head = temp->next;
    free(temp);
    list->size--;
    return data;
}

int peek(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        exit(1);
    }
    return list->head->data;
}

int isEmpty(struct LinkedList* list) {
    return list->head == NULL;
}

int size(struct LinkedList* list) {
    return list->size;
}

void display(struct LinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = list->head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse(struct LinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* curr = list->head;
    while (curr!= NULL) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

int main() {
    struct LinkedList list;
    init(&list);
    push(&list, 10);
    push(&list, 20);
    push(&list, 30);
    push(&list, 40);
    push(&list, 50);
    display(&list);
    printf("Size: %d\n", size(&list));
    reverse(&list);
    display(&list);
    printf("Size: %d\n", size(&list));
    while (!isEmpty(&list)) {
        int data = pop(&list);
        printf("Popped: %d\n", data);
    }
    printf("Size: %d\n", size(&list));
    return 0;
}