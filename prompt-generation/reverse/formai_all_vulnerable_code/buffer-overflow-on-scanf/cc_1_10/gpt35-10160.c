//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define item structure
struct item {
    char name[20];
    int quantity;
    float price;
};

// Global variables
float total_amount = 0;
int num_of_items = 0;
struct item items[20];

int main() {
    int choice = 0;
    do {
        printf("Welcome to C Cafe!\n");
        printf("1. Add item\n");
        printf("2. View bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add item
                printf("Enter item name: ");
                scanf("%s", items[num_of_items].name);
                printf("Enter quantity: ");
                scanf("%d", &items[num_of_items].quantity);
                printf("Enter price: ");
                scanf("%f", &items[num_of_items].price);
                total_amount += items[num_of_items].quantity * items[num_of_items].price;
                num_of_items++;
                break;
            case 2:
                // View bill
                printf("Item Name\tQuantity\tPrice\n");
                for (int i = 0; i < num_of_items; i++) {
                    printf("%s\t\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
                }
                printf("Total amount: %.2f\n", total_amount);
                break;
            case 3:
                printf("Thank you for visiting C Cafe!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}