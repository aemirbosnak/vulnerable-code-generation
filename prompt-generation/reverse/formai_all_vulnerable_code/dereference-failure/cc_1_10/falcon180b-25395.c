//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *create_list(int arr[], int n) {
    struct node *head = NULL;
    struct node *temp = NULL;

    for (int i = 0; i < n; i++) {
        temp = (struct node *) malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            struct node *ptr = head;

            while (ptr->next!= NULL) {
                ptr = ptr->next;
            }

            ptr->next = temp;
        }
    }

    return head;
}

void search_element(struct node *head, int key) {
    struct node *temp = head;

    while (temp!= NULL) {
        if (temp->data == key) {
            printf("Element %d found in the list\n", key);
            return;
        }

        temp = temp->next;
    }

    printf("Element %d not found in the list\n", key);
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    struct node *head = create_list(arr, n);
    search_element(head, key);

    return 0;
}