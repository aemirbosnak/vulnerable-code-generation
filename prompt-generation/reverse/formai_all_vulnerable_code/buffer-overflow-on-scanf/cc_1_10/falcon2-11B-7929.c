//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node* insert_at_head(struct node* list, int data) {
    struct node* new_node = create_node(data);
    new_node->next = list;
    return new_node;
}

void print_list(struct node* list) {
    while (list!= NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int data;

    printf("Enter the number of nodes: ");
    scanf("%d", &data);

    for (int i = 1; i <= data; i++) {
        struct node* new_node = create_node(i);
        if (head == NULL) {
            head = new_node;
        } else {
            struct node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    printf("Linked List: ");
    print_list(head);

    return 0;
}