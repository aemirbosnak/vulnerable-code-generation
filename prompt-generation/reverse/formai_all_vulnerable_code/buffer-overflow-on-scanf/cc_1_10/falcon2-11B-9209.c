//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define SUCCESS 0
#define FAILURE 1

typedef struct {
    int value;
    int next;
} Node;

int search(int value, Node* head, int size) {
    if (head == NULL)
        return FAILURE;
    else if (head->value == value)
        return SUCCESS;
    else
        return search(value, head->next, size);
}

void insert(int value, Node* head, int* size) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    temp->value = value;
    temp->next = NULL;

    if (*size == MAX_SIZE) {
        printf("Memory is full.\n");
        return;
    }
    if (head == NULL) {
        head = temp;
        (*size)++;
        return;
    }
    Node* ptr = head;
    while (ptr->next!= NULL)
        ptr = ptr->next;
    ptr->next = temp;
    (*size)++;
}

void display(Node* head, int* size) {
    Node* ptr = head;
    while (ptr!= NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int size = 0;
    int value;
    while (1) {
        printf("Enter a value or -1 to exit: ");
        scanf("%d", &value);
        if (value == -1)
            break;
        if (search(value, head, size) == FAILURE)
            insert(value, head, &size);
        display(head, &size);
    }
    return 0;
}