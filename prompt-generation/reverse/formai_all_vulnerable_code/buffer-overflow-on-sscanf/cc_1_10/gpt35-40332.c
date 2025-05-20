//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Defining Constants
#define BUFFER_SIZE 1024
#define MAX_INPUT 255
#define MAX_STOCKS 10

// Function to get user input
void getUserInput(float* stocks, int size) {
    char inputStr[MAX_INPUT];
    float input;
    int i = 0;
    printf("Enter stock prices for today\n");
    while(i < size) {
        printf("Stock %d: ", i+1);
        fgets(inputStr, MAX_INPUT, stdin);
        if(sscanf(inputStr, "%f", &input) != 1) {
            printf("Invalid input, try again..\n");
            continue;
        }
        stocks[i] = input;
        i++;
    }
}

// Function to calculate average
float getAverage(float* stocks, int size) {
    float total = 0.0;
    for(int i=0; i<size; i++) {
        total += stocks[i];
    }
    return total/size;
}

// Function to calculate standard deviation
float getStdev(float* stocks, int size, float average) {
    float variance = 0.0;
    for(int i=0; i<size; i++) {
        variance += (stocks[i] - average)*(stocks[i] - average);
    }
    variance /= size;
    return sqrt(variance);
}

int main() {
    // Defining variables
    float stocks[MAX_STOCKS];
    int numOfStocks;
    char buffer[BUFFER_SIZE];

    // Getting user input for number of stocks to track
    printf("Enter number of stocks to track (max 10): ");
    fgets(buffer, BUFFER_SIZE, stdin);
    if(sscanf(buffer, "%d", &numOfStocks) != 1 || numOfStocks > 10) {
        printf("Invalid input, exiting program.\n");
        return 1;
    }

    // Getting user input for stock prices
    getUserInput(stocks, numOfStocks);

    // Calculating average and standard deviation
    float average = getAverage(stocks, numOfStocks);
    float stdev = getStdev(stocks, numOfStocks, average);

    // Displaying results
    printf("\nResults:\n");
    printf("Average stock price: %.2f\n", average);
    printf("Standard deviation: %.2f\n", stdev);

    return 0;
}