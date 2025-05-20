//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Macros to simplify bitwise operations
#define BIT(n) (1 << (n))
#define SET_BIT(var, n) (var |= BIT(n))
#define CLEAR_BIT(var, n) (var &= ~BIT(n))
#define TOGGLE_BIT(var, n) (var ^= BIT(n))
#define GET_BIT(var, n) ((var & BIT(n)) >> n)

// Function to perform bitwise operations on two numbers
int bitwise_operations(int num1, int num2, int operation) {
  switch (operation) {
    case 0: // AND
      return num1 & num2;
    case 1: // OR
      return num1 | num2;
    case 2: // XOR
      return num1 ^ num2;
    case 3: // NOT
      return ~num1;
    case 4: // Left Shift
      return num1 << num2;
    case 5: // Right Shift
      return num1 >> num2;
    default:
      printf("Invalid operation!\n");
      return -1;
  }
}

// Function to print binary representation of an integer
void print_binary(int num) {
  int i;
  printf("Binary representation: ");
  for (i = 31; i >= 0; i--) {
    printf("%d", GET_BIT(num, i));
  }
  printf("\n");
}

int main() {
  int num1, num2, operation;

  // Get input from user
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  // Get input for the bitwise operation
  printf("Enter the bitwise operation (0-5): ");
  scanf("%d", &operation);

  // Perform the operation and print the result
  int result = bitwise_operations(num1, num2, operation);
  if (result != -1) {
    printf("Result: %d\n", result);
    print_binary(result);
  }

  return 0;
}