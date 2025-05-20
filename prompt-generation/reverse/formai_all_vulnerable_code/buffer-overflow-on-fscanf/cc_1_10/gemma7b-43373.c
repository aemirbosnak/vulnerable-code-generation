//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_NUM 10

typedef struct Stock
{
    char name[20];
    double price;
    double change;
    double prev_price;
} Stock;

Stock stocks[MAX_STOCK_NUM];

void update_stocks()
{
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    int i = 0;
    stocks[i].name[0] = '\0';
    while (fscanf(fp, "%s %lf %lf %lf\n", stocks[i].name, &stocks[i].price, &stocks[i].change, &stocks[i].prev_price) != EOF)
    {
        i++;
    }

    fclose(fp);
}

void print_stocks()
{
    printf("----------------------------------------\n");
    printf("Stock List\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        if (stocks[i].name[0] != '\0')
        {
            printf("%-20s: %.2lf (%.2lf%%)\n", stocks[i].name, stocks[i].price, stocks[i].change);
        }
    }
}

int main()
{
    update_stocks();
    print_stocks();

    return 0;
}