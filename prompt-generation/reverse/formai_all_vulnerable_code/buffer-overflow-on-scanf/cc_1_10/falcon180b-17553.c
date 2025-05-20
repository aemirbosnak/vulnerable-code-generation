//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} stock_t;

int main() {
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter stock #%d information:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Price: ");
        scanf("%s", stocks[i].price);
        printf("Volume: ");
        scanf("%s", stocks[i].volume);
    }

    printf("\nStock Market Tracker\n");
    printf("=====================\n");

    while (1) {
        system("clear");
        printf("\n");

        for (int i = 0; i < num_stocks; i++) {
            printf("%d. %s\n", i+1, stocks[i].name);
            printf("Price: $%s\n", stocks[i].price);
            printf("Volume: %s\n\n", stocks[i].volume);
        }

        printf("Press any key to update prices...\n");
        getchar();

        for (int i = 0; i < num_stocks; i++) {
            char url[50];
            sprintf(url, "https://api.iextrading.com/1.0/stock/%s/quote", stocks[i].name);

            FILE *fp;
            char *line = NULL;
            size_t len = 0;
            ssize_t read;

            fp = fopen(url, "r");
            if (fp!= NULL) {
                while ((read = getline(&line, &len, fp))!= -1) {
                    if (strstr(line, "\"price\":")!= NULL) {
                        char *price_str = strstr(line, "\"price\":") + 9;
                        strncpy(stocks[i].price, price_str, MAX_PRICE_LEN);
                    } else if (strstr(line, "\"volume\":")!= NULL) {
                        char *volume_str = strstr(line, "\"volume\":") + 9;
                        strncpy(stocks[i].volume, volume_str, MAX_VOLUME_LEN);
                    }
                }
                fclose(fp);
            }
        }
    }

    return 0;
}