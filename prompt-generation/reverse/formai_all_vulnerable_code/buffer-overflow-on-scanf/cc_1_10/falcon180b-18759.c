//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 1000
#define MAX_VALUES 1000

typedef struct {
	int value;
	int index;
} Coin;

Coin coins[MAX_COINS];
int num_coins;

int main() {
	int num_values;
	int i, j;
	int max_value = 0;

	printf("Enter the number of values: ");
	scanf("%d", &num_values);

	for (i = 0; i < num_values; i++) {
		printf("Enter value %d: ", i + 1);
		scanf("%d", &coins[i].value);
		coins[i].index = i;
		max_value += coins[i].value;
	}

	num_coins = num_values;

	for (i = num_values - 1; i >= 0; i--) {
		for (j = 0; j < num_coins; j++) {
			if (coins[j].value == coins[i].value) {
				coins[j].index = i;
				break;
			}
		}
	}

	int sum = 0;
	int count = 0;
	for (i = 0; i < num_values; i++) {
		sum += coins[i].value;
		count++;
		if (sum == max_value) {
			printf("Minimum number of coins: %d\n", count);
			return 0;
		}
	}

	printf("No solution found.\n");

	return 0;
}