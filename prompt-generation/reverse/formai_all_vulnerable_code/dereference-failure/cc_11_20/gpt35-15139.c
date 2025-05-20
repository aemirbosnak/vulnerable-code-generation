//FormAI DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *head = NULL;

int main() {
  printf("Welcome to the Mind-Bending Linked List Operations Program!\n");
  printf("This program will completely change how you see linked lists.\n");

  while (1) {
    printf("\nEnter the number of your desired operation:\n");
    printf("1. Insert\n2. Delete\n3. Print\n4. Reverse\n");
    printf("5. Check if Empty\n6. Size\n7. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1: { // Insert
        printf("\nEnter integer value to insert: ");
        int val;
        scanf("%d", &val);

        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->data = val;
        new_node->next = head;

        head = new_node;

        printf("\nInserted %d successfully!\n\n", val);

        break;
      }
      case 2: { // Delete
        if (head == NULL) {
          printf("\nLinked list is empty!\n\n");
          break;
        }

        printf("\nEnter integer value to delete: ");
        int val;
        scanf("%d", &val);

        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL) {
          if (curr->data == val) {
            if (prev != NULL) {
              prev->next = curr->next;
            } else {
              head = curr->next;
            }

            printf("\nDeleted %d successfully!\n\n", val);

            free(curr);
            break;
          }

          prev = curr;
          curr = curr->next;
        }

        if (curr == NULL) {
          printf("\nLinked list does not contain %d!\n\n", val);
        }

        break;
      }
      case 3: { // Print
        if (head == NULL) {
          printf("\nLinked list is empty!\n\n");
          break;
        }

        Node *curr = head;

        printf("\nThe linked list is:\n");
        while (curr != NULL) {
          printf("%d ", curr->data);
          curr = curr->next;
        }
        printf("\n\n");

        break;
      }
      case 4: { // Reverse
        if (head == NULL) {
          printf("\nLinked list is empty!\n\n");
          break;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        printf("\nReversing the linked list...\n\n");

        while (curr != NULL) {
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
        }

        head = prev;

        printf("Linked list has been reversed!\n\n");

        break;
      }
      case 5: { // Check if Empty
        if (head == NULL) {
          printf("\nLinked list is empty!\n\n");
        } else {
          printf("\nLinked list is not empty!\n\n");
        }

        break;
      }
      case 6: { // Size
        int count = 0;
        Node *curr = head;

        while (curr != NULL) {
          count++;
          curr = curr->next;
        }

        printf("\nLinked list size is %d.\n\n", count);

        break;
      }
      case 7: { // Exit
        printf("\nThank you for using the Mind-Bending Linked List Operations Program!\n");
        exit(0);
      }
      default:
        printf("\nInvalid choice! Please try again.\n\n");
    }
  }

  return 0;
}