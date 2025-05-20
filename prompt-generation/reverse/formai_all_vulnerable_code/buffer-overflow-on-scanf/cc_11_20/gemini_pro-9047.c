//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <math.h>

int main() {
  double pi = 3.14159265358979323846;
  double e = 2.71828182845904523536;

  printf("Welcome to the Scientific Calculator!\n");
  printf("Enter a command (help for help): ");
  char command[10];
  scanf("%s", command);

  while (strcmp(command, "quit") != 0) {
    if (strcmp(command, "help") == 0) {
      printf("Available commands:\n");
      printf("  add: add two numbers\n");
      printf("  subtract: subtract two numbers\n");
      printf("  multiply: multiply two numbers\n");
      printf("  divide: divide two numbers\n");
      printf("  power: raise a number to a power\n");
      printf("  sqrt: calculate the square root of a number\n");
      printf("  sin: calculate the sine of an angle (in degrees)\n");
      printf("  cos: calculate the cosine of an angle (in degrees)\n");
      printf("  tan: calculate the tangent of an angle (in degrees)\n");
      printf("  pi: print the value of pi\n");
      printf("  e: print the value of e\n");
      printf("  quit: quit the calculator\n");
    } else if (strcmp(command, "add") == 0) {
      double num1, num2;
      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      printf("Result: %lf\n", num1 + num2);
    } else if (strcmp(command, "subtract") == 0) {
      double num1, num2;
      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      printf("Result: %lf\n", num1 - num2);
    } else if (strcmp(command, "multiply") == 0) {
      double num1, num2;
      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      printf("Result: %lf\n", num1 * num2);
    } else if (strcmp(command, "divide") == 0) {
      double num1, num2;
      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      if (num2 == 0) {
        printf("Error: division by zero\n");
      } else {
        printf("Result: %lf\n", num1 / num2);
      }
    } else if (strcmp(command, "power") == 0) {
      double base, exponent;
      printf("Enter a base and an exponent: ");
      scanf("%lf %lf", &base, &exponent);
      printf("Result: %lf\n", pow(base, exponent));
    } else if (strcmp(command, "sqrt") == 0) {
      double num;
      printf("Enter a number: ");
      scanf("%lf", &num);
      if (num < 0) {
        printf("Error: square root of a negative number\n");
      } else {
        printf("Result: %lf\n", sqrt(num));
      }
    } else if (strcmp(command, "sin") == 0) {
      double angle;
      printf("Enter an angle (in degrees): ");
      scanf("%lf", &angle);
      printf("Result: %lf\n", sin(angle * pi / 180));
    } else if (strcmp(command, "cos") == 0) {
      double angle;
      printf("Enter an angle (in degrees): ");
      scanf("%lf", &angle);
      printf("Result: %lf\n", cos(angle * pi / 180));
    } else if (strcmp(command, "tan") == 0) {
      double angle;
      printf("Enter an angle (in degrees): ");
      scanf("%lf", &angle);
      printf("Result: %lf\n", tan(angle * pi / 180));
    } else if (strcmp(command, "pi") == 0) {
      printf("Result: %lf\n", pi);
    } else if (strcmp(command, "e") == 0) {
      printf("Result: %lf\n", e);
    } else {
      printf("Invalid command\n");
    }

    printf("Enter a command (help for help): ");
    scanf("%s", command);
  }

  printf("Goodbye!\n");
  return 0;
}