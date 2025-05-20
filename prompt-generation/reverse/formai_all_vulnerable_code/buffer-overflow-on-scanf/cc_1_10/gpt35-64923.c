//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

int main() {
  // Beginning of program
  printf("Welcome to the Bitwise Operations Statistics Program!\n\n");

  // Reading user input
  int num1, num2;
  printf("Please enter two integer numbers: ");
  scanf("%d %d", &num1, &num2);

  // Statistics on bitwise AND operation
  int result_and = num1 & num2;
  printf("\nBitwise AND Operation:\n");
  printf("Number 1: %d (0x%x)\n", num1, num1);
  printf("Number 2: %d (0x%x)\n", num2, num2);
  printf("Result: %d (0x%x)\n", result_and, result_and);
  printf("Number of bits in result: %d\n", __builtin_popcount(result_and));

  // Statistics on bitwise OR operation
  int result_or = num1 | num2;
  printf("\nBitwise OR Operation:\n");
  printf("Number 1: %d (0x%x)\n", num1, num1);
  printf("Number 2: %d (0x%x)\n", num2, num2);
  printf("Result: %d (0x%x)\n", result_or, result_or);
  printf("Number of bits in result: %d\n", __builtin_popcount(result_or));

  // Statistics on bitwise XOR operation
  int result_xor = num1 ^ num2;
  printf("\nBitwise XOR Operation:\n");
  printf("Number 1: %d (0x%x)\n", num1, num1);
  printf("Number 2: %d (0x%x)\n", num2, num2);
  printf("Result: %d (0x%x)\n", result_xor, result_xor);
  printf("Number of bits in result: %d\n", __builtin_popcount(result_xor));

  // Statistics on bitwise NOT operation
  int result_not1 = ~num1;
  int result_not2 = ~num2;
  printf("\nBitwise NOT Operation:\n");
  printf("Number 1: %d (0x%x)\n", num1, num1);
  printf("Result: %d (0x%x)\n", result_not1, result_not1);
  printf("Number of bits in result: %d\n", __builtin_popcount(result_not1));
  printf("Number 2: %d (0x%x)\n", num2, num2);
  printf("Result: %d (0x%x)\n", result_not2, result_not2);
  printf("Number of bits in result: %d\n", __builtin_popcount(result_not2));

  // End of program
  printf("\nThank you for using the program! Goodbye!\n");
  return 0;
}