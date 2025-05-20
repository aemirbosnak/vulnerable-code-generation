//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int stocks[5][10];        // A 2D array to store 5 stocks with their prices and changes
   int i, j;
   char stock_names[5][25] = {"Apple", "Microsoft", "Amazon", "Facebook", "Google"};   // An array to store 5 stock names

   // Seed the randomizer
   srand(time(NULL));

   // Initialize the stock prices and changes
   for(i=0; i<5; i++)
   {
       for(j=0; j<10; j++)
       {
           stocks[i][j] = rand() % 1000;  // Initialize stock prices to a random number between 0 and 999
       }
   }

   // Print the current stock prices for each stock
   for(i=0; i<5; i++)
   {
       printf("%s stock prices: ", stock_names[i]);
       for(j=0; j<10; j++)
       {
           printf("%d ", stocks[i][j]);
       }
       printf("\n");
   }

   // Print the average stock price for each stock
   for(i=0; i<5; i++)
   {
       int sum = 0;
       for(j=0; j<10; j++)
       {
           sum += stocks[i][j];
       }
       printf("Average %s stock price: %.2f\n", stock_names[i], (float)sum/10);
   }

   // Print the stock price changes compared to last day for each stock
   for(i=0; i<5; i++)
   {
       printf("%s stock price changes: ", stock_names[i]);
       for(j=1; j<10; j++)
       {
           printf("%.2f%% ", ((float)stocks[i][j] - stocks[i][j-1]) / stocks[i][j-1] * 100);
       }
       printf("\n");
   }

   return 0;
}