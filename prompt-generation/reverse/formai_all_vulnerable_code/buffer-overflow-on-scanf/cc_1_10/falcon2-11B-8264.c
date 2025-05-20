//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_CUSTOMERS 100

typedef struct {
    char name[50];
    float total;
} Customer;

typedef struct {
    char item[50];
    float price;
    int quantity;
} Item;

int main() {
    Item items[MAX_ITEMS];
    Customer customers[MAX_CUSTOMERS];

    int nItems = 0;
    int nCustomers = 0;

    printf("Welcome to the C Cafe Billing System!\n");

    while (1) {
        printf("1. Add items to the menu\n");
        printf("2. Add customers to the system\n");
        printf("3. Calculate bill for customers\n");
        printf("4. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < MAX_ITEMS; i++) {
                    printf("Item %d: ", i + 1);
                    fflush(stdout);
                    scanf("%s %f %d", items[i].item, &items[i].price, &items[i].quantity);
                }
                break;
            case 2:
                for (int i = 0; i < MAX_CUSTOMERS; i++) {
                    printf("Customer %d: ", i + 1);
                    fflush(stdout);
                    scanf("%s %f", customers[i].name, &customers[i].total);
                }
                break;
            case 3:
                for (int i = 0; i < nCustomers; i++) {
                    printf("Customer %d: ", i + 1);
                    fflush(stdout);
                    scanf("%s %f", customers[i].name, &customers[i].total);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}