//Falcon-180B DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    FILE* file;
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    // Read the integers from the file and insert them into the linked list
    int data;
    struct Node* head = NULL;
    while (fscanf(file, "%d", &data)!= EOF) {
        push(&head, data);
    }

    // Close the file
    fclose(file);

    // Print the linked list
    printf("Linked list: ");
    printList(head);

    return 0;
}