//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   int player, computer, choice, count;
   char c;
   
   printf("Welcome to the C Table Game!\n");
   printf("Choose your option:\n");
   printf("1) Rock\n");
   printf("2) Paper\n");
   printf("3) Scissors\n");

   do 
   {
      count = 0;
      printf("\nEnter your choice: ");
      scanf("%d",&player);
      while ((c = getchar()) != '\n' && c != EOF) { }
      printf("\nPlayer chooses ");

      switch (player)
      {
         case 1: printf("Rock\n");
                 break;

         case 2: printf("Paper\n");
                 break;

         case 3: printf("Scissors\n");
                 break;

         default: printf("Invalid option\n");
                  count = 1;
      }

      if (!count)
      {
         srand(time(NULL));
         computer = rand() % 3 + 1;
         printf("Computer chooses ");

         switch (computer)
         {
            case 1: printf("Rock\n");
                    break;

            case 2: printf("Paper\n");
                    break;

            case 3: printf("Scissors\n");
                    break;
         }

         if (player == computer)
            printf("It's a draw!\n");

         else if ((player == 1 && computer == 3) ||
                  (player == 2 && computer == 1) ||
                  (player == 3 && computer == 2))
            printf("You won!\n");

         else
            printf("Computer won!\n");
      }

      printf("Do you want to play again? (1 for Yes/0 for No): ");
      scanf("%d",&choice);

   } while (choice == 1);

   printf("\nThanks for playing! Have a good day!\n");
   return 0;
}