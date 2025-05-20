//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items
struct MenuItem {
    char name[20];
    float price;
};

// Define the table items
struct TableItem {
    int tableNumber;
    char customerName[20];
    struct MenuItem items[10];
    int itemCount;
    float total;
};

// Define the cafe structure
struct Cafe {
    struct TableItem tables[10];
    int tableCount;
    float totalSales;
};

// Function to create a new cafe
struct Cafe* createCafe() {
    struct Cafe* cafe = (struct Cafe*)malloc(sizeof(struct Cafe));
    cafe->tableCount = 0;
    cafe->totalSales = 0;
    return cafe;
}

// Function to add a new table to the cafe
void addTable(struct Cafe* cafe) {
    if (cafe->tableCount == 10) {
        printf("Sorry, the cafe is full.\n");
        return;
    }

    int tableNumber;
    printf("Enter the table number: ");
    scanf("%d", &tableNumber);

    char customerName[20];
    printf("Enter the customer name: ");
    scanf("%s", customerName);

    struct TableItem table;
    table.tableNumber = tableNumber;
    strcpy(table.customerName, customerName);
    table.itemCount = 0;
    table.total = 0;

    cafe->tables[cafe->tableCount++] = table;
}

// Function to add an item to a table
void addItem(struct Cafe* cafe) {
    int tableNumber;
    printf("Enter the table number: ");
    scanf("%d", &tableNumber);

    int itemNumber;
    printf("Enter the item number: ");
    scanf("%d", &itemNumber);

    struct MenuItem item;
    printf("Enter the item name: ");
    scanf("%s", item.name);
    printf("Enter the item price: ");
    scanf("%f", &item.price);

    int quantity;
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    struct TableItem* table = &cafe->tables[tableNumber - 1];
    table->items[table->itemCount++] = item;
    table->total += item.price * quantity;
}

// Function to remove an item from a table
void removeItem(struct Cafe* cafe) {
    int tableNumber;
    printf("Enter the table number: ");
    scanf("%d", &tableNumber);

    int itemNumber;
    printf("Enter the item number: ");
    scanf("%d", &itemNumber);

    struct TableItem* table = &cafe->tables[tableNumber - 1];
    for (int i = 0; i < table->itemCount; i++) {
        if (table->items[i].name == itemNumber) {
            table->total -= table->items[i].price;
            for (int j = i; j < table->itemCount - 1; j++) {
                table->items[j] = table->items[j + 1];
            }
            table->itemCount--;
            break;
        }
    }
}

// Function to print the bill for a table
void printBill(struct Cafe* cafe) {
    int tableNumber;
    printf("Enter the table number: ");
    scanf("%d", &tableNumber);

    struct TableItem table = cafe->tables[tableNumber - 1];

    printf("Table Number: %d\n", table.tableNumber);
    printf("Customer Name: %s\n", table.customerName);
    printf("Items:\n");
    for (int i = 0; i < table.itemCount; i++) {
        printf("%s - %.2f\n", table.items[i].name, table.items[i].price);
    }
    printf("Total: %.2f\n", table.total);

    cafe->totalSales += table.total;
}

// Function to print the sales report for the cafe
void printSalesReport(struct Cafe* cafe) {
    printf("Total Sales: %.2f\n", cafe->totalSales);
}

// Main function
int main() {
    // Create a new cafe
    struct Cafe* cafe = createCafe();

    // Add some tables to the cafe
    addTable(cafe);
    addTable(cafe);

    // Add some items to the tables
    addItem(cafe);
    addItem(cafe);

    // Remove an item from a table
    removeItem(cafe);

    // Print the bill for a table
    printBill(cafe);

    // Print the sales report for the cafe
    printSalesReport(cafe);

    return 0;
}