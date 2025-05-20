//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define HASH_SIZE 1024

typedef struct HashNode {
  char *data;
  struct HashNode *next;
} HashNode;

HashNode *hash_insert(HashNode *head, char *data) {
  int hash_index = hash(data) % HASH_SIZE;
  HashNode *newNode = malloc(sizeof(HashNode));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    HashNode *curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = newNode;
  }

  return head;
}

int hash(char *str) {
  int hash_value = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    hash_value = (hash_value * 33) + str[i];
  }

  return hash_value;
}

int main() {
  HashNode *head = NULL;
  char *data = "Hello, world!";
  head = hash_insert(head, data);

  data = "Goodbye, world!";
  head = hash_insert(head, data);

  data = "How are you?";
  head = hash_insert(head, data);

  for (HashNode *curr = head; curr; curr = curr->next) {
    printf("%s\n", curr->data);
  }

  return 0;
}