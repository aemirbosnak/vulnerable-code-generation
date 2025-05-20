//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int n;
  int *a;
} tower;

tower *new_tower(int n) {
  tower *t = malloc(sizeof(tower));
  t->n = n;
  t->a = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) t->a[i] = i + 1;
  return t;
}

void free_tower(tower *t) {
  free(t->a);
  free(t);
}

void print_tower(tower *t) {
  for (int i = 0; i < t->n; i++) printf("%d ", t->a[i]);
  printf("\n");
}

void move_disk(tower *from, tower *to) {
  int disk = from->a[from->n - 1];
  from->n--;
  to->a[to->n++] = disk;
}

void hanoi(tower *a, tower *b, tower *c, int n) {
  if (n == 1) {
    move_disk(a, c);
    return;
  }
  hanoi(a, c, b, n - 1);
  move_disk(a, c);
  hanoi(b, a, c, n - 1);
}

int main() {
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);
  tower *a = new_tower(n);
  tower *b = new_tower(0);
  tower *c = new_tower(0);
  printf("Initial state:\n");
  print_tower(a);
  print_tower(b);
  print_tower(c);
  hanoi(a, b, c, n);
  printf("Final state:\n");
  print_tower(a);
  print_tower(b);
  print_tower(c);
  free_tower(a);
  free_tower(b);
  free_tower(c);
  return 0;
}