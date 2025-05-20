//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for storing stock market data
struct StockData {
    char symbol[6];
    float price;
    int volume;
    char date[11];
};

// Function to read stock market data from a file and store it in an array of StockData structs
int ReadDataFromFile(char* filename, struct StockData* data) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("ERROR: Failed to open file.\n");
        return 0;
    }

    char line[100];
    int i = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s %f %d %s", data[i].symbol, &data[i].price, &data[i].volume, data[i].date);
        i++;
    }

    fclose(file);
    return i;
}

// Function to print out stock market data for a given date
void PrintDataForDate(struct StockData* data, int n, char* date) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].date, date) == 0) {
            printf("%s: $%.2f (%d shares traded)\n", data[i].symbol, data[i].price, data[i].volume);
            found = 1;
        }
    }

    if (!found) {
        printf("No data found for %s\n", date);
    }
}

int main() {
    struct StockData data[100];
    char filename[] = "stock_data.txt";
    int n = ReadDataFromFile(filename, data);

    if (n == 0) {
        return 1;
    }

    char date[11];
    printf("Enter a date (yyyy-mm-dd): ");
    scanf("%s", date);

    PrintDataForDate(data, n, date);

    return 0;
}