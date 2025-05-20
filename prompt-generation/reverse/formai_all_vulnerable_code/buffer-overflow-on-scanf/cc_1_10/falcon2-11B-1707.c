//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct node {
    int id;
    int value;
    int next;
} node;

node nodes[MAX_NODES];
int head = 0;
int tail = 0;

void insert(int value) {
    if (tail == MAX_NODES - 1) {
        printf("List is full, cannot insert\n");
        return;
    }
    nodes[tail].next = head;
    nodes[head].id = tail;
    head++;
    tail++;
    nodes[tail].value = value;
}

void delete(int index) {
    if (index < 0 || index >= MAX_NODES) {
        printf("Index out of range\n");
        return;
    }
    if (index == 0) {
        head = index + 1;
    } else if (index == tail - 1) {
        tail = index - 1;
    } else {
        nodes[index].next = index + 1;
    }
}

void traverse() {
    int i = head;
    while (i!= tail) {
        printf("%d ", nodes[i].value);
        i = nodes[i].next;
    }
    printf("\n");
}

int main() {
    int choice, value, index;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                delete(index);
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}