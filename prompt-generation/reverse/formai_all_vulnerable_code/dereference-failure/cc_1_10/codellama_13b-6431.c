//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // Structure to represent a node in the linked list
  typedef struct Node {
    int data;
    struct Node *next;
  } Node;

  // Function to create a new node
  Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
  }

  // Function to create a new linked list
  Node* newList(int size) {
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
      Node* node = newNode(i);
      if (head == NULL) {
        head = node;
      } else {
        node->next = head;
        head = node;
      }
    }
    return head;
  }

  // Function to insert a node at the beginning of the linked list
  void insertBegin(Node* head, int data) {
    Node* node = newNode(data);
    node->next = head;
    head = node;
  }

  // Function to insert a node at the end of the linked list
  void insertEnd(Node* head, int data) {
    Node* node = newNode(data);
    Node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = node;
  }

  // Function to insert a node after a given node
  void insertAfter(Node* head, int data, int position) {
    Node* node = newNode(data);
    Node* current = head;
    for (int i = 0; i < position; i++) {
      current = current->next;
    }
    node->next = current->next;
    current->next = node;
  }

  // Function to delete a node from the linked list
  void deleteNode(Node* head, int position) {
    Node* current = head;
    for (int i = 0; i < position; i++) {
      current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
  }

  // Function to print the linked list
  void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }

  int main() {
    // Create a linked list with 5 nodes
    Node* head = newList(5);

    // Insert a node at the beginning of the list
    insertBegin(head, 6);

    // Insert a node at the end of the list
    insertEnd(head, 7);

    // Insert a node after a given node
    insertAfter(head, 8, 2);

    // Delete a node from the list
    deleteNode(head, 3);

    // Print the linked list
    printList(head);

    return 0;
  }