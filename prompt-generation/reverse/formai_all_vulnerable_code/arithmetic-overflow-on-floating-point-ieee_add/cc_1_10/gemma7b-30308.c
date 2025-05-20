//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    printf("#################################################\n");
    printf("C Cafe Billing System\n");
    printf("#################################################\n");

    // Declare variables
    int item_no;
    char item_name[50];
    float item_price;
    int quantity;
    float total_amount = 0;

    // Get item number
    printf("Enter item number: ");
    scanf("%d", &item_no);

    // Get item name
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Get item price
    printf("Enter item price: ");
    scanf("%f", &item_price);

    // Get quantity
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Calculate total amount
    total_amount = item_price * quantity;

    // Display bill
    printf("---------------------------------------------------\n");
    printf("Item No: %d\n", item_no);
    printf("Item Name: %s\n", item_name);
    printf("Item Price: %.2f\n", item_price);
    printf("Quantity: %d\n", quantity);
    printf("Total Amount: %.2f\n", total_amount);
    printf("---------------------------------------------------\n");

    // Calculate tax and tip
    float tax = total_amount * 0.1;
    float tip = total_amount * 0.15;

    // Display tax and tip
    printf("Tax: %.2f\n", tax);
    printf("Tip: %.2f\n", tip);

    // Calculate total payment
    float total_payment = total_amount + tax + tip;

    // Display total payment
    printf("Total Payment: %.2f\n", total_payment);

    // Print receipt
    printf("Thank you for your visit to C Cafe!\n");
    printf("Please collect your receipt below:\n");

    // Print receipt information
    printf("Item No: %d\n", item_no);
    printf("Item Name: %s\n", item_name);
    printf("Item Price: %.2f\n", item_price);
    printf("Quantity: %d\n", quantity);
    printf("Total Amount: %.2f\n", total_amount);
    printf("Tax: %.2f\n", tax);
    printf("Tip: %.2f\n", tip);
    printf("Total Payment: %.2f\n", total_payment);

    return 0;
}