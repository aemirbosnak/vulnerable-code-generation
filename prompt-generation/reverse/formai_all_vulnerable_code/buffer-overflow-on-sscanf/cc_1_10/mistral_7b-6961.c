//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 1000
#define LINE_LENGTH 100

typedef struct {
    char symbol[10];
    double price;
    double date;
} StockData;

void read_data(const char *filename, StockData stocks[MAX_LINES]);
void calculate_statistics(const StockData stocks[], int n, double *avg_price, double *std_dev, double *max_price, double *min_price);
void write_data(const char *filename, const StockData stocks[MAX_LINES]);

int main() {
    const char *input_filename = "stocks.txt";
    const char *output_filename = "stats.txt";
    StockData stocks[MAX_LINES];
    int n = 0;

    read_data(input_filename, stocks);
    double avg_price, std_dev, max_price, min_price;
    calculate_statistics(stocks, n, &avg_price, &std_dev, &max_price, &min_price);

    fprintf(stderr, "Average Price: %.2f\n", avg_price);
    fprintf(stderr, "Standard Deviation: %.2f\n", std_dev);
    fprintf(stderr, "Maximum Price: %.2f\n", max_price);
    fprintf(stderr, "Minimum Price: %.2f\n", min_price);

    write_data(output_filename, stocks);

    return 0;
}

void read_data(const char *filename, StockData stocks[MAX_LINES]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[LINE_LENGTH];
    int i = 0;

    while (fgets(line, LINE_LENGTH, file) != NULL) {
        if (sscanf(line, "%s %lf %lf", stocks[i].symbol, &stocks[i].price, &stocks[i].date) != 3) {
            perror("Error parsing line");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    fclose(file);
}

void calculate_statistics(const StockData stocks[], int n, double *avg_price, double *std_dev, double *max_price, double *min_price) {
    double sum = 0.0;
    double sum_square = 0.0;

    for (int i = 0; i < n; i++) {
        sum += stocks[i].price;
        sum_square += pow(stocks[i].price, 2);
    }

    *avg_price = sum / n;
    *std_dev = sqrt(sum_square / n - pow(*avg_price, 2));

    *max_price = stocks[0].price;
    *min_price = stocks[0].price;

    for (int i = 1; i < n; i++) {
        if (stocks[i].price > *max_price) {
            *max_price = stocks[i].price;
        }
        if (stocks[i].price < *min_price) {
            *min_price = stocks[i].price;
        }
    }
}

void write_data(const char *filename, const StockData stocks[MAX_LINES]) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_LINES && stocks[i].symbol[0] != '\0'; i++) {
        fprintf(file, "%s %lf %lf\n", stocks[i].symbol, stocks[i].price, stocks[i].date);
    }

    fclose(file);
}