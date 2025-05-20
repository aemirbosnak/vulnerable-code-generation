//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100

int N;
int queen_cols[MAX_N];
bool row_used[MAX_N];
bool principal_diag_used[MAX_N * 2 - 1];
bool secondary_diag_used[MAX_N * 2 - 1];

void print_solution() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (queen_cols[i] == j) printf("Q ");
      else printf(". ");
    }
    printf("\n");
  }
  printf("\n");
}

void explore(int row) {
  if (row == N) {
    print_solution();
    return;
  }

  for (int col = 0; col < N; col++) {
    if (row_used[row] ||
        principal_diag_used[row + col] ||
        secondary_diag_used[row - col + N - 1]) {
      continue;
    }

    queen_cols[row] = col;
    row_used[row] = true;
    principal_diag_used[row + col] = true;
    secondary_diag_used[row - col + N - 1] = true;
    explore(row + 1);
    row_used[row] = false;
    principal_diag_used[row + col] = false;
    secondary_diag_used[row - col + N - 1] = false;
  }
}

int main() {
  printf("Enter the number of queens N: ");
  scanf("%d", &N);

  explore(0);
  
  return 0;
}