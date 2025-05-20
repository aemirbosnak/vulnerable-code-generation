//FormAI DATASET v1.0 Category: Bitwise operations ; Style: real-life
#include <stdio.h>

int main() {
  // declare two unsigned integers for input
  unsigned int num1, num2;

  // prompt the user for input
  printf("Enter two numbers separated by a space: ");

  // read in the two integers from the user
  scanf("%u %u", &num1, &num2);

  // perform bitwise AND operation between the two numbers
  unsigned int bitwise_and = num1 & num2;
  printf("%u & %u = %u\n", num1, num2, bitwise_and);

  // perform bitwise OR operation between the two numbers
  unsigned int bitwise_or = num1 | num2;
  printf("%u | %u = %u\n", num1, num2, bitwise_or);

  // perform bitwise XOR operation between the two numbers
  unsigned int bitwise_xor = num1 ^ num2;
  printf("%u ^ %u = %u\n", num1, num2, bitwise_xor);

  // perform bitwise NOT operation on num1
  unsigned int bitwise_not1 = ~num1;
  printf("~%u = %u\n", num1, bitwise_not1);

  // perform bitwise NOT operation on num2
  unsigned int bitwise_not2 = ~num2;
  printf("~%u = %u\n", num2, bitwise_not2);

  // perform left shift operation on num1
  unsigned int left_shift = num1 << 1;
  printf("%u << 1 = %u\n", num1, left_shift);

  // perform right shift operation on num2
  unsigned int right_shift = num2 >> 1;
  printf("%u >> 1 = %u\n", num2, right_shift);

  // check if num1 is even or odd using bitwise AND operation
  if ((num1 & 1) == 0) {
    printf("%u is even\n", num1);
  } else {
    printf("%u is odd\n", num1);
  }

  // check if num2 is even or odd using bitwise AND operation
  if ((num2 & 1) == 0) {
    printf("%u is even\n", num2);
  } else {
    printf("%u is odd\n", num2);
  }

  return 0;
}