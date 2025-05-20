//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Structures
typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

typedef struct CafeBill {
    Item items[10];
    int numItems;
    float total;
} CafeBill;

// Function prototypes
void printMenu();
Item getItemDetails();
CafeBill createBill();
void printBill(CafeBill bill);

// Main function
int main() {
    // Print the menu
    printMenu();

    // Get the order
    CafeBill bill = createBill();

    // Print the bill
    printBill(bill);

    return 0;
}

// Function definitions
void printMenu() {
    printf("Welcome to the Cafe!\n");
    printf("Here is our menu:\n");
    printf("-------------------------\n");
    printf("Item\t\tPrice\n");
    printf("-------------------------\n");
    printf("Coffee\t\t$2.50\n");
    printf("Tea\t\t$2.00\n");
    printf("Cake\t\t$5.00\n");
    printf("Muffin\t\t$3.00\n");
    printf("-------------------------\n");
}

Item getItemDetails() {
    Item item;
    printf("Enter the name of the item: ");
    scanf("%s", item.name);
    printf("Enter the price of the item: ");
    scanf("%f", &item.price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &item.quantity);
    return item;
}

CafeBill createBill() {
    CafeBill bill;
    bill.numItems = 0;
    bill.total = 0.0;

    int choice;
    do {
        printf("Enter 1 to add an item, 2 to print the bill, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bill.items[bill.numItems] = getItemDetails();
                bill.numItems++;
                bill.total += bill.items[bill.numItems - 1].price * bill.items[bill.numItems - 1].quantity;
                break;
            case 2:
                printBill(bill);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return bill;
}

void printBill(CafeBill bill) {
    printf("Cafe Bill\n");
    printf("-------------------------\n");
    printf("Item\t\tPrice\t\tQuantity\t\tTotal\n");
    printf("-------------------------\n");
    for (int i = 0; i < bill.numItems; i++) {
        printf("%s\t\t$%.2f\t\t%d\t\t$%.2f\n", bill.items[i].name, bill.items[i].price, bill.items[i].quantity, bill.items[i].price * bill.items[i].quantity);
    }
    printf("-------------------------\n");
    printf("Total:\t\t\t\t\t$%.2f\n", bill.total);
}