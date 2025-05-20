//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 30

// Structure to hold item details
typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} MenuItem;

// Function prototypes
void displayMenu(MenuItem menu[], int item_count);
void takeOrder(MenuItem menu[], int item_count);
float calculateTotal(MenuItem menu[], int item_count, int order[], int order_qty[]);
void generateBill(MenuItem menu[], int item_count, int order[], int order_qty[], float total);

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Espresso", 2.5},
        {"Latte", 3.0},
        {"Cappuccino", 3.5},
        {"Sandwich", 5.0},
        {"Cake", 2.0}
    };

    int item_count = 5;

    printf("Welcome to the Cafe Billing System!\n");
    int choice;
    do {
        printf("\n1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(menu, item_count);
                break;
            case 2:
                takeOrder(menu, item_count);
                break;
            case 3:
                printf("Thank you for visiting!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Display the available menu
void displayMenu(MenuItem menu[], int item_count) {
    printf("\nMenu:\n");
    for (int i = 0; i < item_count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Take the customer's order
void takeOrder(MenuItem menu[], int item_count) {
    int order[MAX_ITEMS] = {0};
    int order_qty[MAX_ITEMS] = {0};
    int num_items = 0;

    while (1) {
        int item_number, quantity;
        printf("\nEnter the item number to order (or 0 to finish): ");
        scanf("%d", &item_number);
        
        if (item_number == 0)
            break;
        
        if (item_number < 1 || item_number > item_count) {
            printf("Invalid item number! Please try again.\n");
            continue;
        }
        
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        order[item_number - 1] += 1;
        order_qty[item_number - 1] = quantity;
        num_items++;
    }

    float total = calculateTotal(menu, item_count, order, order_qty);
    generateBill(menu, item_count, order, order_qty, total);
}

// Calculate the total bill
float calculateTotal(MenuItem menu[], int item_count, int order[], int order_qty[]) {
    float total = 0.0;
    
    for (int i = 0; i < item_count; i++) {
        if (order_qty[i] > 0) {
            total += menu[i].price * order_qty[i];
        }
    }
    
    return total;
}

// Generate the bill
void generateBill(MenuItem menu[], int item_count, int order[], int order_qty[], float total) {
    printf("\n--- Bill Summary ---\n");

    for (int i = 0; i < item_count; i++) {
        if (order_qty[i] > 0) {
            printf("%s x%d - $%.2f\n", menu[i].name, order_qty[i], menu[i].price * order_qty[i]);
        }
    }

    printf("Total Amount: $%.2f\n", total);

    // Payment Section
    float paid_amount;
    printf("Enter amount paid: $");
    scanf("%f", &paid_amount);
    
    if(paid_amount >= total) {
        printf("Change to return: $%.2f\n", paid_amount - total);
        printf("Thank you for your order!\n");
    } else {
        printf("Insufficient amount! Please pay the full amount.\n");
    }
}