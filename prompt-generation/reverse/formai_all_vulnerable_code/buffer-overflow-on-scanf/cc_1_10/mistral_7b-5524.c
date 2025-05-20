//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_AMOUNT 100000
#define NUM_COINS 6

int coins[NUM_COINS] = {1, 5, 10, 25, 50, 100};
int table[MAX_AMOUNT + 1];

void initTable() {
    int i;
    for (i = 0; i <= MAX_AMOUNT; i++) {
        table[i] = i;
    }
    for (i = 0; i < NUM_COINS; i++) {
        int value = coins[i];
        for (int j = value; j <= MAX_AMOUNT; j++) {
            table[j] = min(table[j], table[j - value] + 1);
        }
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void printResult(int amount) {
    int i = NUM_COINS - 1;
    printf("Minimum coins to make %d:\n", amount);
    while (amount > 0 && i >= 0) {
        if (amount >= coins[i]) {
            int taken = min(amount / coins[i], table[amount - coins[i]]);
            amount -= taken * coins[i];
            printf(" %d coin(s) of value %d\n", taken, coins[i]);
            i--;
        } else {
            i--;
        }
    }
}

int main() {
    int amount;

    printf("Enter the amount:\n");
    scanf("%d", &amount);

    initTable();

    printResult(amount);

    return 0;
}