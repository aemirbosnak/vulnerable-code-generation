//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_SYMBOLS 100
#define BUF_SIZE 1024

struct Stock {
    char symbol[5];
    float lastPrice;
    float change;
};

void printHeader() {
    printf("\n*************************************************\n");
    printf("*              StockHappiness Tracker            *\n");
    printf("*                                               *\n");
    printf("*    _____ _____ _____ _____ _____ _____ _____ *\n");
    printf("*   |   __|_   _|_   _|_   _|_   _|_   _|_   | *\n");
    printf("*   |  |  | |  |  | |  | |  | |  | |  | |  | | *\n");
    printf("*   |  |  |_|  |_|  |_|  |_|  |_|  |_|  |_|  | | *\n");
    printf("*   |__|   __|__|__|__|__|__|__|__|__|__|__| |*\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
}

void readStocks(FILE *file, struct Stock stocks[MAX_SYMBOLS]) {
    int i = 0;
    char line[BUF_SIZE];

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s %f %f", stocks[i].symbol, &stocks[i].lastPrice, &stocks[i].change);
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printHeader();
    struct Stock stocks[MAX_SYMBOLS];
    readStocks(file, stocks);
    fclose(file);

    printf("+---------------------------------------+\n");
    printf("| Stock Symbol | Last Price | Change     |\n");
    printf("+---------------------------------------+\n");

    for (int i = 0; i < argc - 1; i++) {
        if (strlen(argv[i + 1]) >= 5) {
            printf("| %-10s | %10.2f | %+6.2f |\n", argv[i + 1], stocks[i].lastPrice, stocks[i].change);
        }
    }

    printf("+---------------------------------------+\n");

    return 0;
}