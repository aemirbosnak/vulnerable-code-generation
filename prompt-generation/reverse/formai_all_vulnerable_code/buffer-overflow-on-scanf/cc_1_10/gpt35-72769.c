//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

#define TAX_RATE 0.05

// Structure to hold menu items
struct MenuItem {
    char name[20];
    int price;
    int quantity;
};
typedef struct MenuItem MenuItem;

// Function prototypes
void addNewItem(MenuItem items[], int numItems);
void displayMenu(MenuItem items[], int numItems);
void generateBill(MenuItem items[], int numItems, int itemQuantities[]);
void printLine(char ch);

int main() {
    int numItems, choice;
    printf("*** Welcome to Cafe Billing System! ***\n\n");
    printf("Enter the number of items in the menu: ");
    scanf("%d", &numItems);
    MenuItem items[numItems];
    for(int i = 0; i < numItems; i++) {
        addNewItem(items, i);
    }
    while(1) {
        printf("\n\tMenu Options\n");
        printf("1. Display Menu\n");
        printf("2. Generate Bill\n");
        printf("3. Exit\n");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: displayMenu(items, numItems); break;
            case 2: {
                int itemQuantities[numItems];
                generateBill(items, numItems, itemQuantities); 
                break;
            }
            case 3: {
                printf("\n*** Thank you for using Cafe Billing System. Goodbye! ***\n");
                exit(0); 
            }
            default: printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to add a new item to the menu
void addNewItem(MenuItem items[], int numItems) {
    printf("\nEnter details for Item %d:\n", numItems+1);
    printf("Name: ");
    scanf("%s", items[numItems].name);
    printf("Price: ");
    scanf("%d", &items[numItems].price);
    items[numItems].quantity = 0;
}

// Function to display the menu
void displayMenu(MenuItem items[], int numItems) {
    printf("\n\tMenu\n");
    printLine('=');
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Quantity");
    printLine('=');
    for(int i = 0; i < numItems; i++) {
        printf("%-20s $%-9d %-10d\n", items[i].name, items[i].price, items[i].quantity);
    }
    printLine('=');
}

// Function to generate the bill
void generateBill(MenuItem items[], int numItems, int itemQuantities[]) {
    printf("\nEnter the quantities of items:");
    int totalAmount = 0;
    for(int i = 0; i < numItems; i++) {
        printf("\n%s: ", items[i].name);
        scanf("%d", &itemQuantities[i]);
        items[i].quantity += itemQuantities[i];
        totalAmount += itemQuantities[i] * items[i].price;
    }
    printf("\n\tBill\n");
    printLine('=');
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Price", "Quantity", "Amount");
    printLine('=');
    for(int i = 0; i < numItems; i++) {
        if(itemQuantities[i] != 0) {
            printf("%-20s $%-9d %-10d $%-9d\n", items[i].name, items[i].price, itemQuantities[i], items[i].price * itemQuantities[i]);
        }
    }
    printLine('=');
    float taxAmount = TAX_RATE * totalAmount;
    float grandTotal = totalAmount + taxAmount;
    printf("%-41s $%-9d\n", "Total", totalAmount);
    printf("%-41s $%-9.2f\n", "Tax (" "5%)", taxAmount);
    printf("%-41s $%-9.2f\n", "Grand Total", grandTotal);
}

// Function to print a line of characters
void printLine(char ch) {
    for(int i = 0; i < 50; i++) {
        printf("%c", ch);
    }
    printf("\n");
}