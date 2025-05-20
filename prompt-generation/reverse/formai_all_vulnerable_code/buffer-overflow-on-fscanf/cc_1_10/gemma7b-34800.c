//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define MAX 1024

typedef struct Node {
  char data[MAX];
  struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data[0] = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int main() {
  Node* head = NULL;

  char filename[] = "my_file.txt";
  FILE* file = fopen(filename, "r");

  if (file) {
    char buffer[MAX];
    int i = 0;

    while (fscanf(file, "%s", buffer) != EOF) {
      insertAtTail(head, buffer[i]);
      i++;
    }

    fclose(file);
  }

  // Backup data
  head->next->data[0] = 'B';

  // Restore data
  head->next->data[0] = 'R';

  return 0;
}