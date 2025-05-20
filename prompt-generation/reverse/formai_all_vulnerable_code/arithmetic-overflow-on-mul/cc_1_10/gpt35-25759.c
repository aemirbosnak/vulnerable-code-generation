//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is our super-duper secure public key algorithm

int main() {
  int p, g, x, y, k, msg, c1, c2;
  
  // Let's get some random values
  srand(time(0));
  
  // Choose a prime number for p
  p = 11;
  
  // Choose a random number for g
  g = rand() % (p-1) + 1;
  
  // Choose a random number for x
  x = rand() % (p-2) + 1;
  
  // Calculate y = g^x (mod p)
  y = 1;
  for (int i=1; i<=x; i++) {
    y *= g;
    y %= p;
  }
  
  // Share public keys
  printf("Public Keys:\n");
  printf("p = %d\n", p);
  printf("g = %d\n", g);
  printf("y = %d\n\n", y);
  
  // Choose a random number for k
  k = rand() % (p-2) + 1;
  
  // Get the message from user
  printf("Enter a message: ");
  scanf("%d", &msg);
  
  // Calculate c1 = g^k (mod p)
  c1 = 1;
  for (int i=1; i<=k; i++) {
    c1 *= g;
    c1 %= p;
  }
  
  // Calculate c2 = y^k * msg (mod p)
  c2 = y;
  for (int i=1; i<=k; i++) {
    c2 *= y;
    c2 %= p;
  }
  c2 *= msg;
  c2 %= p;
  
  // Print encrypted message
  printf("\nEncrypted Message: (%d, %d)\n\n", c1, c2);
  
  // Decrypt the message
  int m = c2;
  for (int i=1; i<=x; i++) {
    m *= c1;
    m %= p;
  }
  
  // Print decrypted message
  printf("Decrypted Message: %d", m);
  
  return 0;
}