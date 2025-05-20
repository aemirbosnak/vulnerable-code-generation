//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>

/* We'll use a prime number for p */
#define P 17
/* Here's a primitive root for p */
#define ALPHA 3

/* Calculate a^x mod p using brute force */
int modexp(int a, int x, int p) {
  int result = 1;
  while (x > 0) {
    if (x % 2 == 1) {
      result = (result * a) % p;
    }
    a = (a * a) % p;
    x /= 2;
  }
  return result;
}

/* Compute a digital signature for a message using private key d */
int sign(int message, int d) {
  return modexp(message, d, P);
}

/* Verify a digital signature for a message using public key e */
int verify(int message, int signature, int e) {
  return (signature == modexp(message, e, P)) ? 1 : 0;
}

int main() {
  int d, e;
  printf("Enter a private key (integer): ");
  scanf("%d", &d);
  e = modexp(ALPHA, d, P);
  printf("Public key: %d\n", e);

  int message;
  printf("Enter a message (integer): ");
  scanf("%d", &message);

  int signature = sign(message, d);
  printf("Digital signature: %d\n", signature);

  int result = verify(message, signature, e);
  if (result == 1) {
    printf("Verification successful!\n");
  } else {
    printf("Verification failed!\n");
  }

  return 0;
}