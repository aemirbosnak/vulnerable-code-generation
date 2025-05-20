//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char symbol[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} stock_t;

int main() {
    int num_symbols = 0;
    stock_t *symbols = NULL;

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open stocks file.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_symbols >= MAX_SYMBOLS) {
            printf("Error: Too many symbols in file.\n");
            exit(1);
        }

        char *token = strtok(line, ",");
        strcpy(symbols[num_symbols].symbol, token);

        token = strtok(NULL, ",");
        strcpy(symbols[num_symbols].name, token);

        token = strtok(NULL, ",");
        strcpy(symbols[num_symbols].price, token);

        num_symbols++;
    }

    fclose(fp);

    int choice;
    while (1) {
        printf("1. Display all symbols\n");
        printf("2. Search for a symbol\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (int i = 0; i < num_symbols; i++) {
                printf("%s,%s,%.2f\n", symbols[i].symbol, symbols[i].name, atof(symbols[i].price));
            }
            break;

        case 2:
            printf("Enter a symbol to search for: ");
            char search_symbol[MAX_NAME_LEN];
            scanf("%s", search_symbol);

            for (int i = 0; i < num_symbols; i++) {
                if (strcmp(symbols[i].symbol, search_symbol) == 0) {
                    printf("%s,%s,%.2f\n", symbols[i].symbol, symbols[i].name, atof(symbols[i].price));
                }
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}