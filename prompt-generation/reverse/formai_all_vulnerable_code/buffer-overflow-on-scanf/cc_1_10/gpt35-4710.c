//FormAI DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    int size;
    Node* head;
} List;

void insert(List* list, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void delete(List* list, int data) {
    Node* curr = list->head;
    Node* prev = NULL;
    while(curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if(curr != NULL) {
        if(prev == NULL) {
            list->head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
        list->size--;
    }
}

void display(List* list) {
    if(list->size == 0) {
        printf("The list is empty!\n");
        return;
    }
    Node* curr = list->head;
    while(curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    List list;
    list.size = 0;
    list.head = NULL;
    int choice, data;
    printf("Welcome to Linked List Visualizer!\n");
    printf("----------------------------------\n");
    while(1) {
        printf("Choose an option:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(&list, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                delete(&list, data);
                break;
            case 3:
                display(&list);
                break;
            case 4:
                printf("Thank you for using Linked List Visualizer!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}