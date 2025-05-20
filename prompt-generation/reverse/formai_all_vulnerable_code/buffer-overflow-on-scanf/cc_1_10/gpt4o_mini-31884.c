//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define STOCK_NAME_SIZE 50

typedef struct {
    char name[STOCK_NAME_SIZE];
    float current_price;
    float open_price;
    float high_price;
    float low_price;
    long volume;
} Stock;

Stock stock_market[MAX_STOCKS];
int stock_count = 0;

void add_stock(const char *name, float open_price, float high_price, float low_price, long volume) {
    if (stock_count >= MAX_STOCKS) {
        printf("Stock market is full! Cannot add new stock.\n");
        return;
    }
    strncpy(stock_market[stock_count].name, name, STOCK_NAME_SIZE);
    stock_market[stock_count].open_price = open_price;
    stock_market[stock_count].current_price = open_price; // Initially, current price is the open price
    stock_market[stock_count].high_price = high_price;
    stock_market[stock_count].low_price = low_price;
    stock_market[stock_count].volume = volume;
    stock_count++;
}

void update_stock_price(const char *name, float new_price) {
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stock_market[i].name, name) == 0) {
            stock_market[i].current_price = new_price;
            if (new_price > stock_market[i].high_price) {
                stock_market[i].high_price = new_price;
            }
            if (new_price < stock_market[i].low_price) {
                stock_market[i].low_price = new_price;
            }
            printf("Price updated for %s: %.2f\n", name, new_price);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void display_stock_market() {
    printf("\nStock Market Tracker\n");
    printf("-----------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s %-10s %-10s\n", "Stock", "Open", "Current", "High", "Low", "Volume");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%-20s %-10.2f %-10.2f %-10.2f %-10.2f %-10ld\n", 
               stock_market[i].name, 
               stock_market[i].open_price, 
               stock_market[i].current_price, 
               stock_market[i].high_price, 
               stock_market[i].low_price, 
               stock_market[i].volume);
    }
    printf("-----------------------------------------------\n");
}

void save_stock_data(const char *file_name) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Could not open file for writing!\n");
        return;
    }
    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%s,%.2f,%.2f,%.2f,%.2f,%ld\n",
                stock_market[i].name,
                stock_market[i].open_price,
                stock_market[i].current_price,
                stock_market[i].high_price,
                stock_market[i].low_price,
                stock_market[i].volume);
    }
    fclose(file);
    printf("Stock data saved to %s\n", file_name);
}

void load_stock_data(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Could not open file for reading!\n");
        return;
    }
    while (!feof(file) && stock_count < MAX_STOCKS) {
        char line[256];
        if (fgets(line, sizeof(line), file)) {
            char name[STOCK_NAME_SIZE];
            float open_price, current_price, high_price, low_price;
            long volume;
            
            sscanf(line, "%49[^,],%f,%f,%f,%f,%ld", name, &open_price, &current_price, &high_price, &low_price, &volume);
            add_stock(name, open_price, high_price, low_price, volume);
        }
    }
    fclose(file);
}

int main() {
    int choice;
    char name[STOCK_NAME_SIZE];
    float price;
    char file_name[100];

    do {
        printf("\nStock Market Tracker Menu\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display Stock Market\n");
        printf("4. Save Stock Data to File\n");
        printf("5. Load Stock Data from File\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter open price: ");
                scanf("%f", &price);
                add_stock(name, price, price, price, 0);
                break;
            case 2:
                printf("Enter stock name to update: ");
                scanf("%s", name);
                printf("Enter new price: ");
                scanf("%f", &price);
                update_stock_price(name, price);
                break;
            case 3:
                display_stock_market();
                break;
            case 4:
                printf("Enter file name to save data: ");
                scanf("%s", file_name);
                save_stock_data(file_name);
                break;
            case 5:
                printf("Enter file name to load data: ");
                scanf("%s", file_name);
                load_stock_data(file_name);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}