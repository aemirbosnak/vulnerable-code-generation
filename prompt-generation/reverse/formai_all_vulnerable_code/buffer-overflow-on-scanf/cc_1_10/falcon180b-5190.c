//Falcon-180B DATASET v1.0 Category: Sorting ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int num;
    bool is_sorted;
} Node;

Node* create_node(int num) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->num = num;
    new_node->is_sorted = false;
    return new_node;
}

void print_node(Node* node) {
    printf("%d ", node->num);
}

int compare_nodes(Node* a, Node* b) {
    return a->num - b->num;
}

void bubble_sort(Node** nodes, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (compare_nodes(nodes[j], nodes[j + 1]) > 0) {
                Node* temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
}

void merge_sort(Node** nodes, int size) {
    for (int i = 0; i < size; i++) {
        nodes[i]->is_sorted = true;
    }

    for (int i = 0; i < size - 1; i++) {
        int j = 0;
        while (j < size - i - 1) {
            if (compare_nodes(nodes[j], nodes[j + 1]) > 0) {
                Node* temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
            j++;
        }
    }
}

int main() {
    Node* nodes[MAX_SIZE];
    int size = 0;

    while (size < MAX_SIZE) {
        int num;
        printf("Enter a number (enter -1 to stop): ");
        scanf("%d", &num);
        if (num!= -1) {
            nodes[size] = create_node(num);
            size++;
        }
    }

    bubble_sort(nodes, size);
    printf("Bubble Sort:\n");
    for (int i = 0; i < size; i++) {
        print_node(nodes[i]);
        printf("\n");
    }

    merge_sort(nodes, size);
    printf("Merge Sort:\n");
    for (int i = 0; i < size; i++) {
        print_node(nodes[i]);
        printf("\n");
    }

    return 0;
}