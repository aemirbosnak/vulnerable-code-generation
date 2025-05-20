//FormAI DATASET v1.0 Category: Educational ; Style: artistic
#include <stdio.h> 

int main() 
{ 
   int angle, i, j, width, height; 

   printf("Enter the angle in degrees (0-360): "); 
   scanf("%d", &angle);

   printf("Enter the width of the rectangle: ");
   scanf("%d", &width);

   printf("Enter the height of the rectangle: ");
   scanf("%d", &height);

   for (i = 0; i < height; i++) 
   { 
      for (j = 0; j < width; j++) 
      { 
         if (angle == 0) 
         { 
             printf("*"); 
         } 
         else if (angle == 90 && j == width/2) 
         { 
             printf("*"); 
         } 
         else if (angle == 180 && i == height/2) 
         { 
             printf("*"); 
         } 
         else if (angle == 270 && j == width/2) 
         { 
             printf("*"); 
         } 
         else if (angle > 0 && angle < 90 && i == (height-1) - j * tan(angle*(3.14159/180))) 
         { 
             printf("*"); 
         } 
         else if (angle > 90 && angle < 180 && j == width - (width-1) * tan((angle-90)*(3.14159/180)) - i * tan((90-angle)*(3.14159/180)))
         { 
             printf("*"); 
         } 
         else if (angle > 180 && angle < 270 && i == height - (height-1) * tan((angle-180)*(3.14159/180)) - j * tan((270-angle)*(3.14159/180)))
         {
             printf("*"); 
         } 
         else if (angle > 270 && angle < 360 && j == (width-1) * tan((angle-270)*(3.14159/180)) + i * tan((360-angle)*(3.14159/180)))
         { 
             printf("*"); 
         } 
         else 
         { 
             printf(" "); 
         } 
      } 
      printf("\n"); 
   } 

   return 0; 
}