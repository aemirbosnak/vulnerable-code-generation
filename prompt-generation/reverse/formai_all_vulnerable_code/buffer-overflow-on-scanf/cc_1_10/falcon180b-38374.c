//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 100
#define MAX_VALUES 100
#define MAX_ITEMS 100
#define MAX_N 100
#define MAX_M 100

int coin_values[MAX_COINS];
int item_values[MAX_ITEMS];
int item_weights[MAX_ITEMS];
int knap_weights[MAX_N][MAX_M];

void generate_random_data(int n, int m) {
    for (int i = 0; i < n; i++) {
        knap_weights[i][0] = rand() % 100;
    }
    for (int i = 0; i < m; i++) {
        coin_values[i] = rand() % 100;
        item_values[i] = rand() % 100;
        item_weights[i] = rand() % 100;
    }
}

void print_solution(int n, int m, int solution[MAX_N][MAX_M]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Enter the number of items: ");
    scanf("%d", &m);
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    generate_random_data(n, m);

    int solution[MAX_N][MAX_M];
    int max_value = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (knap_weights[i][0] + item_weights[j] <= 100) {
                solution[i][j] = 1;
                if (coin_values[j] + item_values[j] > max_value) {
                    max_value = coin_values[j] + item_values[j];
                }
            } else {
                solution[i][j] = 0;
            }
        }
    }

    printf("Maximum value: %d\n", max_value);
    print_solution(n, m, solution);

    return 0;
}