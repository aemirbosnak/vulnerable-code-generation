//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STOCKS 100
#define MAX_THREADS 10

typedef struct {
    char name[20];
    float price;
    float prev_price;
    int change;
} stock;

stock stocks[MAX_STOCKS];
pthread_t threads[MAX_THREADS];
int num_stocks = 0;
int num_threads = 0;

void *track_stock(void *arg) {
    int i = *(int *) arg;
    while (1) {
        sleep(5);
        if (stocks[i].price!= stocks[i].prev_price) {
            stocks[i].prev_price = stocks[i].price;
            stocks[i].change = (stocks[i].price - stocks[i].prev_price) * 100 / stocks[i].prev_price;
        }
    }
    return NULL;
}

int main() {
    FILE *fp;
    char line[100];
    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (fgets(line, 100, fp)!= NULL) {
        sscanf(line, "%s %f %f", stocks[num_stocks].name, &stocks[num_stocks].price, &stocks[num_stocks].prev_price);
        num_stocks++;
    }
    fclose(fp);

    printf("Enter number of stocks to track: ");
    scanf("%d", &num_stocks);

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for (int i = 0; i < num_stocks; i++) {
        pthread_create(&threads[i], NULL, track_stock, &i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}