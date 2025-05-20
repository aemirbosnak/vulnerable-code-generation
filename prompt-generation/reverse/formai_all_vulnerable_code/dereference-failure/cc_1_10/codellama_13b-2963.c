//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
// Bucket Sort implementation in C
// By Linus Torvalds

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 100

typedef struct {
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void insert(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int get_bucket(int data) {
    return data % MAX_BUCKETS;
}

void bucket_sort(node *head) {
    node *curr = head;
    node *next = NULL;
    node *bucket[MAX_BUCKETS];

    for (int i = 0; i < MAX_BUCKETS; i++) {
        bucket[i] = NULL;
    }

    while (curr != NULL) {
        next = curr->next;
        int bucket_index = get_bucket(curr->data);
        if (bucket[bucket_index] == NULL) {
            bucket[bucket_index] = curr;
        } else {
            node *temp = bucket[bucket_index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = curr;
        }
        curr = next;
    }

    for (int i = 0; i < MAX_BUCKETS; i++) {
        if (bucket[i] != NULL) {
            node *temp = bucket[i];
            while (temp != NULL) {
                printf("%d ", temp->data);
                temp = temp->next;
            }
        }
    }
}

int main() {
    insert(3);
    insert(2);
    insert(4);
    insert(1);
    insert(5);

    printf("Before sorting: ");
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    bucket_sort(head);

    printf("\nAfter sorting: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}