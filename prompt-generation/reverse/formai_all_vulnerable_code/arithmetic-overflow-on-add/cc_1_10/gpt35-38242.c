//FormAI DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char *compname;     
   double price;        
   int change;          
   int num_comps = 0;    
   
   printf("Welcome to the Stock Market Tracker!\n");
   printf("------------------------------------\n");

   printf("Please enter the number of companies you want to track: ");
   scanf("%d", &num_comps);

   // Allocating memory to store company names
   compname = (char*)malloc((num_comps+1) * sizeof(char));

   for(int i = 0; i < num_comps; i++) {
      printf("Enter the name of company %d: ", i+1);
      scanf("%s", (compname+i));
   }

   // Creating arrays to store prices and changes
   double prices[num_comps];
   int changes[num_comps];

   // Generating random prices and changes for each company
   for(int j = 0; j < num_comps; j++) {
      prices[j] = ((double)rand()/(double)RAND_MAX) * 1000;
      changes[j] = (rand() % 100) - 50;
   }

   // Printing the stocks
   printf("\n--------------------------\n");
   printf("Stock Market Tracker Results\n");
   printf("--------------------------\n\n");
   printf("Company Name \tPrice \tChange\n");

   for(int k = 0; k < num_comps; k++) {
      printf("%s \t%.2f \t%d\n", (compname+k), prices[k], changes[k]);
   }

   // Finding the company with highest stock price
   int max_index = 0;
   for(int l = 1; l < num_comps; l++) {
      if(prices[l] > prices[max_index]) {
         max_index = l;
      }
   }
   printf("\nThe company with the highest stock price is %s with a price of $%.2f.\n", (compname+max_index), prices[max_index]);
   free(compname);
   compname = NULL;

   return 0;
}