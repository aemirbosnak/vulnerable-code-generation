//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
   int i, j, k, score = 0, total_time;
   char input, option;
   time_t start, end;

   printf("Welcome to the C Typing Speed Test Program\n");
   printf("Select a difficulty level: \n");
   printf("1. Easy\n");
   printf("2. Medium\n");
   printf("3. Hard\n");
   printf("Enter option: ");
   scanf("%c", &option);

   switch(option) {
      case '1':
         j = 5;
         k = 3;
         total_time = 30; // 30 seconds
         break;
      case '2':
         j = 7;
         k = 5;
         total_time = 60; // 1 minute
         break;
      case '3':
         j = 10;
         k = 7;
         total_time = 90; // 1.5 minutes
         break;
      default:
         printf("Invalid option selected. Exiting program.\n");
         return 0;
   }

   printf("You have %d seconds to type as many words as possible.\n", total_time);
   printf("Press enter when ready.\n");
   fflush(stdin);
   getchar();

   srand(time(0));

   start = time(NULL);
   while(difftime(end, start) < total_time) {
      for(i = 0; i < j; i++) {
         for(int l = 0; l < k; l++) {
            int random_char = rand() % 26;
            printf("%c", 'a' + random_char);
         }
         printf(" ");
      }

      printf("\nType the words above and press enter: ");

      fflush(stdin);
      for(i = 0; i < j; i++) {
         for(int l = 0; l < k; l++) {
            scanf("%c", &input);
         }
         scanf(" ");
      }

      score++;

      end = time(NULL);
   }

   printf("Time's up! You scored %d words in %d seconds.\n", score, total_time);
   return 0;
}