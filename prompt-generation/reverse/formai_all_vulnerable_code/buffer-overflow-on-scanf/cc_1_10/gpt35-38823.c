//FormAI DATASET v1.0 Category: Data mining ; Style: creative
#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void insert(struct Node** head, int key) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = key;
  temp->next = *head;
  *head = temp;
}

void delete(struct Node** head) {
  struct Node* temp = *head;
  *head = (*head)->next;
  free(temp);
}

void display(struct Node* head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int main() {
  struct Node* head = NULL;
  int choice, key;

  printf("Linked list Data Mining Example Program\n\n");

  do {
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the data to insert: ");
        scanf("%d", &key);
        insert(&head, key);
        break;
      case 2:
        if (head == NULL) {
          printf("List is empty\n");
        } else {
          delete(&head);
          printf("Node deleted\n");
        }
        break;
      case 3:
        if (head == NULL) {
          printf("List is empty\n");
        } else {
          printf("List elements are: ");
          display(head);
        }
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  } while(1);

  return 0;
}