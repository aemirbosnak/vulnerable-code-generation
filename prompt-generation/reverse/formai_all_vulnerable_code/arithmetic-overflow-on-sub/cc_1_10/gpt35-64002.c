//FormAI DATASET v1.0 Category: Arithmetic ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
   int romeo, juliet, result;

   printf("Romeo enters the value: ");
   scanf("%d", &romeo);

   printf("Juliet enters the value: ");
   scanf("%d", &juliet);

   result = (romeo + juliet) * (romeo - juliet); // A secret formula that only Romeo knows
   
   printf("Romeo's love for Juliet is: %d\n", result);

   printf("But alas!\n");
   printf("The Montagues and Capulets are fighting again!\n");

   printf("Prince Escalus enters the scene and shouts: ENOUGH!\n");
   printf("You may now add or subtract from Romeo and Juliet's love.\n");

   printf("What will you do? Enter 1 to add or 2 to subtract: ");
   int choice;
   scanf("%d", &choice);

   if (choice == 1) {
      int addition;
      printf("Enter a value to add to Romeo and Juliet's love: ");
      scanf("%d", &addition);

      result += addition;
      printf("Romeo and Juliet's love is now %d\n", result);

   } else if (choice == 2) {
      int subtraction;
      printf("Enter a value to subtract from Romeo and Juliet's love: ");
      scanf("%d", &subtraction);

      result -= subtraction;
      printf("Romeo and Juliet's love is now %d\n", result);

   } else {
      printf("Incorrect input. Romeo and Juliet's love remains unchanged.\n");
   }

   printf("However, the feud between the Montagues and Capulets continues.\n");
   printf("Will Romeo and Juliet's love survive?\n");

   return 0;
}