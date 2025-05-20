//FormAI DATASET v1.0 Category: Syntax parsing ; Style: decentralized
#include <stdio.h>

// Defining the Node structure
struct Node {
  char* data;
  struct Node* next;
};

// Function to add a node to the front of the list
void push(struct Node** head, char* new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head);
  (*head) = new_node;
}

// Function to remove last node of the list
void pop(struct Node** head) {
  struct Node* temp = *head;
  if (temp == NULL) {
    printf("List is already empty\n");
    return;
  }
  if (temp->next == NULL) {
    free(temp);
    *head = NULL;
    return;
  }
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

// Function to display the list
void display(struct Node* node) {
  printf("\n\nParsed Syntax:\n");
  while (node != NULL) {
    printf("%s ", node->data);
    node = node->next;
  }
}

int main() {
  struct Node* head = NULL;
  char option;
  char* data = malloc(sizeof(char) * 25);

  // Infinite loop to provide options to the user
  while (1) {
    printf("\nEnter Syntax Element: ");
    scanf("%s", data);
    push(&head, data);

    printf("\nDo you want to add more syntax elements? (Y/N) ");
    scanf("\n%c", &option);
    if (option == 'N' || option == 'n') {
      break;
    }
  }

  // Displaying the parsed syntax in reverse order
  display(head);

  // Removing the last node of the list
  pop(&head);

  // Displaying the updated parsed syntax
  display(head);

  // Freeing the allocated memory
  struct Node* temp = head;
  while (temp != NULL) {
    struct Node* next_node = temp->next;
    free(temp);
    temp = next_node;
  }

  return 0;
}