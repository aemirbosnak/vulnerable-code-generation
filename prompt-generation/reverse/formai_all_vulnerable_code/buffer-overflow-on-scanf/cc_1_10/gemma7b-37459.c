//Gemma-7B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdlib.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node* next;
};

void* my_malloc(int size) {
  return malloc(size);
}

void my_free(void* ptr) {
  free(ptr);
}

int main() {
  struct Node* head = NULL;
  struct Node* tail = NULL;

  while (1) {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    if (data == -1) {
      break;
    }

    struct Node* newNode = (struct Node*) my_malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  printf("List:\n");
  struct Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
  my_free(head);

  return 0;
}