//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <string.h>

// Function to calculate the total cost
float calculateTotal(float price[], int quantity[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += price[i] * quantity[i];
    }
    return total;
}

// Function to print the bill
void printBill(float price[], int quantity[], char items[][100], int count) {
    printf("\n\n*****************************\n");
    printf("           Bill\n");
    printf("*****************************\n");
    printf("Items          Quantity   Price\n");

    for (int i = 0; i < count; i++) {
        printf("%-15s %-8d %.2f\n", items[i], quantity[i], price[i]);
    }

    float total = calculateTotal(price, quantity, count);

    printf("\nTotal Cost: %.2f\n", total);
}

int main() {
    // Declare variables
    char items[10][100];
    int quantity[10];
    float price[10];
    char answer[10];
    int count = 0;

    // Loop to keep asking for items
    do {
        // Get item name
        printf("Enter item name: ");
        scanf("%s", items[count]);

        // Get item quantity
        printf("Enter quantity: ");
        scanf("%d", &quantity[count]);

        // Get item price
        printf("Enter price: ");
        scanf("%f", &price[count]);

        // Ask if user wants to add more items
        printf("Add more items? (yes/no): ");
        scanf("%s", answer);

        count++;
    } while (strcmp(answer, "yes") == 0);

    // Print the bill
    printBill(price, quantity, items, count);

    return 0;
}