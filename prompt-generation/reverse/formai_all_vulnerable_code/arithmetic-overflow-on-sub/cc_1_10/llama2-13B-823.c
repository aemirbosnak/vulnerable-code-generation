//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition of the struct for the data to be searched
struct node {
    int key;
    int value;
    struct node* next;
};

// Function to perform a linear search on an array of struct nodes
int linear_search(struct node* arr, int key) {
    int i = 0;
    while (arr->next != NULL) {
        if (arr->next->key == key) {
            return i; // return the index of the found element
        }
        arr = arr->next;
        i++;
    }
    return -1; // return -1 if the element is not found
}

// Function to perform a recursive search on a linked list
int recursive_search(struct node* head, int key) {
    if (head == NULL) {
        return -1;
    }
    if (head->key == key) {
        return 0; // return the index of the found element
    }
    int result = recursive_search(head->next, key);
    if (result != -1) {
        return result;
    }
    return -1;
}

// Function to perform a randomized search on a linked list
int randomized_search(struct node* head, int key) {
    int i = rand() % (head->next == NULL ? 0 : 1);
    if (i == 0) {
        return linear_search(head, key);
    } else {
        return recursive_search(head, key);
    }
}

// Function to perform a search on a linked list
int search(struct node* head, int key) {
    clock_t start = clock();
    int result = randomized_search(head, key);
    clock_t end = clock();
    printf("Search took %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return result;
}

int main() {
    struct node* head = NULL;
    struct node* node1 = NULL;
    struct node* node2 = NULL;
    struct node* node3 = NULL;

    // Create a linked list with three nodes
    node1 = (struct node*)malloc(sizeof(struct node));
    node1->key = 10;
    node1->value = 100;
    node1->next = NULL;
    head = node1;

    node2 = (struct node*)malloc(sizeof(struct node));
    node2->key = 20;
    node2->value = 200;
    node2->next = NULL;
    head->next = node2;

    node3 = (struct node*)malloc(sizeof(struct node));
    node3->key = 30;
    node3->value = 300;
    node3->next = NULL;
    head->next->next = node3;

    // Search the linked list
    search(head, 25);

    return 0;
}