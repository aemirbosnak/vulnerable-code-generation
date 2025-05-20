//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int n;
  printf("How many coins do you want to divide? ");
  scanf("%d", &n);

  int coins[n];
  printf("Enter the values of the coins:\n");
  for(int i = 0; i < n; i++) {
    scanf("%d", &coins[i]);
  }

  int total, sum = 0;
  printf("What is the desired total value? ");
  scanf("%d", &total);

  int counts[n], used_counts[n];
  for(int i = 0; i < n; i++) {
    counts[i] = 0;
    used_counts[i] = 0;
  }

  while(sum < total) {
    int best_coin = -1;
    double best_ratio = 0;

    for(int i = 0; i < n; i++) {
      if(used_counts[i] < counts[i]) {
        continue;
      }

      double ratio = coins[i] / (double)(counts[i] + 1);

      if(ratio > best_ratio) {
        best_ratio = ratio;
        best_coin = i;
      }
    }

    if(best_coin == -1) {
      printf("Cannot divide coins to reach the desired total\n");
      return 0;
    }

    counts[best_coin]++;
    sum += coins[best_coin];
  }

  for(int i = 0; i < n; i++) {
    printf("%d: %d\n", coins[i], counts[i]);
  }

  return 0;
}