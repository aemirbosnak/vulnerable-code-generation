//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: introspective
// Unique C Data structures visualization example program

#include <stdio.h>
#include <stdlib.h>

// Linked list data structure
struct node {
    int data;
    struct node* next;
};

// Array data structure
int arr[100];

int main() {
    // Linked list example
    struct node* head = NULL;
    struct node* current = NULL;
    struct node* temp = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    current = head;

    for (int i = 2; i <= 10; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = i;
        temp->next = NULL;

        current->next = temp;
        current = temp;
    }

    printf("Linked list: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Array example
    for (int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }

    printf("Array: ");
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}