//FormAI DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {

   FILE *fp;
   int num1, num2;
   char operator;

   fp = fopen("example.txt", "r");
   if (fp == NULL) {
      printf("Error: File does not exist");
      exit(1);
   }

   if (fscanf(fp, "%d %c %d", &num1, &operator, &num2) != 3) {
      printf("Error: Invalid input format");
      fclose(fp);
      exit(2);
   }

   fclose(fp);

   switch (operator) {
      case '+':
         printf("The result is: %d", num1 + num2);
         break;

      case '-':
         printf("The result is: %d", num1 - num2);
         break;

      case '*':
         printf("The result is: %d", num1 * num2);
         break;

      case '/':
         if (num2 == 0) {
            printf("Error: Division by zero");
            exit(3);
         }
         printf("The result is: %d", num1 / num2);
         break;

      default:
         printf("Error: Invalid operator");
         exit(4);
   }

   return 0;
}