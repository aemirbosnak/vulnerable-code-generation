//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_STOCKS 10
#define MAX_DATA_POINTS 100

struct stock_data {
    char symbol[10];
    float price;
    time_t timestamp;
};

struct stock_data stocks[MAX_STOCKS];
int num_stocks = 0;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((struct stock_data*)userp)->timestamp = time(NULL);
    return size * nmemb;
}

void get_stock_data(char* symbol)
{
    CURL* curl = curl_easy_init();
    if (curl) {
        char url[50];
        sprintf(url, "https://api.iextrading.com/1.0/stock/%s/quote", symbol);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stocks[num_stocks]);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        num_stocks++;
    }
}

void display_stock_data()
{
    printf("Stock Data:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s %.2f %s\n", stocks[i].symbol, stocks[i].price, ctime(&stocks[i].timestamp));
    }
}

int main()
{
    system("clear");
    char symbol[10];
    int choice;
    do {
        printf("Enter stock symbol (or 0 to exit): ");
        scanf("%s", symbol);
        if (symbol[0]!= '0') {
            get_stock_data(symbol);
        }
        printf("1. Display stock data\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_stock_data();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 0);
    return 0;
}