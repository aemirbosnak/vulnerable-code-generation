//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>

int main() {
  // Shape shifting variables
  int num_checksums = 0;
  printf("Enter number of checksums to calculate: ");
  scanf("%d", &num_checksums);

  // Dynamic array allocation
  int* numbers = (int*) malloc(num_checksums * sizeof(int));

  // Input number sequence
  printf("Enter numbers to calculate checksums:\n");
  for (int i = 0; i < num_checksums; i++) {
    scanf("%d", &numbers[i]);
  }

  // Start checksum calculations
  printf("\nChecksums:\n");
  for (int i = 0; i < num_checksums; i++) {
    int sum = 0;
    int num = numbers[i];
    int is_shape_shifter = 0;
    
    // Shape shift first digit
    if (num < 10) {
      num += num;
      is_shape_shifter = 1;
    }

    // Shape shift repeating digits
    int repeat;
    do {
      repeat = num % 10;
      num /= 10;
      if (num == repeat) {
        num += repeat;
        is_shape_shifter = 1;
      }
      sum += repeat;
    } while (num != 0);
    
    // Print checksum calculation
    printf("%d: ", numbers[i]);
    if (is_shape_shifter) {
      printf("SHAPE SHIFTER ");
    }
    printf("Checksum = %d\n", sum);
  }

  // Free memory
  free(numbers);

  return 0;
}