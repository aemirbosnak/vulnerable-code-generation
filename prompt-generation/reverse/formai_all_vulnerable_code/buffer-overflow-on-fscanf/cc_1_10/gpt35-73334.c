//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp; // File pointer to open file
  
  fp = fopen("numbers.txt", "r"); // Open file numbers.txt in read mode

  if (fp == NULL) { // If file couldn't be opened
    printf("Unable to open file!");
    return 1;
  }

  int num, sum = 0, count = 0, odd_count = 0, even_count = 0, min = 9999, max = -9999;
  float avg;

  while(fscanf(fp, "%d", &num) == 1) { // Read numbers from file
    sum += num;
    count++;

    if(num%2==0) { // Count even and odd numbers
      even_count++;
    } else {
      odd_count++;
    }

    if(num < min) { // Find minimum number
      min = num;
    }

    if(num > max) { // Find maximum number
      max = num;
    }

  }

  avg = sum * 1.0 / count; // Calculate average 

  printf("Total numbers: %d\n", count);
  printf("Sum of numbers: %d\n", sum);
  printf("Average of numbers: %.2f\n", avg);
  printf("Minimum number: %d\n", min);
  printf("Maximum number: %d\n", max);
  printf("Number of odd numbers: %d\n", odd_count);
  printf("Number of even numbers: %d\n", even_count);

  fclose(fp); // Close file

  return 0;
}