//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: standalone
// DB_INDEX.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_RECORD_SIZE 1000
#define MAX_INDEX_SIZE 10000

typedef struct {
  char key[MAX_KEY_LENGTH];
  char record[MAX_RECORD_SIZE];
} Record;

typedef struct {
  Record *records;
  int size;
} Index;

Index create_index(int size) {
  Index index;
  index.records = (Record *)malloc(size * sizeof(Record));
  index.size = size;
  return index;
}

void add_record(Index *index, char *key, char *record) {
  int i;
  for (i = 0; i < index->size; i++) {
    if (strcmp(index->records[i].key, key) == 0) {
      strcpy(index->records[i].record, record);
      return;
    }
  }
  strcpy(index->records[i].key, key);
  strcpy(index->records[i].record, record);
  index->size++;
}

void remove_record(Index *index, char *key) {
  int i;
  for (i = 0; i < index->size; i++) {
    if (strcmp(index->records[i].key, key) == 0) {
      index->size--;
      memmove(&index->records[i], &index->records[i + 1], (index->size - i) * sizeof(Record));
      return;
    }
  }
}

void print_index(Index *index) {
  int i;
  for (i = 0; i < index->size; i++) {
    printf("key: %s\nrecord: %s\n", index->records[i].key, index->records[i].record);
  }
}

int main() {
  Index index = create_index(10);
  add_record(&index, "key1", "record1");
  add_record(&index, "key2", "record2");
  add_record(&index, "key3", "record3");
  print_index(&index);
  remove_record(&index, "key2");
  print_index(&index);
  return 0;
}