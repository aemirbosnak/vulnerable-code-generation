//LLAMA2-13B DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159
#define INFINITY 1e100

// Function to print a menu
void print_menu(void);

// Function to take user input
int get_user_input(int min, int max, char* prompt);

// Function to calculate the area of a circle
double calculate_area(double radius);

// Function to calculate the circumference of a circle
double calculate_circumference(double radius);

int main(void) {
  // Print menu
  print_menu();

  // Get user input for radius
  double radius = get_user_input(1, 10, "Enter radius: ");

  // Calculate and print area
  double area = calculate_area(radius);
  printf("Area of circle with radius %f is %f\n", radius, area);

  // Calculate and print circumference
  double circumference = calculate_circumference(radius);
  printf("Circumference of circle with radius %f is %f\n", radius, circumference);

  return 0;
}

// Function to print a menu
void print_menu(void) {
  printf("Welcome to the Circle Calculator!\n");
  printf("--------------------------------------\n");
  printf("Enter 'a' to calculate the area of a circle\n");
  printf("Enter 'c' to calculate the circumference of a circle\n");
  printf("Enter 'q' to quit\n");
  printf("--------------------------------------\n");
}

// Function to take user input
int get_user_input(int min, int max, char* prompt) {
  int input;
  char buffer[20];

  printf("%s", prompt);
  scanf("%d", &input);

  while (input < min || input > max) {
    printf("Invalid input. Try again: ");
    fgets(buffer, 20, stdin);
    input = atoi(buffer);
  }

  return input;
}

// Function to calculate the area of a circle
double calculate_area(double radius) {
  return PI * radius * radius;
}

// Function to calculate the circumference of a circle
double calculate_circumference(double radius) {
  return 2 * PI * radius;
}