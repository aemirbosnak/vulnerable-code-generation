//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Bitwise AND operation
int bitwiseAND(int a, int b) {
  if (a == 0 || b == 0) {
    return 0;
  } else if (a % 2 == 0 && b % 2 == 0) {
    return 2 * bitwiseAND(a / 2, b / 2);
  } else if (a % 2 == 0 && b % 2 != 0) {
    return bitwiseAND(a / 2, b);
  } else if (a % 2 != 0 && b % 2 == 0) {
    return bitwiseAND(a, b / 2);
  } else {
    return 1 + bitwiseAND(a - 1, b - 1);
  }
}

// Bitwise OR operation
int bitwiseOR(int a, int b) {
  if (a == 0 && b == 0) {
    return 0;
  } else if (a % 2 == 0 && b % 2 == 0) {
    return 2 * bitwiseOR(a / 2, b / 2);
  } else if (a % 2 == 0 && b % 2 != 0) {
    return 1 + bitwiseOR(a / 2, b);
  } else if (a % 2 != 0 && b % 2 == 0) {
    return 1 + bitwiseOR(a, b / 2);
  } else {
    return 2 + bitwiseOR(a - 1, b - 1);
  }
}

// Bitwise XOR operation
int bitwiseXOR(int a, int b) {
  if (a == 0 && b == 0) {
    return 0;
  } else if (a % 2 == 0 && b % 2 == 0) {
    return 2 * bitwiseXOR(a / 2, b / 2);
  } else if (a % 2 == 0 && b % 2 != 0) {
    return 1 + bitwiseXOR(a / 2, b);
  } else if (a % 2 != 0 && b % 2 == 0) {
    return 1 + bitwiseXOR(a, b / 2);
  } else {
    return 0 + bitwiseXOR(a - 1, b - 1);
  }
}

// Bitwise NOT operation
int bitwiseNOT(int a) {
  if (a == 0) {
    return 1;
  } else if (a % 2 == 0) {
    return 2 * bitwiseNOT(a / 2);
  } else {
    return 1 + 2 * bitwiseNOT(a - 1);
  }
}

int main() {
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);

  printf("Bitwise AND of %d and %d is %d\n", a, b, bitwiseAND(a, b));
  printf("Bitwise OR of %d and %d is %d\n", a, b, bitwiseOR(a, b));
  printf("Bitwise XOR of %d and %d is %d\n", a, b, bitwiseXOR(a, b));
  printf("Bitwise NOT of %d is %d\n", a, bitwiseNOT(a));

  return 0;
}