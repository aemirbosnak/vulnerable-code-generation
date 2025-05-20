//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_COINS 100

typedef struct {
  int value;
  int count;
} Coin;

int compareCoins(const void *a, const void *b) {
  Coin *coinA = (Coin *)a;
  Coin *coinB = (Coin *)b;
  
  if (coinA->value < coinB->value) {
    return -1;
  } else if (coinA->value > coinB->value) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int numCoins, i;
  Coin coins[MAX_NUM_COINS];
  int totalValue = 0;
  int numCoinsUsed = 0;
  
  printf("Enter the number of coins: ");
  scanf("%d", &numCoins);
  
  printf("Enter the values of the coins (in cents):\n");
  for (i = 0; i < numCoins; i++) {
    scanf("%d", &coins[i].value);
  }
  
  qsort(coins, numCoins, sizeof(Coin), compareCoins);
  
  printf("Sorted coins:\n");
  for (i = 0; i < numCoins; i++) {
    printf("%d cents\n", coins[i].value);
  }
  
  printf("\nEnter the amount to be changed (in cents): ");
  scanf("%d", &totalValue);
  
  i = numCoins - 1;
  while (totalValue > 0 && i >= 0) {
    if (coins[i].value <= totalValue) {
      numCoinsUsed++;
      totalValue -= coins[i].value;
    } else {
      i--;
    }
  }
  
  printf("\nNumber of coins used: %d\n", numCoinsUsed);
  
  return 0;
}