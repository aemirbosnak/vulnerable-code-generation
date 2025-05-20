//FormAI DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOL_LEN 5
#define MAX_NAME_LEN 50
#define MAX_RECORDS 100

typedef struct {
    char symbol[MAX_SYMBOL_LEN];
    char name[MAX_NAME_LEN];
    double price;
    double high;
    double low;
} stock_record;

int main() {
    stock_record records[MAX_RECORDS];
    int num_records = 0;

    // read data from file
    FILE *file = fopen("stocks.txt", "r");
    if (file) {
        char buffer[256];
        while (fgets(buffer, 256, file)) {
            if (num_records < MAX_RECORDS) {
                char *token = strtok(buffer, ",");
                strncpy(records[num_records].symbol, token, MAX_SYMBOL_LEN);
                token = strtok(NULL, ",");
                strncpy(records[num_records].name, token, MAX_NAME_LEN);
                token = strtok(NULL, ",");
                records[num_records].price = atof(token);
                token = strtok(NULL, ",");
                records[num_records].high = atof(token);
                token = strtok(NULL, ",");
                records[num_records].low = atof(token);
                num_records++;
            }
        }
        fclose(file);
    }

    // main program loop
    int choice = 0;
    char symbol[MAX_SYMBOL_LEN];
    while (choice != 4) {
        printf("\nStock Market Tracker\n");
        printf("--------------------\n");
        printf("1. List all stocks\n");
        printf("2. Search for a stock\n");
        printf("3. Add a new stock\n");
        printf("4. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // eat the newline

        switch (choice) {
            case 1:
                printf("\nAll Stocks\n");
                printf("----------\n");
                for (int i = 0; i < num_records; i++) {
                    printf("%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", 
                           records[i].symbol, records[i].name,
                           records[i].price, records[i].high, records[i].low);
                }
                break;
            case 2:
                printf("Enter the symbol of the stock to search: ");
                fgets(symbol, MAX_SYMBOL_LEN+1, stdin);
                for (int i = 0; i < strlen(symbol); i++) {
                    symbol[i] = toupper(symbol[i]); // convert to uppercase
                }
                int found = 0;
                for (int i = 0; i < num_records; i++) {
                    if (strcmp(records[i].symbol, symbol) == 0) {
                        found = 1;
                        printf("\n%s\t%s\t%.2lf\t%.2lf\t%.2lf\n",
                               records[i].symbol, records[i].name,
                               records[i].price, records[i].high, records[i].low);
                        break;
                    }
                }
                if (!found) {
                    printf("Stock symbol not found.\n");
                }
                break;
            case 3:
                if (num_records < MAX_RECORDS) {
                    printf("Enter the symbol of the new stock: ");
                    fgets(records[num_records].symbol, MAX_SYMBOL_LEN+1, stdin);
                    for (int i = 0; i < strlen(records[num_records].symbol); i++) {
                        records[num_records].symbol[i] = toupper(records[num_records].symbol[i]); // convert to uppercase
                    }
                    printf("Enter the name of the new stock: ");
                    fgets(records[num_records].name, MAX_NAME_LEN+1, stdin);
                    printf("Enter the price of the new stock: ");
                    scanf("%lf", &records[num_records].price);
                    getchar();  // eat the newline
                    printf("Enter the high of the new stock: ");
                    scanf("%lf", &records[num_records].high);
                    getchar();  // eat the newline
                    printf("Enter the low of the new stock: ");
                    scanf("%lf", &records[num_records].low);
                    getchar();  // eat the newline
                    num_records++;
                    printf("Stock added successfully.\n");
                } else {
                    printf("Maximum number of records reached.\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    
    // write data to file
    file = fopen("stocks.txt", "w");
    if (file) {
        for (int i = 0; i < num_records; i++) {
            fprintf(file, "%s,%s,%.2lf,%.2lf,%.2lf\n", 
                    records[i].symbol, records[i].name,
                    records[i].price, records[i].high, records[i].low);
        }
        fclose(file);
    }

    return 0;
}