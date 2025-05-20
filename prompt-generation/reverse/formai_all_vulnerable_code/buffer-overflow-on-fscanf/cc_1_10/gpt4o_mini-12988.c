//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
    double change;
} Stock;

Stock stocks[MAX_STOCKS];
int stock_count = 0;

void add_stock(const char *name, double price) {
    if (stock_count >= MAX_STOCKS) {
        printf("Cannot add more stocks, limit reached!\n");
        return;
    }
    strncpy(stocks[stock_count].name, name, MAX_NAME_LEN);
    stocks[stock_count].price = price;
    stocks[stock_count].change = 0.0; // Initialize change
    stock_count++;
}

void update_stock(const char *name, double new_price) {
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].change = new_price - stocks[i].price; // Calculate price change
            stocks[i].price = new_price; // Update the price
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void display_stocks() {
    printf("\n---- Stock Market Tracker ----\n");
    printf("------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Stock Name", "Price ($)", "Change ($)");
    printf("------------------------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        printf("| %-20s | %-10.2f | %-10.2f |\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("------------------------------------------------\n");
}

void load_stocks_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char name[MAX_NAME_LEN];
    double price;

    while (fscanf(file, "%49s %lf", name, &price) != EOF) {
        add_stock(name, price);
    }

    fclose(file);
}

void save_stocks_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%s %.2f\n", stocks[i].name, stocks[i].price);
    }

    fclose(file);
}

void simulate_market() {
    // Simulate random updates for demonstration
    for (int i = 0; i < stock_count; i++) {
        double random_change = ((rand() % 200) - 100) / 100.0; // Random change between -1 and 1
        update_stock(stocks[i].name, stocks[i].price + random_change);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <stocks_data_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    load_stocks_from_file(argv[1]);
    display_stocks();

    char command[MAX_NAME_LEN + 20];
    
    while (1) {
        printf("Enter a command (update, display, simulate, save, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "display") == 0) {
            display_stocks();
        } else if (strcmp(command, "simulate") == 0) {
            simulate_market();
            printf("Market simulated.\n");
        } else if (strncmp(command, "update", 6) == 0) {
            char stock_name[MAX_NAME_LEN];
            double new_price;
            sscanf(command, "update %49s %lf", stock_name, &new_price);
            update_stock(stock_name, new_price);
        } else if (strcmp(command, "save") == 0) {
            save_stocks_to_file(argv[1]);
            printf("Stocks saved to file.\n");
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the stock market tracker.\n");
            break;
        } else {
            printf("Unknown command!\n");
        }
    }

    return EXIT_SUCCESS;
}