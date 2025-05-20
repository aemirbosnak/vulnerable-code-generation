//FormAI DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>  //stdio.h is a library of functions used to handle input/output operations 
#include <stdlib.h> //stdlib.h is a library of functions used for dynamic memory allocation
#include <string.h> //string.h is a library of functions used for manipulating arrays of characters

int main() {
  // Declare variables to hold basic information about stocks
  char name[50];
  char symbol[10];
  float price;
  int volume;

  // Get stock information from user input
  printf("Enter Stock Name: ");
  scanf("%s", name);
  
  printf("Enter Stock Symbol: ");
  scanf("%s", symbol);
  
  printf("Enter Stock Price: ");
  scanf("%f", &price);
  
  printf("Enter Stock Volume: ");
  scanf("%d", &volume);
  
  // Print out the stock information
  printf("\nSymbol: %s", symbol);
  printf("\nName: %s", name);
  printf("\nPrice: $%.2f", price);
  printf("\nVolume: %d", volume);
  
  // Add conditionals to display price trend information
  if (price > 4.50) {
    printf("\n\nPrice Trend: Upward");
  } else if (price < 4.50) {
    printf("\n\nPrice Trend: Downward");
  } else {
    printf("\n\nPrice Trend: Stable");
  }
  
  // Generate a random stock performance score between 1-100
  int score = rand() % 101;
  printf("\nPerformance Score: %d/100", score);
  
  // Add switch statement to display stock performance verdict based on score
  switch(score) {
    case 0 ... 25:
      printf("\nVerdict: Poor performance");
      break;
    case 26 ... 50:
      printf("\nVerdict: Average performance");
      break;
    case 51 ... 75:
      printf("\nVerdict: Good performance");
      break;
    case 76 ... 100:
      printf("\nVerdict: Excellent performance");
      break;
    default:
      printf("\nVerdict: No performance data available");
      break;
  }
  
  return 0;
}