//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int itemCount;
} Invoice;

// Function Prototypes
void displayMenu(MenuItem menu[], int size);
void placeOrder(MenuItem menu[], int size, Invoice *invoice);
void generateBill(Invoice *invoice);
float calculateTotal(Invoice *invoice);

int main() {
    MenuItem menu[] = {
        {"Coffee", 2.50, 0},
        {"Tea", 2.00, 0},
        {"Sandwich", 5.00, 0},
        {"Burger", 6.50, 0},
        {"Pizza", 8.00, 0},
        {"Cake", 4.50, 0}
    };
    
    int menuSize = sizeof(menu) / sizeof(menu[0]);
    Invoice invoice;
    invoice.itemCount = 0;

    int choice;
    do {
        printf("\nWelcome to the Cafe Billing System!\n");
        printf("1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Generate Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayMenu(menu, menuSize);
            break;
        case 2:
            placeOrder(menu, menuSize, &invoice);
            break;
        case 3:
            generateBill(&invoice);
            break;
        case 4:
            printf("Thank you for visiting!\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu(MenuItem menu[], int size) {
    printf("\n---- Cafe Menu ----\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void placeOrder(MenuItem menu[], int size, Invoice *invoice) {
    int itemNumber, quantity;

    displayMenu(menu, size);

    printf("Enter the item number to order: ");
    scanf("%d", &itemNumber);

    if (itemNumber < 1 || itemNumber > size) {
        printf("Invalid item number.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (quantity <= 0) {
        printf("Quantity must be at least 1.\n");
        return;
    }

    int index = itemNumber - 1;
    invoice->items[invoice->itemCount] = menu[index];
    invoice->items[invoice->itemCount].quantity = quantity;
    invoice->itemCount++;

    printf("Added %d x %s to your order.\n", quantity, menu[index].name);
}

void generateBill(Invoice *invoice) {
    if (invoice->itemCount == 0) {
        printf("No items in the invoice.\n");
        return;
    }

    printf("\n---- Receipt ----\n");
    for (int i = 0; i < invoice->itemCount; i++) {
        float totalPrice = invoice->items[i].price * invoice->items[i].quantity;
        printf("%d x %s - $%.2f (Total: $%.2f)\n", invoice->items[i].quantity, invoice->items[i].name, invoice->items[i].price, totalPrice);
    }

    float totalBill = calculateTotal(invoice);
    printf("------------------\n");
    printf("Total Bill: $%.2f\n", totalBill);
}

float calculateTotal(Invoice *invoice) {
    float total = 0.0;
    for (int i = 0; i < invoice->itemCount; i++) {
        total += invoice->items[i].price * invoice->items[i].quantity;
    }
    return total;
}