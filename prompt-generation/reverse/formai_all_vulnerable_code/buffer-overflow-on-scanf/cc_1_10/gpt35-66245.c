//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 100 // maximum items that can be stored in the stock

struct medicine {
    char name[50];
    int quantity;
    float price;
};

int num_medicines = 0;
struct medicine stock[MAX_STOCK];

void add_medicine() {
    if (num_medicines == MAX_STOCK) {
        printf("Stock is full. Cannot add more medicines.\n");
        return;
    }

    struct medicine med;

    printf("Enter medicine name: ");
    scanf("%s", med.name);

    printf("Enter quantity: ");
    scanf("%d", &med.quantity);

    printf("Enter price: ");
    scanf("%f", &med.price);

    stock[num_medicines++] = med;

    printf("Medicine added successfully.\n");
}

void sell_medicine() {
    char med_name[50];
    int quantity_to_sell;

    printf("Enter medicine name to sell: ");
    scanf("%s", med_name);

    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(stock[i].name, med_name) == 0) {
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity_to_sell);

            if (quantity_to_sell > stock[i].quantity) {
                printf("Insufficient stock. Cannot sell %d %s.\n", quantity_to_sell, med_name);
                return;
            }

            stock[i].quantity -= quantity_to_sell;
            printf("%d %s sold successfully for Rs. %.2f\n", quantity_to_sell, med_name, quantity_to_sell * stock[i].price);
            return;
        }
    }

    printf("Medicine not found in the stock.\n");
}

void display_medicines() {
    if (num_medicines == 0) {
        printf("No medicines in the stock.\n");
        return;
    }

    printf("Name\t\tQuantity\t\tPrice\n");

    for (int i = 0; i < num_medicines; i++) {
        printf("%s\t\t%d\t\t\t%.2f\n", stock[i].name, stock[i].quantity, stock[i].price);
    }
}

int main() {
    while (1) {
        printf("\n1. Add medicine\n2. Sell medicine\n3. Display medicines\n4. Exit\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                sell_medicine();
                break;
            case 3:
                display_medicines();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}