//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_DAYS 1000

typedef struct {
    char *name;
    double *prices;
    int num_days;
} Stock;

double mean(double *prices, int num_days) {
    double sum = 0;
    for (int i = 0; i < num_days; i++) {
        sum += prices[i];
    }
    return sum / num_days;
}

double variance(double *prices, int num_days) {
    double mean_price = mean(prices, num_days);
    double sum_of_squared_differences = 0;
    for (int i = 0; i < num_days; i++) {
        sum_of_squared_differences += pow(prices[i] - mean_price, 2);
    }
    return sum_of_squared_differences / (num_days - 1);
}

double standard_deviation(double *prices, int num_days) {
    return sqrt(variance(prices, num_days));
}

double covariance(double *prices1, double *prices2, int num_days) {
    double mean_price1 = mean(prices1, num_days);
    double mean_price2 = mean(prices2, num_days);
    double sum_of_products = 0;
    for (int i = 0; i < num_days; i++) {
        sum_of_products += (prices1[i] - mean_price1) * (prices2[i] - mean_price2);
    }
    return sum_of_products / (num_days - 1);
}

double correlation(double *prices1, double *prices2, int num_days) {
    double std_dev1 = standard_deviation(prices1, num_days);
    double std_dev2 = standard_deviation(prices2, num_days);
    return covariance(prices1, prices2, num_days) / (std_dev1 * std_dev2);
}

int main() {
    // Create an array of stocks
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    // Read in the stock data from a file
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (!feof(fp)) {
        // Read in the stock name
        char *name = malloc(100);
        fscanf(fp, "%s", name);

        // Read in the stock prices
        double *prices = malloc(MAX_DAYS * sizeof(double));
        for (int i = 0; i < MAX_DAYS; i++) {
            fscanf(fp, "%lf", &prices[i]);
        }

        // Store the stock in the array
        stocks[num_stocks].name = name;
        stocks[num_stocks].prices = prices;
        stocks[num_stocks].num_days = MAX_DAYS;
        num_stocks++;
    }

    // Close the file
    fclose(fp);

    // Calculate the mean, variance, and standard deviation of each stock
    for (int i = 0; i < num_stocks; i++) {
        printf("Stock: %s\n", stocks[i].name);
        printf("Mean: %.2f\n", mean(stocks[i].prices, stocks[i].num_days));
        printf("Variance: %.2f\n", variance(stocks[i].prices, stocks[i].num_days));
        printf("Standard deviation: %.2f\n", standard_deviation(stocks[i].prices, stocks[i].num_days));
    }

    // Calculate the covariance and correlation between each pair of stocks
    for (int i = 0; i < num_stocks; i++) {
        for (int j = i + 1; j < num_stocks; j++) {
            printf("Covariance between %s and %s: %.2f\n", stocks[i].name, stocks[j].name, covariance(stocks[i].prices, stocks[j].prices, stocks[i].num_days));
            printf("Correlation between %s and %s: %.2f\n", stocks[i].name, stocks[j].name, correlation(stocks[i].prices, stocks[j].prices, stocks[i].num_days));
        }
    }

    // Free the memory allocated for the stocks
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].name);
        free(stocks[i].prices);
    }

    return EXIT_SUCCESS;
}