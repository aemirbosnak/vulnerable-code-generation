//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h>

int main() {
  char stock1[10], stock2[10], stock3[10], stock4[10], stock5[10];
  float price1, price2, price3, price4, price5;
  
  printf("Enter the name of the first stock: ");
  scanf("%s", stock1);
  printf("Enter the price of %s: ", stock1);
  scanf("%f", &price1);
  
  printf("Enter the name of the second stock: ");
  scanf("%s", stock2);
  printf("Enter the price of %s: ", stock2);
  scanf("%f", &price2);
  
  printf("Enter the name of the third stock: ");
  scanf("%s", stock3);
  printf("Enter the price of %s: ", stock3);
  scanf("%f", &price3);
  
  printf("Enter the name of the fourth stock: ");
  scanf("%s", stock4);
  printf("Enter the price of %s: ", stock4);
  scanf("%f", &price4);
  
  printf("Enter the name of the fifth stock: ");
  scanf("%s", stock5);
  printf("Enter the price of %s: ", stock5);
  scanf("%f", &price5);
  
  float average_price = (price1 + price2 + price3 + price4 + price5) / 5;
  printf("The average price of the stocks is: %.2f\n", average_price);
  
  int num_increased = 0;
  if (price1 > average_price) {
    num_increased++;
  }
  if (price2 > average_price) {
    num_increased++;
  }
  if (price3 > average_price) {
    num_increased++;
  }
  if (price4 > average_price) {
    num_increased++;
  }
  if (price5 > average_price) {
    num_increased++;
  }
  printf("The number of stocks that increased above the average is: %d", num_increased);
  
  return 0;
}