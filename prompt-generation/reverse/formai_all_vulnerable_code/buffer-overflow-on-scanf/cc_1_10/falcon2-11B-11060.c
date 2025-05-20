//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int data;
    struct node *next;
} node;

void display(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        node *temp = head;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    node *head = NULL;
    node *curr = NULL;
    int data, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        data = rand() % 100;

        if (head == NULL) {
            head = (node *)malloc(sizeof(node));
            head->data = data;
            head->next = NULL;
        } else {
            curr = head;
            while (curr->next!= NULL) {
                curr = curr->next;
            }
            node *temp = (node *)malloc(sizeof(node));
            temp->data = data;
            temp->next = NULL;
            curr->next = temp;
        }
    }

    display(head);
    return 0;
}