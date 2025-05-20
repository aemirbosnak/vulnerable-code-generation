//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_THREADS 5

typedef struct {
    char symbol[10];
    double price;
    double change;
    double percentage_change;
} Stock;

Stock stocks[MAX_STOCKS];

void *update_stock_price(void *arg) {
    int index = *(int *) arg;
    while (1) {
        sleep(5);
        stocks[index].price += 0.1;
        stocks[index].change = stocks[index].price - stocks[index].price / 100;
        stocks[index].percentage_change = (stocks[index].change / stocks[index].price) * 100;
    }
    return NULL;
}

int main() {
    int i, j;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_STOCKS; i++) {
        printf("Enter stock symbol: ");
        scanf("%s", stocks[i].symbol);
        stocks[i].price = rand() % 100;
        stocks[i].change = 0;
        stocks[i].percentage_change = 0;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        int index = rand() % MAX_STOCKS;
        pthread_create(&threads[i], NULL, update_stock_price, &index);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nStock Symbol\tPrice\tChange\tPercentage Change\n");
    for (i = 0; i < MAX_STOCKS; i++) {
        printf("%-10s", stocks[i].symbol);
        printf("%-10.2f", stocks[i].price);
        printf("%-10.2f", stocks[i].change);
        printf("%-10.2f%%\n", stocks[i].percentage_change);
    }

    return 0;
}