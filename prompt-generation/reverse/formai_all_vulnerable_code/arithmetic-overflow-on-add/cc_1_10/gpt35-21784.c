//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initializing variables
  int n, m, i, j, k, max_weight;
  printf("Enter the number of baggage belts: ");
  scanf("%d", &n);
  printf("Enter the number of baggage carts: ");
  scanf("%d", &m);
  printf("Enter the maximum weight for a single baggage cart: ");
  scanf("%d", &max_weight);

  // Initializing dynamic arrays to store the weight of baggage and the cart number
  int *baggage_weight = (int *) malloc(n * sizeof(int));
  int *cart_number = (int *) malloc(n * sizeof(int));

  // Reading the weight of baggage and assigning it to a cart number
  for (i = 0; i < n; i++) {
    printf("Enter the weight of baggage %d: ", i+1);
    scanf("%d", &baggage_weight[i]);
    // Assigning the baggage to a cart
    for (j = 0; j < m; j++) {
      if (cart_number[j] + baggage_weight[i] <= max_weight) {
        cart_number[j] += baggage_weight[i];
        break;
      }
    }
    if (j == m) {
      printf("Cannot load baggage %d into any cart.\n", i+1);
    } else {
      printf("Baggage %d loaded onto cart %d.\n", i+1, j+1);
    }
  }

  // Printing the final distribution of baggage across carts
  printf("\nDistribution of baggage across carts:\n");
  for (i = 0; i < m; i++) {
    printf("Cart %d: ", i+1);
    for (j = 0; j < n; j++) {
      if (i == cart_number[j]) {
        printf("%d ", j+1);
      }
    }
    printf("\n");
  }

  // Freeing memory allocated to dynamic arrays
  free(baggage_weight);
  free(cart_number);

  return 0;
}