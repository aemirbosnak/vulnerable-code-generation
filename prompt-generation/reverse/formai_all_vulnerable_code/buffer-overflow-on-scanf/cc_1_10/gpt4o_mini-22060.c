//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
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
} Order;

// Function prototypes.
void addItem(Order* order);
void generateBill(Order order);
void paranoidCheck(Order order);

int main() {
    Order currentOrder;
    currentOrder.itemCount = 0;
    
    int choice;

    printf("Welcome to the Paranoid Cafe Billing System.\n");
    printf("Your data is precious; please enter it carefully!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Menu Item\n");
        printf("2. Generate Bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&currentOrder);
                break;
            case 2:
                paranoidCheck(currentOrder);
                generateBill(currentOrder);
                break;
            case 3:
                printf("Exiting the system. Make sure your data is safe!\n");
                break;
            default:
                printf("Invalid choice. Please, be careful!\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

void addItem(Order* order) {
    if (order->itemCount >= MAX_ITEMS) {
        printf("Maximum item limit reached. No more items can be added. \n");
        return;
    }

    MenuItem newItem;
    
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    order->items[order->itemCount] = newItem;
    order->itemCount++;

    printf("Item added successfully. But are you sure it's correct? Double-checking won't hurt!\n");
}

void generateBill(Order order) {
    printf("\n--- Bill ---\n");
    float total = 0;

    for (int i = 0; i < order.itemCount; i++) {
        printf("%s - Price: %.2f, Quantity: %d\n", 
                order.items[i].name, 
                order.items[i].price,
                order.items[i].quantity);
        total += order.items[i].price * order.items[i].quantity;
    }

    printf("-----------------------\n");
    printf("Total: %.2f\n", total);
    printf("Are you confident about this total? Verify every detail...\n");
}

void paranoidCheck(Order order) {
    // A redundant check to ensure data integrity before generating a bill
    printf("Verifying order data...\n");
    for (int i = 0; i < order.itemCount; i++) {
        if (order.items[i].price < 0 || order.items[i].quantity < 0) {
            printf("Warning: Negative values detected in item %s! You must rectify this ASAP!\n",
                   order.items[i].name);
        }
    }
    printf("Data verification complete. Proceed with caution!\n");
}