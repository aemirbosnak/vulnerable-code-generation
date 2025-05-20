//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  typedef struct Node {
    void *data;
    struct Node *next;
  } Node;

  void *kmalloc(size_t size, int flags) {
    void *ptr = malloc(size);
    if (!ptr) {
      perror("kmalloc: failed to allocate memory");
      exit(1);
    }
    return ptr;
  }

  void kfree(void *ptr) {
    free(ptr);
  }

  int main() {
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < 10; i++) {
      Node *node = (Node *) kmalloc(sizeof(Node), 0);
      node->data = (void *) i;
      node->next = NULL;

      if (head == NULL) {
        head = node;
        tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
    }

    printf("List: ");
    for (Node *node = head; node != NULL; node = node->next) {
      printf("%d ", *(int *) node->data);
    }
    printf("\n");

    for (Node *node = head; node != NULL; node = node->next) {
      kfree(node->data);
      node->data = NULL;
      if (node->next != NULL) {
        kfree(node);
        node = NULL;
      }
    }

    return 0;
  }