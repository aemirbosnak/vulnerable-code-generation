//Code Llama-13B DATASET v1.0 Category: Performance-Critical Component ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

struct data_t {
  char *key;
  int value;
};

struct data_t *data_table;
int data_table_size = 1024;
int data_table_capacity = 1024;

void init_data_table() {
  data_table = malloc(sizeof(struct data_t) * data_table_size);
  memset(data_table, 0, sizeof(struct data_t) * data_table_size);
}

int add_data(char *key, int value) {
  if (data_table_size >= data_table_capacity) {
    data_table_capacity *= 2;
    data_table = realloc(data_table, sizeof(struct data_t) * data_table_capacity);
  }
  data_table[data_table_size].key = key;
  data_table[data_table_size].value = value;
  data_table_size++;
  return 0;
}

int get_data(char *key, int *value) {
  for (int i = 0; i < data_table_size; i++) {
    if (strcmp(data_table[i].key, key) == 0) {
      *value = data_table[i].value;
      return 0;
    }
  }
  return -1;
}

int main() {
  init_data_table();
  add_data("hello", 42);
  add_data("world", 24);
  int value;
  get_data("hello", &value);
  printf("Value of 'hello' is: %d\n", value);
  return 0;
}