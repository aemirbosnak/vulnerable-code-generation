//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 256

typedef struct HashNode {
  char data[HASH_SIZE];
  struct HashNode* next;
} HashNode;

void hash_init(HashNode** head) {
  *head = NULL;
}

void hash_add(HashNode** head, char* str) {
  int hash = str_hash(str);
  HashNode* node = malloc(sizeof(HashNode));
  node->data[0] = hash & 0xFF;
  node->next = NULL;

  if (*head == NULL) {
    *head = node;
  } else {
    HashNode* current = *head;
    while (current->next) {
      current = current->next;
    }
    current->next = node;
  }
}

int str_hash(char* str) {
  int hash = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    hash = (hash << 5) ^ str[i];
  }
  return hash;
}

int main() {
  HashNode* head = NULL;
  hash_init(&head);

  char* str1 = "This is a string";
  hash_add(&head, str1);

  char* str2 = "Another string";
  hash_add(&head, str2);

  char* str3 = "The first string";
  hash_add(&head, str3);

  // Print the hash values
  HashNode* current = head;
  while (current) {
    printf("%s has hash value %x\n", current->data, current->data[0]);
    current = current->next;
  }

  return 0;
}