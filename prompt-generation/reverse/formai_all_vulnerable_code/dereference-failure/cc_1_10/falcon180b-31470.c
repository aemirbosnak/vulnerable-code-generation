//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct node {
    int data;
    struct node* next;
};

// Define structure for a linked list
struct linkedList {
    struct node* head;
    int size;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(struct linkedList* list, int data) {
    struct node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        struct node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Function to display the linked list
void displayList(struct linkedList* list) {
    struct node* temp = list->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct linkedList list;
    list.head = NULL;
    list.size = 0;

    // Add nodes to the list
    addNode(&list, 1);
    addNode(&list, 2);
    addNode(&list, 3);
    addNode(&list, 4);
    addNode(&list, 5);

    // Display the list
    displayList(&list);

    // Free memory
    struct node* temp = list.head;
    while (temp!= NULL) {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}