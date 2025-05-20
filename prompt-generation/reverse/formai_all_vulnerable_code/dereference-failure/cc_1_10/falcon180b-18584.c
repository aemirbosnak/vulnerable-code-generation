//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: modular
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** head_ref, int new_data);
void print_list(struct node* node);
void delete_node(struct node **head_ref, int key);
void search(struct node* head, int x);

int main() {
    struct node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);

    printf("Created Linked List: ");
    print_list(head);

    search(head, 5);

    printf("\nList after deleting 5: ");
    print_list(head);

    return 0;
}

void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void delete_node(struct node **head_ref, int key) {
    struct node* temp = *head_ref, *prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void search(struct node* head, int x) {
    struct node* current = head;

    while (current!= NULL) {
        if (current->data == x) {
            printf("%d found\n", x);
            return;
        }
        current = current->next;
    }

    printf("%d not found\n", x);
}