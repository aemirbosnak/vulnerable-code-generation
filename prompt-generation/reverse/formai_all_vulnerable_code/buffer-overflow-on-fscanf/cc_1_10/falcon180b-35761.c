//Falcon-180B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the list
void addNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        struct Node* last = *head_ref;
        while (last->next!= *head_ref) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *head_ref;
    }
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int data;
    while (fscanf(fp, "%d", &data)!= EOF) {
        addNode(&head, data);
    }

    fclose(fp);

    printf("Linked List: ");
    printList(head);

    return 0;
}