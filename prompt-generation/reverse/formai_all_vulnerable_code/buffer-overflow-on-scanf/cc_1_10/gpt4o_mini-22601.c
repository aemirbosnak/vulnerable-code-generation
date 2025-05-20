//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct Stock {
    char name[MAX_NAME_LENGTH];
    float price;
    struct Stock* next;
} Stock;

Stock* head = NULL;

Stock* create_stock(const char* name, float price) {
    Stock* new_stock = (Stock*)malloc(sizeof(Stock));
    strncpy(new_stock->name, name, MAX_NAME_LENGTH);
    new_stock->price = price;
    new_stock->next = NULL;
    return new_stock;
}

void add_stock(const char* name, float price) {
    Stock* new_stock = create_stock(name, price);
    if (head == NULL) {
        head = new_stock;
    } else {
        Stock* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_stock;
    }
    printf("Stock %s added with price $%.2f\n", name, price);
}

void update_stock_price(const char* name, float new_price) {
    Stock* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            temp->price = new_price;
            printf("Stock %s updated to price $%.2f\n", name, new_price);
            return;
        }
        temp = temp->next;
    }
    printf("Stock %s not found\n", name);
}

void view_stocks() {
    if (head == NULL) {
        printf("No stocks available.\n");
        return;
    }
    printf("Current Stocks:\n");
    Stock* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Price: $%.2f\n", temp->name, temp->price);
        temp = temp->next;
    }
}

void free_stocks() {
    Stock* current = head;
    Stock* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

void display_menu() {
    printf("\nStock Market Tracker\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Stocks\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    float price;

    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                add_stock(name, price);
                break;
            case 2:
                printf("Enter stock name to update: ");
                scanf("%s", name);
                printf("Enter new stock price: ");
                scanf("%f", &price);
                update_stock_price(name, price);
                break;
            case 3:
                view_stocks();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    free_stocks();
    return 0;
}