//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main() {
  int i, j, n, m, a[10], b[10], c[10], d[10], e[10], f[10];

  printf("Enter the number of rooms: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter the number of exits for room %d: ", i + 1);
    scanf("%d", &m);

    switch (m) {
      case 1:
        a[i] = 1;
        break;
      case 2:
        a[i] = 2;
        break;
      case 3:
        a[i] = 3;
        break;
      default:
        a[i] = 0;
        break;
    }

    printf("Enter the room number where the exit leads: ");
    scanf("%d", &j);

    b[i] = j;
  }

  printf("Enter the room number where you start: ");
  scanf("%d", &i);

  printf("You are in room %d. You have %d exits.\n", i, a[i - 1]);

  switch (a[i - 1]) {
    case 1:
      printf("Exit to room %d.\n", b[i - 1]);
      break;
    case 2:
      printf("Exit to room %d and %d.\n", b[i - 1], b[i - 1] + 1);
      break;
    case 3:
      printf("Exit to room %d, %d, and %d.\n", b[i - 1], b[i - 1] + 1, b[i - 1] + 2);
      break;
  }

  return;
}