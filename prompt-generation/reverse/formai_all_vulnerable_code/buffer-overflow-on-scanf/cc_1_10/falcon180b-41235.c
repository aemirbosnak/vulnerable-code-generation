//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 100
#define MAX_VALUES 100

int values[MAX_VALUES];
int coins[MAX_COINS];

void generate_values() {
    int i;
    srand(time(NULL));
    for (i = 0; i < MAX_VALUES; i++) {
        values[i] = rand() % 100;
    }
}

void generate_coins() {
    int i;
    srand(time(NULL));
    for (i = 0; i < MAX_COINS; i++) {
        coins[i] = rand() % 100;
    }
}

void print_solution(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    if (n > MAX_COINS) {
        printf("Error: Too many coins.\n");
        return 1;
    }
    generate_values();
    generate_coins();
    int max_value = values[0];
    int max_coins = 0;
    for (i = 1; i < MAX_VALUES; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }
    for (i = 0; i < MAX_COINS; i++) {
        if (coins[i] == max_value) {
            max_coins++;
        }
    }
    printf("The maximum number of coins you can make is %d.\n", max_coins);
    print_solution(max_coins);
    return 0;
}