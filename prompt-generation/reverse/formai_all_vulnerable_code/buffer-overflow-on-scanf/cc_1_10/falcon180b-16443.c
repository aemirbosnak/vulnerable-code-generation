//Falcon-180B DATASET v1.0 Category: Educational ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* next;
};

struct node* create_list(int size) {
    struct node* head = NULL;
    for (int i = 0; i < size; i++) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = NULL;
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
    return head;
}

void print_list(struct node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void delete_list(struct node* head) {
    while (head!= NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    struct node* head = create_list(size);
    print_list(head);
    delete_list(head);
    return 0;
}