//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct {
    char name[30];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int itemCount;
} Order;

void displayMenu() {
    printf("\n=== Cafe Menu ===\n");
    printf("1. Coffee - $2.00\n");
    printf("2. Tea - $1.50\n");
    printf("3. Sandwich - $3.50\n");
    printf("4. Salad - $4.00\n");
    printf("5. Pastry - $2.50\n");
    printf("==================\n");
}

void addItem(Order *order, char *itemName, float price, int quantity) {
    strcpy(order->items[order->itemCount].name, itemName);
    order->items[order->itemCount].price = price;
    order->items[order->itemCount].quantity = quantity;
    order->itemCount++;
}

float calculateTotal(Order *order) {
    float total = 0.0;
    for (int i = 0; i < order->itemCount; i++) {
        total += order->items[i].price * order->items[i].quantity;
    }
    return total;
}

void printReceipt(Order *order) {
    printf("\n=== Receipt ===\n");
    for (int i = 0; i < order->itemCount; i++) {
        printf("%s x%d - $%.2f\n", order->items[i].name, 
               order->items[i].quantity, 
               order->items[i].price * order->items[i].quantity);
    }
    printf("==================\n");
}

void applyDiscount(float *total) {
    if (*total > 20.0) {
        *total *= 0.9; // 10% discount
        printf("A 10%% discount has been applied!\n");
    }
}

int main() {
    Order order;
    order.itemCount = 0;
    int choice, quantity;

    displayMenu();

    do {
        printf("Select an item (1-5) or 0 to finish: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 5) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        
        if (choice == 0) {
            break; // Exit loop to finish the order
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        switch (choice) {
            case 1:
                addItem(&order, "Coffee", 2.00, quantity);
                break;
            case 2:
                addItem(&order, "Tea", 1.50, quantity);
                break;
            case 3:
                addItem(&order, "Sandwich", 3.50, quantity);
                break;
            case 4:
                addItem(&order, "Salad", 4.00, quantity);
                break;
            case 5:
                addItem(&order, "Pastry", 2.50, quantity);
                break;
            default:
                printf("Invalid item selected.\n");
        }
        
    } while (choice != 0);

    float total = calculateTotal(&order);
    applyDiscount(&total);
    printReceipt(&order);
    
    printf("Total Amount Due: $%.2f\n", total);
    return 0;
}