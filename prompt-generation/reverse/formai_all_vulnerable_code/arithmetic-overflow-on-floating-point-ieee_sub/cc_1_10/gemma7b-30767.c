//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_NUM 10

typedef struct Stock
{
  char name[20];
  double current_price;
  double previous_price;
  double change;
} Stock;

void update_stock(Stock *stock)
{
  printf("Enter the current price of %s: ", stock->name);
  scanf("%lf", &stock->current_price);

  stock->change = (stock->current_price - stock->previous_price) / stock->previous_price * 100;

  if (stock->change > 0)
  {
    printf("%s is up %f%%.\n", stock->name, stock->change);
  }
  else
  {
    printf("%s is down %f%%.\n", stock->name, -stock->change);
  }

  stock->previous_price = stock->current_price;
}

int main()
{
  Stock stocks[MAX_STOCK_NUM];

  for (int i = 0; i < MAX_STOCK_NUM; i++)
  {
    stocks[i].name[0] = '\0';
    stocks[i].current_price = 0.0;
    stocks[i].previous_price = 0.0;
    stocks[i].change = 0.0;
  }

  int num_stocks = 0;

  printf("Enter the name of the stock you want to track: ");
  scanf("%s", stocks[num_stocks].name);

  stocks[num_stocks].current_price = 100.0;
  stocks[num_stocks].previous_price = 100.0;

  num_stocks++;

  while (1)
  {
    update_stock(&stocks[num_stocks - 1]);

    printf("Enter 'q' to quit or any other key to continue: ");
    char input;
    scanf(" %c", &input);

    if (input == 'q')
    {
      break;
    }
  }

  return 0;
}