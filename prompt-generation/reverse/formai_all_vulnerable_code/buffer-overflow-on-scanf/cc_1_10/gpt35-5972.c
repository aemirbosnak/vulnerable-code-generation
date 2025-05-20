//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int player, computer, result;
   char choice;
   
   srand(time(NULL));

   printf("Let's play a game of Table! Do you accept the challenge? (Y/N) \n");
   scanf("%c", &choice);
   
   if(choice == 'Y'|| choice == 'y')
   {
	   printf("Great! Let's begin. \n");
	   
	   do
	   {
		   printf("\n");
		   printf("Enter your choice (1 for Rock, 2 for Scissors, 3 for Paper): ");
		   scanf("%d", &player);
		   
		   while(player < 1 || player > 3)
		   {
			   printf("Invalid choice! Please enter a valid option: ");
			   scanf("%d", &player);
		   }
		   
		   computer = (rand() % 3) + 1;
		   
		   printf("Player chose: %d \n", player);
		   printf("Computer chose: %d \n", computer);
		   
		   result = (player - computer + 3) % 3;
		   
		   if(result == 1)
		   {
			   printf("Player wins! \n");
		   }
		   else if(result == 2)
		   {
			   printf("Computer wins! \n");
		   }
		   else
		   {
			   printf("It's a tie! \n");
		   }
		   
		   printf("\n");
		   printf("Would you like to play again? (Y/N) \n");
		   scanf(" %c", &choice);
		   
	   }while(choice == 'Y' || choice == 'y');
   }
   else
   {
      printf("Alright, good bye! \n");
   }
   
   return 0;
}