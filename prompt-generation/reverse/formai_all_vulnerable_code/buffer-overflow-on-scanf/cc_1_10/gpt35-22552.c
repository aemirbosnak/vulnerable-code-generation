//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Define Struct for Menu Items
struct MenuItem {
    char name[50];
    float price;
};

// Define Struct for Order Items
struct OrderItem {
    char name[50];
    float price;
    int quantity;
};

// Define Function to Display the Menu
void displayMenu(struct MenuItem menu[], int size) {
    printf("MENU:\n");
    for(int i = 0; i < size; i++) {
        printf("%d. %s: $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Define Function to Place an Order
void placeOrder(struct MenuItem menu[], int size, struct OrderItem orders[], int *numOrders) {
    int choice;
    int quantity;
    
    displayMenu(menu, size);
    
    printf("Enter your choice (1-%d): ", size);
    scanf("%d", &choice);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    if(choice < 1 || choice > size) {
        printf("Invalid choice!\n");
        return;
    }
    
    orders[*numOrders].price = menu[choice-1].price;
    strcpy(orders[*numOrders].name, menu[choice-1].name);
    orders[*numOrders].quantity = quantity;
    
    *numOrders += 1;
    
    printf("Order placed successfully!\n");
}

// Define Function to View the Order
void viewOrder(struct OrderItem orders[], int numOrders) {
    float sum = 0;
    
    printf("YOUR ORDER:\n");
    for(int i = 0; i < numOrders; i++) {
        printf("%s x%d: $%.2f\n", orders[i].name, orders[i].quantity, orders[i].price * orders[i].quantity);
        sum += orders[i].price * orders[i].quantity;
    }
    
    printf("TOTAL: $%.2f\n", sum);
}

// Define the Main Function
int main() {
    // Declare and Initialize the Menu Items
    struct MenuItem menu[5] = {
        {"Coffee", 1.50},
        {"Tea", 1.00},
        {"Sandwich", 3.00},
        {"Burger", 4.50},
        {"Fries", 2.00}
    };
    
    // Declare the Order Items and NumOrders
    struct OrderItem orders[50];
    int numOrders = 0;
    
    // Declare and Initialize the User's Choice
    char choice;
    
    do {
        printf("WELCOME TO THE CAFE BILLING SYSTEM!\n\n");
        printf("1. PLACE ORDER\n");
        printf("2. VIEW ORDER\n");
        printf("3. EXIT\n\n");
        printf("Enter your choice (1-3): ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                placeOrder(menu, 5, orders, &numOrders);
                break;
            case '2':
                viewOrder(orders, numOrders);
                break;
            case '3':
                printf("\nThank you for using the Cafe Billing System!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
        
        printf("\n");
    } while(choice != '3');
    
    return 0;
}