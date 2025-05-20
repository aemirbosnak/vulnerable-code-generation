//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stock{
    char name[50];
    float current_price;
    float previous_price;
};

// Function to check if the file exists
bool file_exists(const char* filename){
    FILE* file = fopen(filename, "r");
    if(file != NULL){
        fclose(file);
        return true;
    }
    return false;
}

int main(){
    // Create an array of stocks
    struct stock stocks[10];
    // Set the default values for each stock
    for(int i = 0; i < 10; i++){
        sprintf(stocks[i].name, "Stock%d", i+1);
        stocks[i].current_price = 0;
        stocks[i].previous_price = 0;
    }
    // Check if the data file exists
    if(!file_exists("stock_data.txt")){
        // If it does not exist, create it and set the default values
        FILE* data_file = fopen("stock_data.txt", "w");
        for(int i = 0; i < 10; i++){
            fprintf(data_file, "%s:%f:%f\n", stocks[i].name, stocks[i].current_price, stocks[i].previous_price);
        }
        fclose(data_file);
    }
    // Read the data from the file
    FILE* data_file = fopen("stock_data.txt", "r");
    for(int i = 0; i < 10; i++){
        fscanf(data_file, "%[^:]:%f:%f\n", stocks[i].name, &stocks[i].current_price, &stocks[i].previous_price);
    }
    fclose(data_file);

    // Display the stock data
    printf("Current Stock Prices:\n");
    for(int i = 0; i < 10; i++){
        printf("%s: %.2f\n", stocks[i].name, stocks[i].current_price);
    }

    // Simulate the stock prices changing
    for(int i = 0; i < 10; i++){
        float random_change = ((float) rand()/RAND_MAX)*10 - 5;
        stocks[i].previous_price = stocks[i].current_price;
        stocks[i].current_price += random_change;
    }

    // Save the new data to the file
    data_file = fopen("stock_data.txt", "w");
    for(int i = 0; i < 10; i++){
        fprintf(data_file, "%s:%f:%f\n", stocks[i].name, stocks[i].current_price, stocks[i].previous_price);
    }
    fclose(data_file);

    // Display the stock data again
    printf("Updated Stock Prices:\n");
    for(int i = 0; i < 10; i++){
        printf("%s: %.2f\n", stocks[i].name, stocks[i].current_price);
    }

    return 0;
}