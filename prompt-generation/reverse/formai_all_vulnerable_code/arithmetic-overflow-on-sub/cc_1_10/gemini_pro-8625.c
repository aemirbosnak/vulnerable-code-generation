//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STOCK_COUNT 10

typedef struct {
    char *name;
    int price;
    int change;
} Stock;

Stock stocks[STOCK_COUNT] = {
    { "Arasaka", 100, 0 },
    { "Militech", 150, 0 },
    { "Kang Tao", 200, 0 },
    { "Biotechnica", 250, 0 },
    { "Trauma Team", 300, 0 },
    { "Quadra", 350, 0 },
    { "Delamain", 400, 0 },
    { "Tyger Claws", 450, 0 },
    { "Maelstrom", 500, 0 },
    { "Voodoo Boys", 550, 0 }
};

void update_prices() {
    for (int i = 0; i < STOCK_COUNT; i++) {
        stocks[i].price += rand() % 10 - 5;
        stocks[i].change = stocks[i].price - stocks[i-1].price;
    }
}

void print_stocks() {
    printf("================================================================================\n");
    printf("| Symbol | Price | Change | Trend |\n");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < STOCK_COUNT; i++) {
        printf("| %-7s | %5d | %6d | %s |\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].change >= 0 ? "▲" : "▼");
    }
    printf("================================================================================\n");
}

int main() {
    srand(time(NULL));
    while (1) {
        update_prices();
        print_stocks();
        sleep(1);
    }
    return 0;
}