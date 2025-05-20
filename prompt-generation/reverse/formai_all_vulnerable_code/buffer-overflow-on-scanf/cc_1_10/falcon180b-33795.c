//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    double change;
    double percentage_change;
} stock_t;

stock_t stocks[MAX_STOCKS];

void update_stock_data(int index) {
    char url[100];
    sprintf(url, "https://api.example.com/stocks/%s", stocks[index].symbol);

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(url, "r");
    if (fp == NULL) {
        printf("Error: Could not open URL.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        if (strstr(line, "\"price\":")!= NULL) {
            char *price_str = strstr(line, "\"price\":") + strlen("\"price\":");
            stocks[index].price = atof(price_str);

            char *change_str = strstr(line, "\"change\":");
            stocks[index].change = atof(change_str + strlen("\"change\":"));

            char *percentage_change_str = strstr(line, "\"percentage_change\":");
            stocks[index].percentage_change = atof(percentage_change_str + strlen("\"percentage_change\":"));
        }
    }

    fclose(fp);
}

void print_stock_data(int index) {
    printf("%s (%s)\n", stocks[index].name, stocks[index].symbol);
    printf("Price: $%.2f\n", stocks[index].price);
    printf("Change: $%.2f (%+.2f%%)\n", stocks[index].change, stocks[index].percentage_change * 100);
}

int main() {
    int num_stocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i + 1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock %d: ", i + 1);
        scanf("%s", stocks[i].symbol);
    }

    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    printf("\nCurrent time: %s\n", asctime(local_time));

    for (int i = 0; i < num_stocks; i++) {
        update_stock_data(i);
        print_stock_data(i);
    }

    return 0;
}