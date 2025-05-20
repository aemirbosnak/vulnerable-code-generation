//FormAI DATASET v1.0 Category: Stock market tracker ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   int stock_price[5][30]; // creating a matrix to store stock prices of 5 stocks over a period of 30 days
   int i,j;
    
   srand(time(0)); // setting the seed for random number generator
   
   // initializing stock prices for the first day
   
   for(i=0;i<5;i++){
       printf("Enter the initial price of stock %d: ",i+1);
       scanf("%d",&stock_price[i][0]);
   }
   
   // simulating stock price fluctuations over 30 days
   
   for(i=0;i<5;i++){
       for(j=1;j<30;j++)
           stock_price[i][j] = stock_price[i][j-1] + (rand()%40-20);
   }
   
   // printing the stock price matrix
   
   printf("\nStock Prices:\n");
   for(i=0;i<5;i++){
       printf("Stock %d: ",i+1);
       for(j=0;j<30;j++)
           printf("%d ",stock_price[i][j]);
       printf("\n");
   }
   
   // calculating the maximum and minimum price of each stock over 30 days
   
   int max_price,min_price;
   
   printf("\nMaximum and Minimum Stock Prices:\n");
   for(i=0;i<5;i++){
       max_price = stock_price[i][0];
       min_price = stock_price[i][0];
       for(j=1;j<30;j++){
           if(stock_price[i][j] > max_price)
               max_price = stock_price[i][j];
           if(stock_price[i][j] < min_price)
               min_price = stock_price[i][j];
       }
       printf("Stock %d: Max Price - %d, Min Price - %d\n",i+1,max_price,min_price);
   }
   
   return 0;
}