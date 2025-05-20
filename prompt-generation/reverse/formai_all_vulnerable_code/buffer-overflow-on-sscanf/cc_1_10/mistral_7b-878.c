//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMPANIES 100
#define MAX_SYMBOL_LEN 10
#define FILE_NAME "stock_prices.txt"

struct Company {
    char symbol[MAX_SYMBOL_LEN];
    float current_price;
    float previous_close;
    float change_percent;
};

void get_stock_prices(struct Company companies[MAX_COMPANIES]);
void print_stock_data(struct Company company);

int main(int argc, char *argv[]) {
    int num_companies = 0;
    struct Company companies[MAX_COMPANIES];

    if (access(FILE_NAME, F_OK) != -1) {
        printf("Reading stock prices from file...\n");
        get_stock_prices(companies);

        while (num_companies > 0) {
            print_stock_data(companies[--num_companies]);
            printf("\n");
        }
    } else {
        printf("File not found. Exiting...\n");
        return 1;
    }

    printf("\nPress any key to exit...\n");
    getchar();

    return 0;
}

void get_stock_prices(struct Company companies[]) {
    int i = 0;
    FILE *file = fopen(FILE_NAME, "r");

    if (file != NULL) {
        char line[1024];

        while (fgets(line, sizeof(line), file) != NULL) {
            if (sscanf(line, "%s %f %f %f", companies[i].symbol, &companies[i].previous_close, &companies[i].current_price, &companies[i].change_percent) != 4) {
                printf("Invalid line format: %s\n", line);
                break;
            }

            i++;
            if (i == MAX_COMPANIES) {
                printf("Max number of companies reached. Exiting...\n");
                break;
            }
        }

        fclose(file);
    }
}

void print_stock_data(struct Company company) {
    printf("\nCompany Symbol: %s", company.symbol);
    printf("\nPrevious Close: $%.2f", company.previous_close);
    printf("\nCurrent Price: $%.2f", company.current_price);
    printf("\nChange Percent: %.2f%%", company.change_percent);

    if (company.change_percent > 0) {
        printf("\nStock Price is UP!");
        printf("\n--------------------------------------------------\n");
    } else if (company.change_percent < 0) {
        printf("\nStock Price is DOWN!");
        printf("\n--------------------------------------------------\n");
    } else {
        printf("\nStock Price is unchanged!");
        printf("\n--------------------------------------------------\n");
    }
}