//FormAI DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void handle_error(int error_code);
void puzzle_solver(int input);

int main() {
   int input;
   printf("Enter an integer between 1 and 10: ");
   scanf("%d", &input);
   
   if (input < 1 || input > 10) {
        handle_error(1);
   }
   
   puzzle_solver(input);
   
   return 0;
}

void handle_error(int error_code) {
   switch(error_code) {
      case 1:
         printf("Error: Invalid input.\n");
         printf("Please enter an integer between 1 and 10.\n");
         exit(0);
      case 2:
         printf("Error: Insufficient memory.\n");
         exit(0);
      case 3:
         printf("Error: Invalid file path.\n");
         exit(0);
      default:
         printf("Error: Unknown error code.\n");
         exit(0);
   }
}

void puzzle_solver(int input) {
   int solution;
   
   switch(input) {
      case 1:
         solution = 42;
         break;
      case 2:
         solution = 12;
         break;
      case 3:
         solution = 53;
         break;
      case 4:
         solution = 9;
         break;
      case 5:
         solution = 18;
         break;
      case 6:
         solution = 36;
         break;
      case 7:
         solution = 72;
         break;
      case 8:
         solution = 144;
         break;
      case 9:
         solution = 288;
         break;
      case 10:
         solution = 576;
         break;
   }

   printf("The answer to the puzzle is: %d\n", solution);
}