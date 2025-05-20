//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* create_list(int size, int* arr) {
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        Node* new_node = create_node(arr[i]);
        if (head == NULL) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    return head;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse_list(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter the elements of the list: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    Node* head = create_list(size, arr);
    print_list(head);

    reverse_list(&head);
    printf("Reversed list: ");
    print_list(head);

    return 0;
}