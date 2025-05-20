//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct {
    char symbol[10];
    char name[50];
    float price;
    float change;
} Stock;

// Define the global array of stocks
Stock stocks[MAX_STOCKS];

// Define the number of stocks in the array
int num_stocks = 0;

// Function to load the stocks from a file
void load_stocks(char *filename) {
    FILE *fp;
    char line[100];
    int i;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the line
        sscanf(line, "%s %s %f %f", stocks[i].symbol, stocks[i].name, &stocks[i].price, &stocks[i].change);

        // Increment the number of stocks
        i++;
    }

    // Close the file
    fclose(fp);
}

// Function to print the stocks
void print_stocks() {
    int i;

    // Print the header
    printf("%-10s %-50s %-10s %-10s\n", "Symbol", "Name", "Price", "Change");

    // Print the stocks
    for (i = 0; i < num_stocks; i++) {
        printf("%-10s %-50s %-10.2f %-10.2f\n", stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

// Function to get the user's input
void get_input() {
    char input[100];
    int i;

    // Prompt the user for input
    printf("Enter a stock symbol or 'q' to quit: ");
    scanf("%s", input);

    // Check if the user entered 'q' to quit
    if (strcmp(input, "q") == 0) {
        exit(EXIT_SUCCESS);
    }

    // Find the stock in the array
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(input, stocks[i].symbol) == 0) {
            // Print the stock
            printf("%-10s %-50s %-10.2f %-10.2f\n", stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].change);

            // Break out of the loop
            break;
        }
    }

    // If the stock was not found, print an error message
    if (i == num_stocks) {
        printf("Stock not found\n");
    }
}

// Main function
int main() {
    // Load the stocks from the file
    load_stocks("stocks.txt");

    // Print the stocks
    print_stocks();

    // Get the user's input
    get_input();

    return EXIT_SUCCESS;
}