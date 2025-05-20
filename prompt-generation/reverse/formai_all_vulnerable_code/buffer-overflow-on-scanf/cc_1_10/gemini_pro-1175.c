//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cyberpunk-themed function names
double cyber_add(double a, double b) { return a + b; }
double cyber_sub(double a, double b) { return a - b; }
double cyber_mul(double a, double b) { return a * b; }
double cyber_div(double a, double b) { return a / b; }
double cyber_pow(double a, double b) { return pow(a, b); }
double cyber_sqrt(double a) { return sqrt(a); }
double cyber_sin(double a) { return sin(a); }
double cyber_cos(double a) { return cos(a); }
double cyber_tan(double a) { return tan(a); }

// Main function
int main() {
  // Cyberpunk-themed variable names
  double decker_input;
  double cyberdeck_result;
  char command[20];

  // Cyberpunk-themed greeting
  printf("Welcome to the Cyberdeck Calculator, decker.\n");

  // Loop until the user exits
  while (1) {
    // Prompt the user for input
    printf("Enter a command (add, sub, mul, div, pow, sqrt, sin, cos, tan, exit): ");
    scanf("%s", command);

    // Handle the command
    if (strcmp(command, "add") == 0) {
      printf("Enter two numbers: ");
      scanf("%lf %lf", &decker_input, &cyberdeck_result);
      cyberdeck_result = cyber_add(decker_input, cyberdeck_result);
      printf("Result: %.2lf\n", cyberdeck_result);
    } else if (strcmp(command, "sub") == 0) {
      printf("Enter two numbers: ");
      scanf("%lf %lf", &decker_input, &cyberdeck_result);
      cyberdeck_result = cyber_sub(decker_input, cyberdeck_result);
      printf("Result: %.2lf\n", cyberdeck_result);
    } else if (strcmp(command, "mul") == 0) {
      printf("Enter two numbers: ");
      scanf("%lf %lf", &decker_input, &cyberdeck_result);
      cyberdeck_result = cyber_mul(decker_input, cyberdeck_result);
      printf("Result: %.2lf\n", cyberdeck_result);
    } else if (strcmp(command, "div") == 0) {
      printf("Enter two numbers: ");
      scanf("%lf %lf", &decker_input, &cyberdeck_result);
      cyberdeck_result = cyber_div(decker_input, cyberdeck_result);
      printf("Result: %.2lf\n", cyberdeck_result);
    } else if (strcmp(command, "pow") == 0) {
      printf("Enter two numbers: ");
      scanf("%lf %lf", &decker_input, &cyberdeck_result);
      cyberdeck_result = cyber_pow(decker_input, cyberdeck_result);
      printf("Result: %.2lf\n", cyberdeck_result);
    } else if (strcmp(command, "sqrt") == 0) {
      printf("Enter a number: ");
      scanf("%lf", &decker_input);
      cyberdeck_result = cyber_sqrt(decker_input);
      printf("Result: %.2lf\n", cyberdeck_result);
    } else if (strcmp(command, "sin") == 0) {
      printf("Enter an angle in degrees: ");
      scanf("%lf", &decker_input);
      cyberdeck_result = cyber_sin(decker_input * M_PI / 180);
      printf("Result: %.2lf\n", cyberdeck_result);
    } else if (strcmp(command, "cos") == 0) {
      printf("Enter an angle in degrees: ");
      scanf("%lf", &decker_input);
      cyberdeck_result = cyber_cos(decker_input * M_PI / 180);
      printf("Result: %.2lf\n", cyberdeck_result);
    } else if (strcmp(command, "tan") == 0) {
      printf("Enter an angle in degrees: ");
      scanf("%lf", &decker_input);
      cyberdeck_result = cyber_tan(decker_input * M_PI / 180);
      printf("Result: %.2lf\n", cyberdeck_result);
    } else if (strcmp(command, "exit") == 0) {
      printf("Exiting the Cyberdeck Calculator.\n");
      break;
    } else {
      printf("Invalid command. Try again.\n");
    }
  }

  return 0;
}