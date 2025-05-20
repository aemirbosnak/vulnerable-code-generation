//FormAI DATASET v1.0 Category: Calculator ; Style: portable
#include <stdio.h>

// Function to add two numbers
int add(int num1, int num2) {
  return num1 + num2;
}

// Function to subtract two numbers
int subtract(int num1, int num2) {
  return num1 - num2;
}

// Function to multiply two numbers
int multiply(int num1, int num2) {
  return num1 * num2;
}

// Function to divide two numbers
float divide(int num1, int num2) {
  if (num2 == 0) {
    printf("Error: Division by zero!");
    return 0;
  }
  return (float)num1 / num2;
}

// Main function
int main() {
  int num1, num2, choice;
  char cont;

  do {
    // Print menu
    printf("Choose an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Enter your choice: ");
    
    scanf("%d", &choice);

    // Get two numbers from user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Perform operation based on user's choice
    switch (choice) {
      case 1:
        printf("%d + %d = %d\n", num1, num2, add(num1, num2));
        break;
      case 2:
        printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
        break;
      case 3:
        printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
        break;
      case 4:
        printf("%d / %d = %.2f\n", num1, num2, divide(num1, num2));
        break;
      default:
        printf("Invalid choice!\n");
    }

    // Ask user if they want to continue
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &cont);
    
    // If user chooses not to continue, terminate program
    if (cont == 'n' || cont == 'N') break;
  } while (1); // Infinite loop

  return 0;
}