//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 100

struct db_index_node {
  char key[MAX_KEY_SIZE];
  char value[MAX_VALUE_SIZE];
  struct db_index_node *next;
};

struct db_index {
  struct db_index_node *head;
};

void db_index_insert(struct db_index *index, char *key, char *value) {
  struct db_index_node *new_node = (struct db_index_node *)malloc(sizeof(struct db_index_node));
  strcpy(new_node->key, key);
  strcpy(new_node->value, value);
  new_node->next = index->head;
  index->head = new_node;
}

void db_index_search(struct db_index *index, char *key, char *value) {
  struct db_index_node *curr = index->head;
  while (curr != NULL) {
    if (strcmp(curr->key, key) == 0) {
      strcpy(value, curr->value);
      return;
    }
    curr = curr->next;
  }
  strcpy(value, "");
}

int main() {
  struct db_index index;
  index.head = NULL;

  char key1[] = "key1";
  char value1[] = "value1";
  db_index_insert(&index, key1, value1);

  char key2[] = "key2";
  char value2[] = "value2";
  db_index_insert(&index, key2, value2);

  char key3[] = "key3";
  char value3[] = "value3";
  db_index_insert(&index, key3, value3);

  char key4[] = "key4";
  char value4[] = "value4";
  db_index_insert(&index, key4, value4);

  char key5[] = "key5";
  char value5[] = "value5";
  db_index_insert(&index, key5, value5);

  char key6[] = "key6";
  char value6[] = "value6";
  db_index_insert(&index, key6, value6);

  char key7[] = "key7";
  char value7[] = "value7";
  db_index_insert(&index, key7, value7);

  char key8[] = "key8";
  char value8[] = "value8";
  db_index_insert(&index, key8, value8);

  char key9[] = "key9";
  char value9[] = "value9";
  db_index_insert(&index, key9, value9);

  char key10[] = "key10";
  char value10[] = "value10";
  db_index_insert(&index, key10, value10);

  char value_search[MAX_VALUE_SIZE];
  db_index_search(&index, key7, value_search);
  printf("Value for key7: %s\n", value_search);

  return 0;
}