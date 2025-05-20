//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements allowed in the circuit
#define MAX_ELEMENTS 20

// Define the maximum name length allowed for each element
#define MAX_NAME_LENGTH 10

// Define a structure to represent an element in the circuit
typedef struct element {
  char name[MAX_NAME_LENGTH];
  int value;
} element;

// Define a structure to represent the circuit
typedef struct circuit {
  element elements[MAX_ELEMENTS];
  int size;
} circuit;

// Define a function to add an element to the circuit
void addElement(circuit *c, char *name, int value) {
  // Check if the circuit is full
  if (c->size == MAX_ELEMENTS) {
    printf("Circuit is full, cannot add element\n");
    return;
  }

  // Check if the name of the element already exists in the circuit
  for (int i = 0; i < c->size; i++) {
    if (strcmp(c->elements[i].name, name) == 0) {
      printf("Element with name %s already exists in the circuit\n", name);
      return;
    }
  }

  // Add the new element to the circuit
  element e;
  strcpy(e.name, name);
  e.value = value;
  c->elements[c->size] = e;
  c->size++;

  printf("Element added successfully!\n");
}

// Define a function to remove an element from the circuit
void removeElement(circuit *c, char *name) {
  // Check if the circuit is empty
  if (c->size == 0) {
    printf("Circuit is empty, cannot remove element\n");
    return;
  }

  // Check if the element with the given name exists in the circuit
  int indexToRemove = -1;
  for (int i = 0; i < c->size; i++) {
    if (strcmp(c->elements[i].name, name) == 0) {
      indexToRemove = i;
      break;
    }
  }

  // If the element was not found, print an error message and return
  if (indexToRemove == -1) {
    printf("Element with name %s not found in circuit\n", name);
    return;
  }

  // Remove the element from the circuit by shifting all elements after it to the left
  for (int i = indexToRemove; i < c->size - 1; i++) {
    c->elements[i] = c->elements[i + 1];
  }
  c->size--;

  printf("Element removed successfully!\n");
}

// Define a function to print the names and values of all elements in the circuit
void printCircuit(circuit c) {
  // Check if the circuit is empty
  if (c.size == 0) {
    printf("Circuit is empty\n");
    return;
  }

  printf("Circuit elements:\n");
  for (int i = 0; i < c.size; i++) {
    printf("%s = %d\n", c.elements[i].name, c.elements[i].value);
  }
}

// Define the main function
int main() {
  // Create a new circuit
  circuit c;
  c.size = 0;

  printf("Welcome to the cheerful circuit simulator!\n");

  // Repeat until the user quits
  while (1) {
    // Print the menu
    printf("\nMenu:\n");
    printf("1. Add element\n");
    printf("2. Remove element\n");
    printf("3. Print circuit\n");
    printf("4. Quit\n");

    // Read the user's choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Handle the user's choice
    switch (choice) {
      case 1:
        // Add element
        printf("Enter name of element: ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);
        printf("Enter value of element: ");
        int value;
        scanf("%d", &value);
        addElement(&c, name, value);
        break;
      case 2:
        // Remove element
        printf("Enter name of element to remove: ");
        char nameToRemove[MAX_NAME_LENGTH];
        scanf("%s", nameToRemove);
        removeElement(&c, nameToRemove);
        break;
      case 3:
        // Print circuit
        printCircuit(c);
        break;
      case 4:
        // Quit
        printf("Goodbye!\n");
        exit(0);
      default:
        // Invalid choice
        printf("Invalid choice, please try again\n");
        break;
    }
  }
  return 0;
}