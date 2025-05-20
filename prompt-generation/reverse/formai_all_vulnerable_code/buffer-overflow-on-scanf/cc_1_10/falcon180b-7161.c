//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

typedef struct {
    int data;
    int index;
} node_t;

node_t arr[SIZE];
int count = 0;

void insert(int data) {
    if (count == SIZE) {
        printf("Array is full\n");
        return;
    }
    int index = rand() % SIZE;
    while (arr[index].data!= -1) {
        index = rand() % SIZE;
    }
    arr[index].data = data;
    arr[index].index = index;
    count++;
}

void search(int data) {
    int index = rand() % SIZE;
    node_t *curr_node = &arr[index];
    while (curr_node->data!= -1) {
        if (curr_node->data == data) {
            printf("Element found at index %d\n", curr_node->index);
            return;
        }
        curr_node = &arr[rand() % SIZE];
    }
    printf("Element not found\n");
}

void delete(int data) {
    int index = rand() % SIZE;
    node_t *curr_node = &arr[index];
    while (curr_node->data!= -1) {
        if (curr_node->data == data) {
            curr_node->data = -1;
            count--;
            printf("Element deleted at index %d\n", curr_node->index);
            return;
        }
        curr_node = &arr[rand() % SIZE];
    }
    printf("Element not found\n");
}

int main() {
    srand(time(NULL));
    int choice, data;
    while (1) {
        printf("1. Insert\n2. Search\n3. Delete\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}