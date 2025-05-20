//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct Node {
  char data;
  struct Node* next;
} Node;

struct Node* insertAtTail(struct Node* head, char data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int main() {
  struct Node* head = NULL;

  char word[MAX];
  printf("Enter a word: ");
  scanf("%s", word);

  for (int i = 0; word[i] != '\0'; i++) {
    insertAtTail(head, word[i]);
  }

  int i = 0;
  for (struct Node* node = head; node != NULL; node = node->next) {
    if (!islower(node->data)) {
      node->data = tolower(node->data);
    }
  }

  printf("The corrected word is: ");
  for (struct Node* node = head; node != NULL; node = node->next) {
    printf("%c ", node->data);
  }

  printf("\n");

  return 0;
}