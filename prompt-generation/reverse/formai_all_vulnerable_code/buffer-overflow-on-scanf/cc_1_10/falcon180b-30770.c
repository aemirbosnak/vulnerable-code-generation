//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <curl/curl.h>

#define NUM_COMPANIES 10
#define API_KEY "your_api_key_here"

typedef struct {
    char symbol[10];
    double price;
} company_t;

company_t companies[NUM_COMPANIES] = {
    {"AAPL", 0.0},
    {"MSFT", 0.0},
    {"GOOG", 0.0},
    {"AMZN", 0.0},
    {"FB", 0.0},
    {"TSLA", 0.0},
    {"NFLX", 0.0},
    {"TWTR", 0.0},
    {"NVDA", 0.0},
    {"ADBE", 0.0}
};

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    return fwrite(ptr, size, nmemb, (FILE*)stream);
}

void get_stock_price(char* symbol) {
    char url[50];
    sprintf(url, "https://api.iextrading.com/1.0/stock/%s/quote?apikey=%s", symbol, API_KEY);

    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &companies[0]);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Stock price for %s retrieved successfully\n", symbol);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

void main() {
    int choice;
    char symbol[10];

    do {
        printf("\n==== STOCK MARKET TRACKER ====\n");
        printf("Enter the symbol of the company you want to track: ");
        scanf("%s", symbol);

        get_stock_price(symbol);

        printf("\nCurrent stock price for %s: $%.2f\n", symbol, companies[0].price);

        printf("\nDo you want to track another company? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
}