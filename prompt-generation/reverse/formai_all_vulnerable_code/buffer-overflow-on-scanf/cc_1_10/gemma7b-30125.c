//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, i, j, k, l, m, greed, total = 0;
  char **a, **b;

  printf("Enter the number of participants: ");
  scanf("%d", &n);

  a = (char **)malloc(n * sizeof(char *));
  b = (char **)malloc(n * sizeof(char *));

  for (i = 0; i < n; i++) {
    a[i] = (char *)malloc(10 * sizeof(char));
    b[i] = (char *)malloc(10 * sizeof(char));
  }

  for (i = 0; i < n; i++) {
    printf("Enter the name of participant %d: ", i + 1);
    scanf("%s", a[i]);

    printf("Enter the participant's dream: ");
    scanf("%s", b[i]);
  }

  printf("Enter the total amount of money: ");
  scanf("%d", &total);

  greed = total / n;

  for (i = 0; i < n; i++) {
    k = strlen(a[i]) + strlen(b[i]) + 1;
    l = greed - k;
    m = l / 2;
    a[i][k] = '$';
    b[i][k] = '$';
    a[i][k + 1] = '$';
    b[i][k + 1] = '$';
    a[i][k + m] = '$';
    b[i][k + m] = '$';
  }

  for (i = 0; i < n; i++) {
    printf("%s\n", a[i]);
    printf("%s\n", b[i]);
  }

  return 0;
}