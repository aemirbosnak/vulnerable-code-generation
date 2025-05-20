//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Node structure for linked list
typedef struct node {
    char name[50];
    int size;
    struct node* next;
} Node;

//Function to create a new node
Node* createNode(char* name, int size) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

//Function to add a node to the end of the list
void addNode(Node** head, char* name, int size) {
    Node* newNode = createNode(name, size);
    Node* temp = *head;
    if(*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    }
    else {
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

//Function to delete a node from the list
void deleteNode(Node** head, char* name) {
    Node* temp = *head;
    if(temp!= NULL &&!strcmp(temp->name, name)) {
        *head = temp->next;
        free(temp);
    }
    else {
        while(temp!= NULL && strcmp(temp->name, name)) {
            temp = temp->next;
        }
        if(temp!= NULL) {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
        }
    }
}

//Function to search for a node in the list
Node* searchNode(Node* head, char* name) {
    Node* temp = head;
    while(temp!= NULL && strcmp(temp->name, name)) {
        temp = temp->next;
    }
    return temp;
}

//Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while(temp!= NULL) {
        printf("%s (%d bytes)\n", temp->name, temp->size);
        temp = temp->next;
    }
}

//Main function
int main() {
    Node* head = NULL;
    //Create some nodes
    addNode(&head, "file1.txt", 1024);
    addNode(&head, "file2.txt", 2048);
    addNode(&head, "file3.doc", 4096);
    //Display the list
    displayList(head);
    //Delete a node
    deleteNode(&head, "file2.txt");
    //Display the updated list
    displayList(head);
    return 0;
}