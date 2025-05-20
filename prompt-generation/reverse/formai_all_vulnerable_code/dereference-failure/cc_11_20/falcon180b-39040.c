//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SYMBOLS 100
#define MAX_DATA_POINTS 1000

typedef struct {
    char symbol[10];
    double price;
    int volume;
} DataPoint;

int main() {
    FILE *fp;
    char line[1000];
    int num_symbols = 0, num_data_points = 0;
    char symbols[MAX_SYMBOLS][10];
    DataPoint data_points[MAX_DATA_POINTS];

    fp = fopen("stock_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read in the symbols
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        strcpy(symbols[num_symbols], token);
        num_symbols++;
    }

    // Initialize the data points
    for (int i = 0; i < num_symbols; i++) {
        strcpy(data_points[i].symbol, symbols[i]);
        data_points[i].price = 0.0;
        data_points[i].volume = 0;
    }

    // Read in the data points
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int symbol_index = -1;
        for (int i = 0; i < num_symbols; i++) {
            if (strcmp(symbols[i], token) == 0) {
                symbol_index = i;
                break;
            }
        }
        if (symbol_index == -1) {
            continue;
        }
        data_points[symbol_index].price = atof(strtok(NULL, ","));
        data_points[symbol_index].volume = atoi(strtok(NULL, ","));
        num_data_points++;
    }

    fclose(fp);

    printf("Number of symbols: %d\n", num_symbols);
    printf("Number of data points: %d\n", num_data_points);

    // Calculate the moving average for each symbol
    for (int i = 0; i < num_symbols; i++) {
        int num_points = num_data_points / num_symbols;
        double sum = 0.0;
        for (int j = 0; j < num_points; j++) {
            sum += data_points[i * num_points + j].price;
        }
        data_points[i].price = sum / num_points;
    }

    // Sort the data points by price
    for (int i = 0; i < num_symbols - 1; i++) {
        for (int j = 0; j < num_symbols - i - 1; j++) {
            if (data_points[j].price > data_points[j + 1].price) {
                DataPoint temp = data_points[j];
                data_points[j] = data_points[j + 1];
                data_points[j + 1] = temp;
            }
        }
    }

    // Print the results
    printf("\n");
    for (int i = 0; i < num_symbols; i++) {
        printf("%s %.2f %d\n", data_points[i].symbol, data_points[i].price, data_points[i].volume);
    }

    return 0;
}