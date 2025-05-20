//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock_data {
    char ticker[10];
    float price;
};

int read_data(struct stock_data *data);
void print_data(struct stock_data *data, int count);

int main() {
    int count = 0;
    struct stock_data data[100];

    count = read_data(data);
    print_data(data, count);

    return 0;
}

int read_data(struct stock_data *data) {
    FILE *fp;
    char filename[50];
    int count = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while(fscanf(fp, "%s %f", data[count].ticker, &data[count].price) == 2) {
        count++;
    }

    fclose(fp);

    return count;
}

void print_data(struct stock_data *data, int count) {
    int i;

    printf("Ticker\tPrice\n");
    for(i = 0; i < count; i++) {
        printf("%s\t%.2f\n", data[i].ticker, data[i].price);
    }
}