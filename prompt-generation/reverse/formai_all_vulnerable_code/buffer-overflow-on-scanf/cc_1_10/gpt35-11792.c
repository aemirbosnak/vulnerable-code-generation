//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
/* Greedy Algorithm program to find the minimum number 
of coins required to make a given amount of change */

#include <stdio.h>

int coins[] = {1, 5, 10, 25}; // Array of coin denominations
int n = 4; // Number of different denominations

void minCoins(int amount)
{
  int coinCount[n]; // Array to store the count of coins
  int i;

  // Initialize all coin counts to zero
  for (i = 0; i < n; i++) {
    coinCount[i] = 0;
  }

  // Iterate over each denomination and add the max number of coins possible to coinCount array
  for (i = n - 1; i >= 0; i--) {
    while (amount >= coins[i]) {
      amount -= coins[i];
      coinCount[i]++;
    }
  }

  // Print the minimum number of coins required
  printf("Minimum number of coins required to make change: ");
  for (i = 0; i < n; i++) {
    printf("%d x %d cents ", coinCount[i], coins[i]);
    if (i != n - 1) {
      printf("+ ");
    }
  }
  printf("= %d cents\n", coins[0] * coinCount[0] + coins[1] * coinCount[1] + coins[2] * coinCount[2] + coins[3] * coinCount[3]);
}

int main()
{
  int amount;

  // Read the amount from the user
  printf("Enter the amount (in cents): ");
  scanf("%d", &amount);

  // Call the minCoins function to find the minimum number of coins required
  minCoins(amount);

  return 0;
}