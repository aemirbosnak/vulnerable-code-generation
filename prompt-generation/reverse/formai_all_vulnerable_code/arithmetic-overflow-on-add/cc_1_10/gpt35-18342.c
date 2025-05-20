//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int quantity;
    float price;
} Item;

Item menu[5] = { {"Latte", 0, 3.50}, {"Espresso", 0, 2.50}, {"Cappuccino", 0, 4.00}, {"Iced Coffee", 0, 3.00}, {"Tea", 0, 2.00} };

void printMenu() {
    printf("Menu:\n");
    printf("1. Latte\t\t$3.50\n");
    printf("2. Espresso\t\t$2.50\n");
    printf("3. Cappuccino\t\t$4.00\n");
    printf("4. Iced Coffee\t\t$3.00\n");
    printf("5. Tea\t\t\t$2.00\n");
}

void order() {
    int choice, quantity;
    float total = 0;

    printf("Enter your order (0 to exit):\n");
    do {
        printf("Item no.:\t");
        scanf("%d", &choice);
        if (choice != 0) {
            printf("Quantity:\t");
            scanf("%d", &quantity);

            menu[choice-1].quantity += quantity;
            total += menu[choice-1].price * quantity;
        }
    } while (choice != 0);

    printf("Total bill: $%.2f\n", total);
}

void printReceipt() {
    float total = 0;

    printf("Receipt:\n");
    for (int i = 0; i < 5; i++) {
        if (menu[i].quantity > 0) {
            printf("%s:\t\t%d x $%.2f = $%.2f\n", menu[i].name, menu[i].quantity, menu[i].price, menu[i].quantity * menu[i].price);
            total += menu[i].quantity * menu[i].price;
            menu[i].quantity = 0;
        }
    }
    
    printf("Total bill: $%.2f\n", total);
}

int main() {
    int choice;

    do {
        printf("\nWelcome to C Cafe!\n");
        printf("1. Order\n");
        printf("2. Print Receipt\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printMenu();
                order();
                break;
            case 2:
                printReceipt();
                break;
            case 3:
                printf("Thank you for visiting C Cafe!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}