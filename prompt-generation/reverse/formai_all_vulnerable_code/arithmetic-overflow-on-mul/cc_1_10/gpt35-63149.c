//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* function to find the greatest common divisor */

int gcd(int a, int b) {
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

/* function to find the mod inverse */

int modInverse(int a, int m) {
  int m0 = m, t, q;
  int x0 = 0, x1 = 1;
  if (m == 1)
    return 0;
  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0)
    x1 += m0;
  return x1;
}

/* function to encrypt the message */

void encrypt(char message[], int e, int n) {
  int i = 0, len = strlen(message), cipher;
  long int m;
  while (i != len) {
    m = message[i];
    m = m - 96;
    cipher = pow(m, e);
    cipher = cipher % n;
    printf("%d ", cipher);
    i++;
  }
}

/* function to decrypt the message */

void decrypt(int cipher[], int d, int n) {
  int i = 0, len = sizeof(cipher)/sizeof(int), plain;
  long int c;
  while (i != len) {
    c = cipher[i];
    plain = pow(c, d);
    plain = plain % n;
    plain = plain + 96;
    printf("%c", plain);
    i++;
  }
}

/* main function */

int main() {
  int p, q, n, phi, e, d, cipher[100];
  char message[100];
  printf("Enter two prime numbers: ");
  scanf("%d %d", &p, &q);
  n = p * q;
  phi = (p - 1) * (q - 1);
  for (e = 2; e < phi; e++) {
    if (gcd(e, phi) == 1)
      break;
  }
  d = modInverse(e, phi);
  printf("Public key: (%d,%d)\nPrivate key: (%d,%d)\n", e, n, d, n);
  printf("Enter a message to encrypt: ");
  scanf("%s", message);
  encrypt(message, e, n);
  printf("\nEnter the cipher: ");
  for (int i = 0; i < sizeof(cipher)/sizeof(int); i++)
    scanf("%d", &cipher[i]);
  decrypt(cipher, d, n);
  return 0;
}