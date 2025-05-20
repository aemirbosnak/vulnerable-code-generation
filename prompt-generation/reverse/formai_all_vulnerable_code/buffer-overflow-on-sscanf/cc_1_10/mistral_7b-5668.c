//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define STOCK_FILE "stocks.txt"
#define LINE_LENGTH 256

typedef struct {
    char symbol[10];
    float price;
} Stock;

void generate_random_stock_price(Stock *stock) {
    stock->price = (float) rand() / RAND_MAX * 100 + 10;
}

int file_exists(char *filename) {
    struct stat st;
    return stat(filename, &st) == 0;
}

int read_stock_file(Stock stocks[], int max_stocks) {
    int num_stocks = 0;
    FILE *fp = fopen(STOCK_FILE, "r");

    if (fp != NULL) {
        while (num_stocks < max_stocks && fgets(stocks[num_stocks].symbol, sizeof(stocks[num_stocks].symbol), fp) != NULL) {
            sscanf(stocks[num_stocks].symbol, "%s %f", stocks[num_stocks].symbol, &stocks[num_stocks].price);
            num_stocks++;
        }

        fclose(fp);
    }

    return num_stocks;
}

void write_stock_file(Stock stocks[], int num_stocks) {
    FILE *fp = fopen(STOCK_FILE, "w");

    for (int i = 0; i < num_stocks; i++) {
        fprintf(fp, "%s %f\n", stocks[i].symbol, stocks[i].price);
    }

    fclose(fp);
}

void print_stock(Stock stock) {
    printf("%s: %.2f\n", stock.symbol, stock.price);
}

int main() {
    srand(time(NULL));

    Stock stocks[100];
    int num_stocks = 0;

    if (file_exists(STOCK_FILE)) {
        num_stocks = read_stock_file(stocks, 100);
    }

    while (num_stocks < 100) {
        Stock new_stock;
        generate_random_stock_price(&new_stock);
        strcpy(new_stock.symbol, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        stocks[num_stocks++] = new_stock;
    }

    write_stock_file(stocks, num_stocks);

    printf("Initial stock prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
        usleep(500000); // Sleep for 500ms to add a surreal touch
    }

    printf("\nStock market is closed for the night. Good dreams!\n");

    return 0;
}