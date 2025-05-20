//FormAI DATASET v1.0 Category: Stock market tracker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STOCKS 10

typedef struct Stock {
	char name[10];
	float current_price;
	float previous_price;
	float percentage_change;
} Stock;

void update_stock_values(Stock *stock) {
	float diff = stock->current_price - stock->previous_price;
	float perc = (diff / stock->previous_price) * 100;
	stock->percentage_change = perc;
}

void print_stock_info(Stock *stock) {
	printf("Name: %s\n", stock->name);
	printf("Current Price: $%.2f\n", stock->current_price);
	printf("Previous Price: $%.2f\n", stock->previous_price);
	printf("Percentage Change: %.2f%%\n", stock->percentage_change);
}

int main() {
	Stock stocks[MAX_STOCKS];
	char stock_name[10];
	float stock_price;

	for (int i = 0; i < MAX_STOCKS; i++) {
		printf("Enter stock name: ");
		scanf("%s", stocks[i].name);
		printf("Enter current stock price: ");
		scanf("%f", &stock_price);
		stocks[i].current_price = stock_price;
		printf("Enter previous stock price: ");
		scanf("%f", &stock_price);
		stocks[i].previous_price = stock_price;
		update_stock_values(&stocks[i]);
		printf("\n");
	}

	printf("Stock Information:\n");
	for (int i = 0; i < MAX_STOCKS; i++) {
		print_stock_info(&stocks[i]);
		printf("\n");
	}

	return 0;
}