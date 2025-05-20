//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: safe
#include<stdio.h>

// Function to calculate the area of a rectangular
float rect_area(float l, float b) {
  return l*b;
}

// Function to calculate the perimeter of a rectangular
float rect_perimeter(float l, float b) {
  return 2*(l+b);
}

// Function to calculate the area of a circle
float circle_area(float r) {
  return 3.14*r*r;
}

// Function to calculate the circumference of a circle
float circle_circumference(float r) {
  return 2*3.14*r;
}

int main() {
  int choice;
  float length, breadth, radius, area, perimeter, circumference;
  
  // Displaying the menu
  printf("\n1. Calculate the area of a rectangular");
  printf("\n2. Calculate the perimeter of a rectangular");
  printf("\n3. Calculate the area of a circle");
  printf("\n4. Calculate the circumference of a circle");
  printf("\n5. Exit");
  
  // Reading the choice
  printf("\nEnter your choice: ");
  scanf("%d", &choice);
  
  // Based on the choice selected, perform the relevant operation
  switch(choice) {
    case 1:
      printf("\nEnter the length of the rectangular: ");
      scanf("%f", &length);
      printf("\nEnter the breadth of the rectangular: ");
      scanf("%f", &breadth);
      area = rect_area(length, breadth);
      printf("\nThe area of the rectangular is: %f\n", area);
      break;
      
    case 2:
      printf("\nEnter the length of the rectangular: ");
      scanf("%f", &length);
      printf("\nEnter the breadth of the rectangular: ");
      scanf("%f", &breadth);
      perimeter = rect_perimeter(length, breadth);
      printf("\nThe perimeter of the rectangular is: %f\n", perimeter);
      break;
      
    case 3:
      printf("\nEnter the radius of the circle: ");
      scanf("%f", &radius);
      area = circle_area(radius);
      printf("\nThe area of the circle is: %f\n", area);
      break;
      
    case 4:
      printf("\nEnter the radius of the circle: ");
      scanf("%f", &radius);
      circumference = circle_circumference(radius);
      printf("\nThe circumference of the circle is: %f\n", circumference);
      break;
      
    case 5:
      printf("\nExiting....\n");
      break;
      
    default:
      printf("\nInvalid choice. Please select a valid choice (1-5).\n");
      break;
  }
  
  return 0;
}