//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000
#define MAX_OPERATIONS 10

// Function to perform arithmetic operations
void perform_ops(int *nums, int num_of_nums, char op) {
  int i, j, k, temp;

  for (i = 0; i < num_of_nums; i++) {
    for (j = i + 1; j < num_of_nums; j++) {
      // Perform arithmetic operations
      switch (op) {
        case '+':
          temp = nums[i] + nums[j];
          break;
        case '-':
          temp = nums[i] - nums[j];
          break;
        case '*':
          temp = nums[i] * nums[j];
          break;
        case '/':
          temp = nums[i] / nums[j];
          break;
        default:
          printf("Invalid operation selected! Please try again...\n");
          return;
      }

      // Check if the result is negative
      if (temp < 0) {
        printf("Error: Result is negative! Please try again...\n");
        return;
      }

      // Store the result in the corresponding position
      nums[i] = temp;
    }
  }
}

int main() {
  int nums[MAX_NUM] = {0};
  char op = '+';
  int num_of_nums = 0;

  // Get the number of numbers and the operation
  printf("Enter the number of numbers: ");
  scanf("%d", &num_of_nums);
  printf("Enter the operation (+, -, *, /): ");
  scanf(" %c", &op);

  // Initialize the numbers
  for (int i = 0; i < num_of_nums; i++) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &nums[i]);
  }

  // Perform the arithmetic operations
  perform_ops(nums, num_of_nums, op);

  // Print the results
  printf("Results:\n");
  for (int i = 0; i < num_of_nums; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}