//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

#define MAX_ITEMS 100
#define CUSTOMER_NAME_SIZE 50

// Define a structure for grocery items
struct Item {
    char name[50];
    float price;
    int quantity;
};

// Function to calculate total cost without discount
float calculateTotal(struct Item items[], int itemCount) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}

// Function to apply discount based on membership status
float applyDiscount(float total, int isMember, float discountPercentage) {
    if (isMember) {
        return total - (total * discountPercentage / 100);
    }
    return total;
}

// Function to print the receipt
void printReceipt(struct Item items[], int itemCount, float totalCost, float finalCost, const char *customerName) {
    printf("\n--- Receipt ---\n");
    printf("Customer Name: %s\n", customerName);
    printf("---------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s (x%d): $%.2f\n", items[i].name, items[i].quantity, items[i].price * items[i].quantity);
    }
    printf("---------------------\n");
    printf("Total Cost: $%.2f\n", totalCost);
    printf("Final Amount after Discount: $%.2f\n", finalCost);
    printf("---------------------\n");
}

int main() {
    struct Item items[MAX_ITEMS];
    char customerName[CUSTOMER_NAME_SIZE];
    int itemCount = 0;
    int isMember = 0;
    float discountPercentage = 10.0; // 10% discount for members

    printf("Welcome to the Grocery Store!\n");
    printf("Please enter your name: ");
    fgets(customerName, CUSTOMER_NAME_SIZE, stdin);
   
    printf("Are you a member? (1 for Yes, 0 for No): ");
    scanf("%d", &isMember);

    // Input items
    while (itemCount < MAX_ITEMS) {
        printf("Enter item name (or type 'done' to finish): ");
        scanf(" %[^\n]", items[itemCount].name);
        if (strcmp(items[itemCount].name, "done") == 0) {
            break;
        }

        printf("Enter price for %s: $", items[itemCount].name);
        scanf("%f", &items[itemCount].price);
        
        printf("Enter quantity for %s: ", items[itemCount].name);
        scanf("%d", &items[itemCount].quantity);
        
        itemCount++;
    }

    // Calculate total cost and apply discount if applicable
    float totalCost = calculateTotal(items, itemCount);
    float finalCost = applyDiscount(totalCost, isMember, discountPercentage);

    // Print the receipt
    printReceipt(items, itemCount, totalCost, finalCost, customerName);
    
    printf("Thank you for shopping with us!\n");
    return 0;
}