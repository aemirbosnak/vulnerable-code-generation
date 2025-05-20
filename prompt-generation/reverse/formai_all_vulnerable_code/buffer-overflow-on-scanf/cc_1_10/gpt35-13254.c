//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// define menu items with their prices
const float COFFEE_PRICE = 1.50;
const float TEA_PRICE = 1.00;
const float CROISSANT_PRICE = 2.00;
const float SANDWICH_PRICE = 4.00;
const float CAKE_PRICE = 3.50;

// function to display menu and take order
void takeOrder(float *subtotal, float *tax, float *total) {
    int choice, quantity;
    printf("Welcome to Brave Cafe!\n");
    printf("MENU:\n");
    printf("1. Coffee - $%.2f\n", COFFEE_PRICE);
    printf("2. Tea - $%.2f\n", TEA_PRICE);
    printf("3. Croissant - $%.2f\n", CROISSANT_PRICE);
    printf("4. Sandwich - $%.2f\n", SANDWICH_PRICE);
    printf("5. Cake - $%.2f\n", CAKE_PRICE);
    printf("Please enter your order (1-5): ");
    scanf("%d", &choice);
    printf("Please enter quantity: ");
    scanf("%d", &quantity);
    
    // calculate subtotal and update total and tax
    switch(choice) {
        case 1:
            *subtotal += COFFEE_PRICE * quantity;
            break;
        case 2:
            *subtotal += TEA_PRICE * quantity;
            break;
        case 3:
            *subtotal += CROISSANT_PRICE * quantity;
            break;
        case 4:
            *subtotal += SANDWICH_PRICE * quantity;
            break;
        case 5:
            *subtotal += CAKE_PRICE * quantity;
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }
    *tax = *subtotal * 0.07; // 7% tax
    *total = *subtotal + *tax;
    printf("Order added: %d x Item %d\n", quantity, choice);
}

// main function
int main() {
    float subtotal = 0, tax = 0, total = 0;
    int option;
    do {
        printf("\nSelect an option:\n");
        printf("1. Take order\n");
        printf("2. Display total\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                takeOrder(&subtotal, &tax, &total);
                break;
            case 2:
                printf("\nSUBTOTAL: $%.2f\n", subtotal);
                printf("TAX: $%.2f\n", tax);
                printf("TOTAL: $%.2f\n", total);
                break;
            case 3:
                printf("\nThank you for visiting Brave Cafe!\n");
                exit(0);
                break;
            default:
                printf("Invalid option.\n");
        }
    } while(1);
    return 0;
}