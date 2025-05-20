//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define FILENAME "stock.txt"

// Struct to hold stock information
typedef struct {
    char symbol[5];
    float price;
    int change;
} Stock;

// Function to read stock data from file
void read_data(void) {
    int fd = open(FILENAME, O_RDONLY);
    char line[MAX_LINE];
    Stock stock;

    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE, fd) != NULL) {
        if (sscanf(line, "%s %f %d", stock.symbol, &stock.price, &stock.change) != 3) {
            continue;
        }

        printf("Symbol: %s\n", stock.symbol);
        printf("Price: %.2f\n", stock.price);
        printf("Change: %d\n", stock.change);
        printf("\n");
    }

    close(fd);
}

int main() {
    printf("\n***** STOCK MARKET TRACKER *****\n\n");
    read_data();

    // Add your code here to update the stock data in the file

    return EXIT_SUCCESS;
}