//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct node {
    char name[50];
    float price;
    struct node *next;
} Node;

// Define the structure of the linked list
typedef struct list {
    Node *head;
} List;

// Function to create a new node
Node *createNode(char name[], float price) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void addNode(List *list, char name[], float price) {
    Node *newNode = createNode(name, price);
    Node *temp = list->head;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the list
void displayList(List *list) {
    Node *temp = list->head;
    printf("Name\t\tPrice\n");
    while (temp!= NULL) {
        printf("%s\t\t%.2f\n", temp->name, temp->price);
        temp = temp->next;
    }
}

// Main function
int main() {
    List list;
    list.head = NULL;

    // Add nodes to the list
    addNode(&list, "Paracetamol", 10.50);
    addNode(&list, "Ibuprofen", 12.75);
    addNode(&list, "Aspirin", 8.25);

    // Display the list
    displayList(&list);

    return 0;
}