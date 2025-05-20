//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    Product *product;
    int quantity;
} Order;

typedef struct {
    int id;
    char name[50];
    float total;
    Order *orders;
    int ordersCount;
} Table;

// Functions
void printMenu(Product *products, int size) {
    printf("Menu\n");
    printf("----\n");
    for(int i = 0; i < size; i++) {
        printf("%d. %-20s - $%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

int selectProduct(Product *products, int size) {
    int choice;
    do {
        printf("Enter product ID: ");
        scanf("%d", &choice);
        // Check if choice is valid
        for(int i = 0; i < size; i++) {
            if(products[i].id == choice) {
                return i; // Return index
            }
        }
        printf("Invalid choice, please try again.\n");
    } while(1);
}

int selectTable(Table *tables, int size) {
    int choice;
    do {
        printf("Enter table ID: ");
        scanf("%d", &choice);
        // Check if choice is valid
        for(int i = 0; i < size; i++) {
            if(tables[i].id == choice) {
                return i; // Return index
            }
        }
        printf("Invalid choice, please try again.\n");
    } while(1);
}

void addToOrder(Order *order, Product *product) {
    order->product = product;
    order->quantity++;
}

void printOrder(Order *orders, int size) {
    float total = 0;
    printf("Order\n");
    printf("-----\n");
    for(int i = 0; i < size; i++) {
        printf("%d x %-20s - $%.2f\n", orders[i].quantity, orders[i].product->name, orders[i].product->price * orders[i].quantity);
        total += orders[i].product->price * orders[i].quantity;
    }
    printf("Total: $%.2f\n", total);
}

void printTables(Table *tables, int size) {
    printf("Tables\n");
    printf("------\n");
    for(int i = 0; i < size; i++) {
        printf("%d. %-20s - $%.2f\n", tables[i].id, tables[i].name, tables[i].total);
    }
}

int main() {
    // Initialize products
    Product products[5] = {
        {1, "Coffee", 2.50},
        {2, "Tea", 2.00},
        {3, "Juice", 3.00},
        {4, "Sandwich", 5.00},
        {5, "Cake", 4.00}
    };
    int productsSize = sizeof(products) / sizeof(Product);

    // Initialize tables
    Table tables[3] = {
        {1, "Table 1", 0, NULL, 0},
        {2, "Table 2", 0, NULL, 0},
        {3, "Table 3", 0, NULL, 0}
    };
    int tablesSize = sizeof(tables) / sizeof(Table);

    int choice;
    int tableIndex;
    int productIndex;

    while(1) {
        // Print main menu
        printf("\nMain Menu\n");
        printf("---------\n");
        printf("1. View menu\n");
        printf("2. Take order\n");
        printf("3. View tables\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // View menu
                printMenu(products, productsSize);
                break;
            case 2:
                // Take order
                tableIndex = selectTable(tables, tablesSize);
                productIndex = selectProduct(products, productsSize);
                addToOrder(&tables[tableIndex].orders[tables[tableIndex].ordersCount], &products[productIndex]);
                tables[tableIndex].ordersCount++;
                printf("Order added to table %d.\n", tables[tableIndex].id);
                break;
            case 3:
                // View tables
                printTables(tables, tablesSize);
                tableIndex = selectTable(tables, tablesSize);
                printOrder(tables[tableIndex].orders, tables[tableIndex].ordersCount);
                break;
            case 4:
                // Exit
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}