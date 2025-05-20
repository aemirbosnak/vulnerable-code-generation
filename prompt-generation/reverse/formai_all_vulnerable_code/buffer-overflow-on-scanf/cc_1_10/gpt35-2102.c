//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define item struct
typedef struct {
    char name[20];
    float price;
    int quantity;
} Item;

// Function to add item to the bill
void addItem(Item *bill[], int *count) {
    // Allocate memory for new item
    Item *newItem = malloc(sizeof(Item));
    printf("\nEnter item name: ");
    scanf("%s", newItem->name);
    printf("Enter item price: ");
    scanf("%f", &newItem->price);
    printf("Enter item quantity: ");
    scanf("%d", &newItem->quantity);
    // Add new item to bill
    bill[*count] = newItem;
    // Increment item count
    (*count)++;
}

// Function to print bill
void printBill(Item *bill[], int count) {
    printf("\n---BILL---\n");
    float total = 0;
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\t%d\n", bill[i]->name, bill[i]->price, bill[i]->quantity);
        total += bill[i]->price * bill[i]->quantity;
    }
    printf("TOTAL: %.2f\n", total);
}

int main() {
    // Initialize variables
    Item *bill[100];
    int count = 0;
    char option[10];
    // Start menu loop
    while (1) {
        printf("\n1. Add item\n2. Print bill\n3. Exit\nEnter option: ");
        scanf("%s", option);
        if (strcmp(option, "1") == 0) {
            addItem(bill, &count);
        } else if (strcmp(option, "2") == 0) {
            printBill(bill, count);
        } else if (strcmp(option, "3") == 0) {
            // Exit program
            printf("\nThank you for using our cafe billing system!");
            exit(0);
        } else {
            printf("\nInvalid option, please try again.");
        }
    }
}