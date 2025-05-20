//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>

int main() {
   int shapeChoice; // to determine which shape the user wants
   printf("Welcome to the Geometric Algorithm program!\n");
   printf("Which shape do you want to calculate? \n");
   printf("1. Circle\n");
   printf("2. Triangle\n");
   printf("3. Rectangle\n");
   printf("4. Pentagon\n");
   printf("5. Hexagon\n");
   printf("Enter your choice: ");
   scanf("%d", &shapeChoice);

   switch(shapeChoice) {
       case 1:
           printf("You chose the Circle. How original.\n");
           printf("Enter the radius of the circle: ");
           float radius;
           scanf("%f", &radius);
           printf("The area of the circle is %.2f. Wow!\n", 3.14159 * radius * radius);
           break;

       case 2:
           printf("Ooh, a Triangle. So edgy.\n");
           printf("Enter the base of the triangle: ");
           float base;
           scanf("%f", &base);
           printf("Enter the height of the triangle: ");
           float height;
           scanf("%f", &height);
           printf("The area of the triangle is %.2f. So acute!\n", 0.5 * base * height);
           break;

       case 3:
           printf("A Rectangle? Well, it's your life.\n");
           printf("Enter the length of the rectangle: ");
           float length;
           scanf("%f", &length);
           printf("Enter the width of the rectangle: ");
           float width;
           scanf("%f", &width);
           printf("The area of the rectangle is %.2f. How oblong.\n", length * width);
           break;

       case 4:
           printf("A Pentagon? That's one too many sides.\n");
           printf("Enter the side length of the pentagon: ");
           float sideLength;
           scanf("%f", &sideLength);
           printf("The area of the pentagon is %.2f. So...pentaful.\n", 1.7205 * sideLength * sideLength);
           break;

       case 5:
           printf("Ah, the Hexagon. Six is such a lovely number.\n");
           printf("Enter the side length of the hexagon: ");
           float side;
           scanf("%f", &side);
           printf("The area of the hexagon is %.2f. So hex-y!\n", 2.598 * side * side);
           break;

       default:
           printf("Invalid choice. Geometry is not your strong suit, is it?\n");
   }

   return 0;
}