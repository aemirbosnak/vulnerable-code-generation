//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print_puzzle(struct node* head) {
    struct node* current = head;

    while (current!= NULL) {
        if (current->data % 3 == 0) {
            printf("I love this number!\n");
        } else if (current->data % 5 == 0) {
            printf("This number is also nice.\n");
        } else {
            printf("Meh.\n");
        }
        current = current->next;
    }
}

int main() {
    struct node* head = NULL;
    struct node* current = NULL;
    int data;

    while (1) {
        printf("Enter an integer or -1 to exit: ");
        scanf("%d", &data);

        if (data == -1) {
            break;
        }

        current = malloc(sizeof(struct node));
        current->data = data;
        current->next = NULL;

        if (head == NULL) {
            head = current;
        } else {
            current->next = head;
            head = current;
        }
    }

    print_puzzle(head);

    return 0;
}