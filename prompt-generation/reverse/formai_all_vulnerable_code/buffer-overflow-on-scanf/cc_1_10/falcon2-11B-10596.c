//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include <stdio.h>
#include <time.h>

int main() {
    // Create a structure to store the stock data
    struct Stock {
        char company[20];
        double price;
        time_t timestamp;
    };

    // Create an array to store the stock data
    struct Stock stocks[100];

    // Prompt the user to enter the number of stock data points
    int num_data_points;
    printf("Enter the number of stock data points: ");
    scanf("%d", &num_data_points);

    // Prompt the user to enter the stock data
    for (int i = 0; i < num_data_points; i++) {
        printf("Enter the company name: ");
        scanf("%s", stocks[i].company);

        printf("Enter the stock price: ");
        scanf("%lf", &stocks[i].price);

        printf("Enter the timestamp (in seconds since the epoch): ");
        scanf("%ld", &stocks[i].timestamp);
    }

    // Print the stock data
    printf("Stock data:\n");
    for (int i = 0; i < num_data_points; i++) {
        printf("Company: %s\n", stocks[i].company);
        printf("Price: %.2lf\n", stocks[i].price);
        printf("Timestamp: %ld\n", stocks[i].timestamp);
    }

    // Calculate the average stock price
    double total_price = 0.0;
    for (int i = 0; i < num_data_points; i++) {
        total_price += stocks[i].price;
    }
    double average_price = total_price / num_data_points;

    // Print the average stock price
    printf("Average stock price: %.2lf\n", average_price);

    return 0;
}