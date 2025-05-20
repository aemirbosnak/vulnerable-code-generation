//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};

struct node* create_node(int val){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->value = val;
    node->next = NULL;
    return node;
}

struct node* insert_node(struct node* head, int val) {
    struct node* new_node = create_node(val);
    if (head == NULL)
        return new_node;
    struct node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    return head;
}

struct node* delete_node(struct node* head, int val) {
    if (head == NULL)
        return NULL;
    if (head->value == val) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node* curr = head;
    struct node* prev = NULL;
    while (curr != NULL && curr->value != val) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
        return head;
    prev->next = curr->next;
    free(curr);
    return head;
}

void print_list(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int choice = 0;
    int val = 0;
    do {
        printf("\n1. Insert\n2. Delete\n3. Print\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insert_node(head, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                head = delete_node(head, val);
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}