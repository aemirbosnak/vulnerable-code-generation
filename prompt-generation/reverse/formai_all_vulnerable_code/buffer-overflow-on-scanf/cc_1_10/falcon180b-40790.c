//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *create_list(int n) {
    struct node *head = (struct node *) malloc(sizeof(struct node));
    struct node *tail = head;
    int i;

    for (i = 0; i < n; i++) {
        tail->data = i;
        tail->next = (struct node *) malloc(sizeof(struct node));
        tail = tail->next;
    }

    tail->next = NULL;

    return head;
}

void print_list(struct node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);

    printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod);

    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n, choice, i;
    struct node *head = NULL;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    head = create_list(n);
    print_list(head);

    printf("\nEnter 1 to solve the Tower of Hanoi problem\n");
    scanf("%d", &choice);

    if (choice == 1) {
        tower_of_hanoi(n, 'A', 'C', 'B');
    } else {
        printf("Invalid choice!");
    }

    return 0;
}