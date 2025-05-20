//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  typedef struct {
    char key[10];
    int value;
  } entry_t;

  void index_insert(entry_t *index, char *key, int value) {
    int i;
    for (i = 0; i < 10; i++) {
      if (index[i].key[0] == '\0') {
        strcpy(index[i].key, key);
        index[i].value = value;
        return;
      }
    }
    printf("Index is full\n");
  }

  int index_search(entry_t *index, char *key) {
    int i;
    for (i = 0; i < 10; i++) {
      if (strcmp(index[i].key, key) == 0) {
        return index[i].value;
      }
    }
    return -1;
  }

  void index_delete(entry_t *index, char *key) {
    int i;
    for (i = 0; i < 10; i++) {
      if (strcmp(index[i].key, key) == 0) {
        index[i].key[0] = '\0';
        index[i].value = 0;
        return;
      }
    }
  }

  int main(void) {
    entry_t index[10];
    char key[10];
    int value;

    printf("Enter key: ");
    scanf("%s", key);
    value = index_search(index, key);
    if (value != -1) {
      printf("Value = %d\n", value);
    } else {
      printf("Key not found\n");
    }

    printf("Enter key to delete: ");
    scanf("%s", key);
    index_delete(index, key);
    value = index_search(index, key);
    if (value != -1) {
      printf("Key not deleted\n");
    } else {
      printf("Key deleted\n");
    }

    return 0;
  }