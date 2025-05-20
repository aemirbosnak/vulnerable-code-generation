//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
};

struct node *sort(struct node *head) {
  struct node *prev, *curr, *next;
  prev = NULL;
  curr = head;
  while (curr) {
    next = curr->next;
    if (prev && prev->val > curr->val) {
      if (prev == head) {
        head = curr;
      } else {
        prev->next = curr->next;
      }
      curr->next = prev;
      prev = curr;
      curr = next;
    } else {
      prev = curr;
      curr = next;
    }
  }
  return head;
}

int main() {
  struct node *head, *curr;
  int n, i;
  head = NULL;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    curr = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &curr->val);
    curr->next = head;
    head = curr;
  }
  head = sort(head);
  curr = head;
  while (curr) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("\n");
  return 0;
}