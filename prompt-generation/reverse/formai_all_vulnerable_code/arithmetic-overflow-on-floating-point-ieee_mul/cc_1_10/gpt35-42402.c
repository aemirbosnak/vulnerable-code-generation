//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mind-bending
#include <stdio.h>

int main() {
   int shape;
   float length, width, area, perimeter;
   
   printf("Choose a shape: \n");
   printf("1. Square \n");
   printf("2. Rectangle \n");
   printf("3. Circle \n");
   printf("4. Triangle \n");
   scanf("%d", &shape);
   
   switch(shape) {
      case 1:
         printf("Enter the length of a side: ");
         scanf("%f", &length);
         area = length * length;
         perimeter = 4 * length;
         printf("Area of square: %0.2f \n", area);
         printf("Perimeter of square: %0.2f \n", perimeter);
         break;
         
      case 2:
         printf("Enter the length and width: ");
         scanf("%f %f", &length, &width);
         area = length * width;
         perimeter = 2 * (length + width);
         printf("Area of rectangle: %0.2f \n", area);
         printf("Perimeter of rectangle: %0.2f \n", perimeter);
         break;
         
      case 3:
         printf("Enter the radius: ");
         scanf("%f", &length);
         area = 3.14159 * length * length;
         perimeter = 2 * 3.14159 * length;
         printf("Area of circle: %0.2f \n", area);
         printf("Circumference of circle: %0.2f \n", perimeter);
         break;
         
      case 4:
         printf("Enter the length of the base and height: ");
         scanf("%f %f", &length, &width);
         area = 0.5 * length * width;
         perimeter = length + (2 * (length * length + width * width));
         printf("Area of triangle: %0.2f \n", area);
         printf("Perimeter of triangle: %0.2f \n", perimeter);
         break;
         
      default:
         printf("Invalid input.");
   }
   
   return 0;
}