//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menuItems[][20] = {"Americano", "Cappuccino", "Espresso", "Latte", "Mocha"};
float menuPrices[] = {4.00, 5.00, 3.00, 4.50, 5.50};

// Define the function to get the user's order
void getOrder(int *numItems, char orderItems[][20], float *total) {
    int num;
    char item[20];
    float price;

    *numItems = 0;
    *total = 0.00;

    printf("Welcome to the Cafe!\n");
    printf("---------------------\n");

    while (1) {
        printf("Enter the number of items you want to order: ");
        scanf("%d", &num);

        if (num <= 0) {
            break;
        }

        for (int i = 0; i < num; i++) {
            printf("Enter the name of item %d: ", i + 1);
            scanf("%s", item);

            // Find the price of the item
            for (int j = 0; j < 5; j++) {
                if (strcmp(item, menuItems[j]) == 0) {
                    price = menuPrices[j];
                }
            }

            // Add the item to the order and update the total
            strcpy(orderItems[*numItems], item);
            *total += price;
            *numItems += 1;
        }
    }
}

// Define the function to print the bill
void printBill(int numItems, char orderItems[][20], float total) {
    printf("\nYour Order:\n");
    printf("---------------------\n");

    for (int i = 0; i < numItems; i++) {
        printf("%s: $%.2f\n", orderItems[i], menuPrices[i]);
    }

    printf("---------------------\n");
    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    int numItems;
    char orderItems[10][20];
    float total;

    getOrder(&numItems, orderItems, &total);
    printBill(numItems, orderItems, total);

    return 0;
}