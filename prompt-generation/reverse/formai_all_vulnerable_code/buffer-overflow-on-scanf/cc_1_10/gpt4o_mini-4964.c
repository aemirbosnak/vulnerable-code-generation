//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_ITEMS 10

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    char customerName[50];
    MenuItem itemsOrdered[MAX_ITEMS];
    int itemsCount;
    float totalBill;
} CustomerBill;

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\n--- Cafe Menu ---\n");
    for(int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

void takeOrder(CustomerBill *bill, MenuItem menu[], int itemCount) {
    printf("Enter customer name: ");
    scanf("%s", bill->customerName);
    bill->itemsCount = 0;
    bill->totalBill = 0;

    int choice;
    while(1) {
        displayMenu(menu, itemCount);
        printf("Select an item number to order (0 to finish): ");
        scanf("%d", &choice);

        if(choice == 0) {
            break;
        } else if(choice > 0 && choice <= itemCount) {
            bill->itemsOrdered[bill->itemsCount++] = menu[choice - 1];
            bill->totalBill += menu[choice - 1].price;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void printBill(const CustomerBill *bill) {
    printf("\n--- Bill for %s ---\n", bill->customerName);
    for(int i = 0; i < bill->itemsCount; i++) {
        printf("%s - $%.2f\n", bill->itemsOrdered[i].name, bill->itemsOrdered[i].price);
    }
    printf("Total Bill: $%.2f\n", bill->totalBill);
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        { "Coffee", 2.50 },
        { "Tea", 1.75 },
        { "Sandwich", 5.00 },
        { "Pasta", 7.50 },
        { "Cake", 3.25 },
        { "Water", 0.99 },
        { "Juice", 2.00 },
        { "Soda", 1.50 },
        { "Salad", 6.00 },
        { "Burger", 4.50 }
    };
    
    CustomerBill bills[MAX_CUSTOMERS];
    int customerCount = 0;

    while(customerCount < MAX_CUSTOMERS) {
        printf("\n--- Cafe Billing System ---\n");
        printf("1. Take Order\n");
        printf("2. Print Bills\n");
        printf("0. Exit\n");
        int option;
        printf("Select an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                takeOrder(&bills[customerCount], menu, MAX_ITEMS);
                customerCount++;
                break;

            case 2:
                for(int i = 0; i < customerCount; i++) {
                    printBill(&bills[i]);
                }
                break;

            case 0:
                printf("Exiting the Cafe Billing System.\n");
                return 0;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    printf("Maximum number of customers reached. Exiting.\n");
    return 0;
}