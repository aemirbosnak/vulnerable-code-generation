#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 64

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void hanoi(int n, Node* top) {
  if (n == 0) {
    return;
  }

  hanoi(n - 1, top);

  top->data = n;
  printf("Move disk %d from peg %c to peg %c\n", n, 'a' + top->data - 1, 'c' + top->data - 1);

  hanoi(1, top);
}

int main() {
  Node* top = NULL;
  hanoi(MAX_DISKS, top);
  return 0;
}
