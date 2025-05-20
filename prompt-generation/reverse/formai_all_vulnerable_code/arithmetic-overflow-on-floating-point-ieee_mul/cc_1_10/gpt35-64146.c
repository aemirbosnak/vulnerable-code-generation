//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>

int main() {
  // Welcome message 
  printf("Get ready for some geometric fun!\n\n");

  // The program will calculate the area of a circle
  // Ask the user to input the circle's radius
  float radius;
  printf("What is the radius of your circle? ");
  scanf("%f", &radius);

  // Calculate the area of the circle
  float area = 3.14 * radius * radius;

  // Display the result
  printf("\n Great choice! The area of a circle with radius %.2f is %.2f\n", radius, area);

  // Now let's add some excitement by calculating the area of a rectangle
  // Ask the user to input the rectangle's length and width
  float length, width;
  printf("\nNow let's calculate the area of a rectangle!\n");
  printf("What is the length of your rectangle? ");
  scanf("%f", &length);
  printf("What is the width of your rectangle? ");
  scanf("%f", &width);

  // Calculate the area of the rectangle
  float rectangle_area = length * width;

  // Display the result
  printf("\nWoohoo! The area of a rectangle with length %.2f and width %.2f is %.2f\n", length, width, rectangle_area);

  // Let's take it up a notch by calculating the area of a triangle
  // Ask the user to input the triangle's base and height
  float base, height;
  printf("\nLet's get triangular!\n");
  printf("What is the base of your triangle? ");
  scanf("%f", &base);
  printf("What is the height of your triangle? ");
  scanf("%f", &height);

  // Calculate the area of the triangle
  float triangle_area = 0.5 * base * height;

  // Display the result
  printf("\nGet ready to party! The area of a triangle with base %.2f and height %.2f is %.2f\n", base, height, triangle_area);

  // Thank the user for using the program
  printf("\nThanks for calculating areas with me! Keep geometrically exploring :)\n");

  return 0;
}