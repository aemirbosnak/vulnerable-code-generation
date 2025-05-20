//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int id;
};

struct menu {
    char name[50];
    float price;
    float tax;
    int quantity;
};

struct menu items[] = {
    {"Tea", 30.0, 0.0, 1},
    {"Coffee", 40.0, 0.0, 1},
    {"Sandwich", 50.0, 0.0, 1},
    {"Pasta", 60.0, 0.0, 1},
    {"Pizza", 70.0, 0.0, 1},
};

void displayMenu() {
    printf("Menu:\n");
    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
        printf("%s: %.2f\n", items[i].name, items[i].price);
    }
}

float calculateTotal(struct menu item) {
    return item.price * item.quantity + item.quantity * item.tax;
}

void printBill(struct customer customer, struct menu item) {
    float total = calculateTotal(item);
    printf("Customer: %s\n", customer.name);
    printf("Item: %s\n", item.name);
    printf("Price: %.2f\n", item.price);
    printf("Quantity: %d\n", item.quantity);
    printf("Tax: %.2f\n", item.tax);
    printf("Total: %.2f\n", total);
}

int main() {
    struct customer customer;
    struct menu item;
    char choice;

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please enter your name:\n");
    scanf("%s", customer.name);
    printf("Your customer ID is %d\n", (int)strlen(customer.name));

    displayMenu();

    printf("Please enter your choice (T/C/S): ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'T':
            printf("Tea: %.2f\n", items[0].price);
            printf("Do you want to order Tea? (Y/N): ");
            scanf(" %c", &choice);
            if (choice == 'Y') {
                item = items[0];
                printf("Quantity: ");
                scanf("%d", &item.quantity);
                printf("Total: %.2f\n", calculateTotal(item));
                printf("Press any key to continue...\n");
                getchar();
                printBill(customer, item);
            }
            break;
        case 'C':
            printf("Coffee: %.2f\n", items[1].price);
            printf("Do you want to order Coffee? (Y/N): ");
            scanf(" %c", &choice);
            if (choice == 'Y') {
                item = items[1];
                printf("Quantity: ");
                scanf("%d", &item.quantity);
                printf("Total: %.2f\n", calculateTotal(item));
                printf("Press any key to continue...\n");
                getchar();
                printBill(customer, item);
            }
            break;
        case 'S':
            printf("Sandwich: %.2f\n", items[2].price);
            printf("Do you want to order Sandwich? (Y/N): ");
            scanf(" %c", &choice);
            if (choice == 'Y') {
                item = items[2];
                printf("Quantity: ");
                scanf("%d", &item.quantity);
                printf("Total: %.2f\n", calculateTotal(item));
                printf("Press any key to continue...\n");
                getchar();
                printBill(customer, item);
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}