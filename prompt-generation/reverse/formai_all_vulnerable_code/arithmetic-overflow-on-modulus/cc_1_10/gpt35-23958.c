//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>

//function that returns the sum of two numbers
float sum(float a, float b) {
  return a + b;
}

//function that returns the difference between two numbers
float difference(float a, float b) {
  return a - b;
}

//function that returns the product of two numbers
float product(float a, float b) {
  return a * b;
}

//function that returns the division of two numbers
float division(float a, float b) {
  if(b == 0) {
    printf("Error: Division by zero\n");
    return -1;
  } else {
    return a / b;
  }
}

//function that returns the modulus of two numbers
int modulus(int a, int b) {
  if(b == 0) {
    printf("Error: Division by zero\n");
    return -1;
  } else {
    return a % b;
  }
}

int main() {

  printf("Welcome to the Math Exercise program!\n");

  float num1, num2;
  int choice;

  do {

    //menu
    printf("\n Choose an option:\n");
    printf("\n 1. Sum");
    printf("\n 2. Difference");
    printf("\n 3. Product");
    printf("\n 4. Division");
    printf("\n 5. Modulus");
    printf("\n 6. Quit");

    //read user's choice
    printf("\n Enter your choice: ");
    scanf("%d", &choice);

    //based on the choice, do the corresponding operation
    switch(choice) {

      case 1:
        printf("\n Enter two numbers to add: ");
        scanf("%f%f", &num1, &num2);
        printf("\n The sum of %.2f and %.2f is %.2f\n", num1, num2, sum(num1, num2));
        break;

      case 2:
        printf("\n Enter two numbers to subtract: ");
        scanf("%f%f", &num1, &num2);
        printf("\n The difference between %.2f and %.2f is %.2f\n", num1, num2, difference(num1, num2));
        break;

      case 3:
        printf("\n Enter two numbers to multiply: ");
        scanf("%f%f", &num1, &num2);
        printf("\n The product of %.2f and %.2f is %.2f\n", num1, num2, product(num1, num2));
        break;

      case 4:
        printf("\n Enter two numbers to divide: ");
        scanf("%f%f", &num1, &num2);
        if(division(num1, num2) != -1) {
          printf("\n The division of %.2f and %.2f is %.2f\n", num1, num2, division(num1, num2));
        }
        break;

      case 5:
        printf("\n Enter two numbers to find modulus: ");
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        if(modulus(n1, n2) != -1) {
          printf("\n The modulus of %d and %d is %d\n", n1, n2, modulus(n1, n2));
        }
        break;

      case 6:
        printf("\n Thank you for using the Math Exercise program!\n");
        break;

      default:
        printf("\n Invalid choice. Please try again.\n");

    }

  }while(choice != 6);

  return 0;
}